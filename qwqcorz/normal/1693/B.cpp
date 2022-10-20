#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

vector<int>e[N];
int dp[N];
ll val[N],l[N],r[N];
void dfs(int now)
{
	ll sum=0;
	dp[now]=0;
	for (int to:e[now])
	{
		dfs(to);
		dp[now]+=dp[to];
		sum+=val[to];
	}
	if (sum<l[now]) val[now]=r[now];
	else val[now]=min(sum,r[now]),dp[now]++;
}
void work()
{
	int n=read();
	for (int i=2;i<=n;i++) e[read()].push_back(i);
	for (int i=1;i<=n;i++) l[i]=read(),r[i]=read();
	dfs(1);
	print(n-dp[1]);
	for (int i=1;i<=n;i++) e[i].clear();
}

signed main()
{
	int T=read();
	while (T--) work();
	
	return 0;
}