//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 10010
using namespace std;
ll n,k,m,a[N],len[N],dist[25][N],dp[(1<<20)+20];
bool seq[N];
vector<ll> v;
void getdist(ll x,ll id)
{
	memset(dist[id],63,sizeof(dist[id]));
	queue<ll> q;
	q.push(x);
	dist[id][x]=0;
	ll i;
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		for(i=0;i<m;i++)
		{
			if(x+len[i]<=n&&dist[id][x+len[i]]>dist[id][x]+1)
			{
				dist[id][x+len[i]]=dist[id][x]+1;
				q.push(x+len[i]);
			}
			if(x-len[i]>0&&dist[id][x-len[i]]>dist[id][x]+1)
			{
				dist[id][x-len[i]]=dist[id][x]+1;
				q.push(x-len[i]);
			}
		}
	}
	return;
}
int main(){
	ll i,j,k,x;
	scanf("%lld%lld%lld",&n,&k,&m);
	for(i=0;i<k;i++)
	{
		scanf("%lld",&x);
		a[x]=1;
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld",&len[i]);
	}
	for(i=0;i<=n;i++)
	{
		seq[i]=(a[i]!=a[i+1]);
		if(seq[i])
		{
			getdist(i,v.size());
			v.push_back(i);
		}
	}
	memset(dp,63,sizeof(dp));
	dp[(1<<v.size())-1]=0;
	for(i=(1<<v.size())-1;i>=0;i--)
	{
		for(j=0;j<v.size();j++)
		{
			if(i&(1<<j))
			{
				for(k=j+1;k<v.size();k++)
				{
					if(i&(1<<k))
					{
						dp[i^(1<<j)^(1<<k)]=min(dp[i^(1<<j)^(1<<k)],dp[i]+dist[j][v[k]]);
					}
				}
			}
		}
	}
	if(dp[0]>=INF)
	{
		dp[0]=-1;
	}
	printf("%lld\n",dp[0]);
	return 0;
}