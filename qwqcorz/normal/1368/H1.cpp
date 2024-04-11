#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int dp[N][2];
char l[N],r[N],u[N],d[N];
int solve(int n,int m,char *l,char *r,char *u,char *d)
{
	dp[0][0]=dp[0][1]=0;
	for (int i=1;i<=n;i++) dp[0][l[i]=='B']++;
	for (int i=1;i<=m;i++)
	{
		dp[i][0]=min(dp[i-1][0],dp[i-1][1]+n)+(u[i]!='B')+(d[i]!='B');
		dp[i][1]=min(dp[i-1][0]+n,dp[i-1][1])+(u[i]=='B')+(d[i]=='B');
	}
	for (int i=1;i<=n;i++) dp[m][r[i]=='B']++;
	return min(dp[m][0],dp[m][1]);
}

signed main()
{
	int n=read(),m=read(),Q=read();
	scanf("%s%s%s%s",l+1,r+1,u+1,d+1);
	print(min(solve(n,m,l,r,u,d),solve(m,n,u,d,l,r)));
	
	return 0;
}