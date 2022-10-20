#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=105;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int s[N][N][N],dp[N][N];

signed main()
{
	int n=read(),m=read();
	for (int i=1;i<=n;i++)
	{
		int k=read();
		for (int j=1;j<=k;j++)
		{
			int l=read(),r=read();
			for (int t=l;t<=r;t++) s[t][l][r]++;
		}
	}
	for (int i=1;i<=m;i++)
	for (int l=m;l>=1;l--)
	for (int r=l;r<=m;r++)
	s[i][l][r]+=s[i][l+1][r]+s[i][l][r-1]-s[i][l+1][r-1];
	for (int l=m;l>=1;l--)
	for (int r=l;r<=m;r++)
	for (int k=l;k<=r;k++)
	dp[l][r]=max(dp[l][r],dp[l][k-1]+dp[k+1][r]+s[k][l][r]*s[k][l][r]);
	print(dp[1][m]);
	
	return 0;
}