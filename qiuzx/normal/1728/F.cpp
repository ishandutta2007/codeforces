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
#define N 2010
using namespace std;
ll n,v[N],sz1,sz2,w[N],cur[N],lst[N];
vector<ll> vt[N];
map<ll,ll> id;
void upd(ll x)
{
	while(id.count(cur[x]))
	{
		vt[x].push_back(id[cur[x]]);
		cur[x]+=w[x];
	}
	return;
}
void bfs(ll st)
{
	ll i;
	queue<ll> q;
	q.push(st);
	for(i=0;i<sz2;i++)
	{
		lst[i]=0;
	}
	lst[st]=-1;
	while(!q.empty())
	{
		ll x=q.front();
		q.pop();
		for(i=0;i<vt[x].size();i++)
		{
			if(lst[vt[x][i]]==0)
			{
				lst[vt[x][i]]=x;
				q.push(vt[x][i]);
			}
		}
	}
	return;
}
int main(){
	ll i,j;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&v[i]);
	}
	sort(v,v+n);
	sz1=0,sz2=n;
	w[0]=-INF;
	for(i=0;i<n;i++)
	{
		if(sz1==0||w[sz1-1]!=v[i])
		{
			w[sz1]=cur[sz1]=v[i];
			sz1++;
		}
		for(j=0;j<sz1;j++)
		{
			upd(j);
		}
		bfs(sz1-1);
		ll curans=INF;
		for(j=0;j<sz1;j++)
		{
			if(lst[j])
			{
				curans=min(curans,cur[j]);
			}
		}
		for(j=0;j<sz1;j++)
		{
			if(lst[j]&&cur[j]==curans)
			{
				break;
			}
		}
		id[curans]=sz2;
		vt[sz2++].push_back(j);
		while(lst[j]!=-1)
		{
			j=lst[j];
			vt[j][0]=lst[j];
			j=lst[j];
		}
	}
	ll res=0;
	for(map<ll,ll>::iterator it=id.begin();it!=id.end();it++)
	{
		res+=it->F;
	}
	printf("%lld\n",res);
	return 0;
}