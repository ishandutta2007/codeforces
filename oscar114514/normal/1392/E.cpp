#include<bits/stdc++.h>
using namespace std;
int T,n,m;
long long w;
long long C[33][33],fl[33][33],sum[33][33];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		C[i][1]=C[1][i]=1;
	for(int i=2;i<n;i++)
	{
		for(int j=2;j<n;j++)
		{
			C[i][j]=C[i-1][j]+C[i][j-1];
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(!fl[i][j])
			{
				swap(C[i][j],C[n-i+1][n-j]);
				fl[i][j]=fl[n-i+1][n-j]=1;
			}
		}
	}
	for(int i=1;i<=n;i++)C[1][i]=C[i][n]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=n;j>=1;j--)
		{
			C[i][j]+=C[i-1][j+1];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<C[i][j]<<' ';
		}
		cout<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=j;k<=n;k++)
				sum[i][j]+=C[i][k];
			for(int k=j+1;k<=n;k++)
				sum[i][j]+=C[k][n];
		}
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>w;
		int x=1,y=1;
		cout<<x<<' '<<y<<endl;
		while(x!=n||y!=n)
		{
			if(x!=n&&sum[x+1][y]<=w)
				x++;
			else
				y++;
			cout<<x<<' '<<y<<endl;
			w-=C[x][y];
		}
	}
	return 0;
}