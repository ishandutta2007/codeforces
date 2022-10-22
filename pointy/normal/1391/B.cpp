#include<bits/stdc++.h>
using namespace std;
char a[101][101];
int n,m;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
    	cin >>n >> m;
    	for (int i=1;i<=n;i++)
    	{
    		for (int j=1;j<=m;j++)
    		{
    			cin >> a[i][j]; 
			}
		} 
		int ans=0;
		for (int i=1;i<n;i++)
		{
			if (a[i][m]=='R') ans++;
		}
		for (int i=1;i<m;i++)
		{
			if (a[n][i]=='D') ans++;
		}
		cout <<ans << endl;
	}
    return 0;
}