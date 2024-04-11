#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

vector<int>e[N];
int is[N],dp[N];
int dfs(int now,int father,int deep)
{
	int ret=N*2;
	for (int to:e[now])
	{
		if (to==father) continue;
		ret=min(ret,dfs(to,now,deep+1));
		if (dp[now]<0||dp[to]<0) dp[now]=-1;
							else dp[now]+=dp[to];
	}
	if (is[now]) ret=deep;
	if (deep>ret/2) dp[now]=1;
			   else if (!dp[now]) dp[now]=-1;
	return ret;
}
void GreenDay()
{
	int n=read(),k=read();
	for (int i=1;i<=k;i++) is[read()]=1;
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0,1);
	puts(dp[1]<0?"YES":"NO");
	for (int i=1;i<=n;i++) e[i].clear(),is[i]=dp[i]=0;
}

signed main()
{
//	int T=1;
	int T=read();
	while (T--) GreenDay();
	
	return 0;
}