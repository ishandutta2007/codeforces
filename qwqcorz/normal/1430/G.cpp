#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=18;
const int S=1<<N;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

#define have(x,y) ((x&y)==y)
int c[N][S],s[N],dp[S],from[S],a[N];

signed main()
{
	int n=read(),m=read(),up=(1<<n)-1;
	for (int i=1;i<=m;i++)
	{
		int u=read()-1,v=read()-1,w=read();
		c[u][1<<v]=w;
		s[v]|=1<<u;
	}
	for (int i=0;i<n;i++)
	for (int j=1;j<=up;j++)
	c[i][j]=c[i][j&-j]+c[i][j&(j-1)];
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	for (int i=0;i<up;i++)
	{
		int S=0,val=0;
		for (int j=0;j<n;j++)
		if (i>>j&1) val+=c[j][i^up];
			   else S|=have(i,s[j])<<j;
		for (int k=S;k;k=(k-1)&S)
		if (dp[i^k]>dp[i]+val)
		{
			dp[i^k]=dp[i]+val;
			from[i^k]=i;
		}
	}
	int S=up;
	while (S)
	{
		for (int i=0;i<n;i++) a[i]+=S>>i&1;
		S=from[S];
	}
	for (int i=0;i<n;i++) print(a[i]," \n"[i+1==n]);
	
	return 0;
}