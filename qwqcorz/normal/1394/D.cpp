#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
const ll inf=1e12;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

ll dp[N][2];
int a[N],b[N];
vector<int>e[N];
void dfs(int now,int father)
{
	dp[now][0]=dp[now][1]=inf;
	ll sum=0;
	vector<ll>d;
	for (int to:e[now])
	{
		if (to==father) continue;
		dfs(to,now);
		sum+=dp[to][0];
		d.push_back(dp[to][1]-dp[to][0]);
	}
	sort(d.begin(),d.end());
	for (int i=0;i<=(int)d.size();i++)
	{
		dp[now][0]=min(dp[now][0],sum+1LL*a[now]*max(i+!!father,(int)d.size()-i));
		dp[now][1]=min(dp[now][1],sum+1LL*a[now]*max(i,(int)d.size()-i+!!father));
		if (i==(int)d.size()) continue;
		sum+=d[i];
	}
	if (father&&b[now]>b[father]) dp[now][0]=inf;
	if (father&&b[now]<b[father]) dp[now][1]=inf;
}

signed main()
{
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) b[i]=read(); 
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	print(dp[1][1]);
	
	return 0;
}