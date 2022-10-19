//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 10000000000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 200010
using namespace std;
ll n,m,k,cost[N],dist[N];
map<pair<ll,ll>,ll> mp;
vector<ll> id[N];
vector<pair<ll,ll> > vt[N];
void update(ll x)
{
	ll i,mx=-LINF;
	vector<ll> v,ret;
	sort(id[x].begin(),id[x].end());
	for(i=0;i<id[x].size();i++)
	{
		v.push_back(dist[mp[make_pair(x,id[x][i])]]);
	}
	for(i=0;i<v.size();i++)
	{
		ret.push_back(mx-cost[x]*id[x][i]);
		mx=max(mx,v[i]+cost[x]*id[x][i]);
	}
	mx=-LINF;
	for(i=v.size()-1;i>=0;i--)
	{
		ret[i]=max(ret[i],mx+cost[x]*id[x][i]);
		mx=max(mx,v[i]-cost[x]*id[x][i]);
	}
	for(i=0;i<v.size();i++)
	{
		dist[mp[make_pair(x,id[x][i])]]=max(dist[mp[make_pair(x,id[x][i])]],ret[i]);
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll T,i,j,l,l1,r1,l2,r2,cnt,v;
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>k;
		for(i=0;i<n;i++)
		{
			id[i].clear();
			cin>>cost[i];
		}
		mp.clear();
		id[0].push_back(0);
		mp[make_pair(0,0)]=0;
		id[n-1].push_back(m-1);
		mp[make_pair(n-1,m-1)]=1;
		cnt=2;
		for(i=0;i<k;i++)
		{
			cin>>l1>>r1>>l2>>r2>>v;
			l1--,r1--,l2--,r2--;
			if(!mp.count(make_pair(l1,r1)))
			{
				id[l1].push_back(r1);
				mp[make_pair(l1,r1)]=cnt++;
			}
			if(!mp.count(make_pair(l2,r2)))
			{
				id[l2].push_back(r2);
				mp[make_pair(l2,r2)]=cnt++;
			}
			vt[mp[make_pair(l1,r1)]].push_back(make_pair(mp[make_pair(l2,r2)],v));
		}
		for(i=0;i<cnt;i++)
		{
			dist[i]=-LINF;
		}
		dist[0]=0;
		for(i=0;i<n;i++)
		{
			update(i);
			for(j=0;j<id[i].size();j++)
			{
				v=mp[make_pair(i,id[i][j])];
				for(l=0;l<vt[v].size();l++)
				{
					dist[vt[v][l].F]=max(dist[vt[v][l].F],dist[v]+vt[v][l].S);
				}
			}
		}
		if(dist[1]>-INF)
		{
			cout<<-dist[1]<<endl;
		}
		else
		{
			cout<<"NO ESCAPE"<<endl;
		}
		for(i=0;i<cnt;i++)
		{
			vt[i].clear();
		}
	}
	return 0;
}