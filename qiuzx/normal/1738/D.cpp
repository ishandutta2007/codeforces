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
#define N 100010
using namespace std;
ll n,deg[N],b[N],dep[N];
vector<ll> vt[N],deps[N];
bool cmp(ll x,ll y)
{
	return vt[x].size()<vt[y].size();
}
int main(){
	ll T,i,j;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		deps[0].clear();
		for(i=1;i<=n;i++)
		{
			vt[i].clear();
			deps[i].clear();
			deg[i]=0;
		}
		ll k=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&b[i]);
			if(b[i]>i)
			{
				k=i;
			}
			if(b[i]>0&&b[i]<=n)
			{
				vt[b[i]].push_back(i);
				deg[i]++;
			}
		}
		vector<ll> seq;
		queue<ll> q;
		for(i=1;i<=n;i++)
		{
			if(deg[i]==0)
			{
				dep[i]=0;
				q.push(i);
			}
		}
		while(!q.empty())
		{
			ll x=q.front();
			q.pop();
			for(i=0;i<vt[x].size();i++)
			{
				dep[vt[x][i]]=dep[x]+1;
				q.push(vt[x][i]);
			}
		}
		for(i=1;i<=n;i++)
		{
			deps[dep[i]].push_back(i);
		}
		for(i=0;i<=n;i++)
		{
			sort(deps[i].begin(),deps[i].end(),cmp);
			for(j=0;j<deps[i].size();j++)
			{
				seq.push_back(deps[i][j]);
			}
		}
		printf("%lld\n",k);
		for(i=0;i<seq.size();i++)
		{
			printf("%lld ",seq[i]);
		}
		puts("");
	}
	return 0;
}