#include <bits/stdc++.h>
using namespace std;
int n,m;
char a[4][1000006];
int c[1000006],d[1000006];
int dp[1000006][2][2][2];
bool check(int x,int y,int z,int X,int Y,int Z)
{
	if (x^y^X^Y==0) return 0;
	if (y^z^Y^Z==0) return 0;
	return 1;
}
int step(int x,int y,int z,int X,int Y,int Z)
{
	return (x^X)+(y^Y)+(z^Z);
}
int main()
{
	cin >> n >> m;
	if (n>3&&m>3)
	{
		puts("-1");
		return 0;
	}
	if (n==1||m==1) 
	{
		puts("0");
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			cin >> a[i][j];
		}
	}
	if (n==2)
	{
		for (int i=1;i<=m;i++) c[i]=(a[1][i]-'0'+a[2][i]-'0')%2;
		for (int i=1;i<=m;i++) d[i]=c[i];
		int ans=0,res=0;
		for (int i=2;i<=m;i++) if ((d[i]+d[i-1])%2==0) d[i]=(d[i]+1)%2,ans++;
		for (int i=1;i<=m;i++) d[i]=c[i];
		d[1]=(d[1]+1)%2;
		for (int i=2;i<=m;i++) if ((d[i]+d[i-1])%2==0) d[i]=(d[i]+1)%2,res++;
		cout << min(ans,res+1);
	}
	else
	{
		int ans=1000000000;
		for (int i=1;i<=m;i++)
		{
			for (int x=0;x<=1;x++)
			{
				for (int y=0;y<=1;y++)
				{
					for (int z=0;z<=1;z++)
					{
						dp[i][x][y][z]=1000000000;
						for (int X=0;X<=1;X++)
						{
							for (int Y=0;Y<=1;Y++)
							{
								for (int Z=0;Z<=1;Z++)
								{
									if (check(x,y,z,X,Y,Z)==0) continue; 
									dp[i][x][y][z]=min(dp[i][x][y][z],dp[i-1][X][Y][Z]+step(a[1][i]-'0',a[2][i]-'0',a[3][i]-'0',x,y,z));
								}
							}
						}
						if (i==m) ans=min(ans,dp[i][x][y][z]);
					}
				}
			}
		}
		cout << ans;
	}
	
	return 0;
}