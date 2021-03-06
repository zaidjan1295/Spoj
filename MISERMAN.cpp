/*
 * MISERMAN.cpp
 *
 *  Created on: 17-Oct-2017
 *      Author: zaidjan1295
 */
/*
 * MISERMAC.CPP
 *
 *  Created on: 30-Sep-2017
 *      Author: zaidjan1295
 */

/*
 * BYTESM2.cpp
 *
 *  Created on: 26-Sep-2017
 *      Author: zaidjan1295
 */

#include <bits/stdc++.h>

using namespace std;

int rows,columns;

int miser(vector<vector<int> >& checkboard, int i,int j, vector<vector<int> >& dp_table)
{
	if(j<0 || j>=columns)
		return INT16_MAX;
	if(i>=rows)
		return 0;
	if(dp_table[i][j] == -1)
	{
		int sum1,sum2,sum3;
		sum1 = checkboard[i][j] + miser(checkboard, i+1,j-1,dp_table);
		sum2 = checkboard[i][j] + miser(checkboard, i+1,j,dp_table);
		sum3 = checkboard[i][j] + miser(checkboard, i+1,j+1,dp_table);
		dp_table[i][j] = min(sum1,min(sum2,sum3));
	}
	return dp_table[i][j];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    	cin>>rows>>columns;
    	vector<vector<int> > checkboard (rows, vector<int>(columns));
    	vector<vector<int> > dp_table (rows, vector<int>(columns,-1));
    	for(int i=0;i<rows;i++)
    		for(int j=0;j<columns;j++)
    			cin>>checkboard[i][j];
    	int result = INT32_MAX;
    	for(int j=0;j<columns;j++)
    		result = min(result,miser(checkboard,0,j,dp_table));
    	cout<<result<<endl;
    return 0;
}





