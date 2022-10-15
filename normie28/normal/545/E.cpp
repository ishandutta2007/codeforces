#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "exp.inp"
#define FILE_OUT "exp.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(111539768))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define S second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
typedef long long ll;
const ll inf=1e16,N=3e5+200;
ll x,y,we,a[N],b[N],c[N],u,dist[N],mark[N],ans=0,n,ma,m[N],cmp[N];
vector <ll> g[N],w[N],cn[N];
set < pair<ll,ll> > s;
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> ma;
	for(int i=1; i<=ma; i++)
	{
		cin >> a[i] >> b[i] >> c[i];
		x=a[i],y=b[i],we=c[i];
		g[x].push_back(y);
		g[y].push_back(x);	
		w[x].push_back(we);
		w[y].push_back(we);
		cn[x].push_back(i);
		cn[y].push_back(i);
	}
	cin >> u;
	fill(dist,dist+N,inf);
	fill(cmp,cmp+N,0);
	c[0]=inf+200;
	dist[u]=0;
	for(int i=1; i<=n; i++)	s.insert({dist[i],i});
	while((ll)s.size())
	{
		auto it=s.begin();
		x=it->S;
		s.erase(it);
		mark[x]=1;
		for(int i=0; i<g[x].size(); i++)
		{
			y=g[x][i];
			if(!mark[y])
			{
				if(dist[y]>dist[x]+w[x][i] ||(dist[y]==dist[x]+w[x][i] && c[cmp[y]]>=w[x][i]))
				{
					m[cmp[y]]=0;
					cmp[y]=cn[x][i];
					m[cmp[y]]=1;
					s.erase({dist[y],y});
					dist[y]=dist[x]+w[x][i];
					s.insert({dist[y],y});
				}
			}
		}
	}
	for(int i=1; i<=ma; i++)
	{
		if(m[i]==1)
			ans+=c[i];
	}
	cout << ans << endl;
	//for(int i=1; i<=n; i++)		
	//	cout << i << ' ' << dist[i] << endl;
	for(int i=1; i<=ma; i++)
        {
                if(m[i]==1)
                        cout << i << ' ';
        }
	return 0;
}