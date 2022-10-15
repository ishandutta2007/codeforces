/*
	Normie's Template v2.0
*/
 
// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;
 
// ordered_set library.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>
 
// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;
 
//Pragmas (Comment out these three lines if you're submitting in szkopul.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
 
//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define endl "\n"
 
//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))
 
//min/max redefines, so i dont have to resolve annoying compile errors.
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320
 
//Pairs and 3-pairs.
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pii(element_type) pair<element_type,element_type>
#define piii(element_type) pair<element_type,pii(element_type)>
 
//Quick power of 2.
#define pow2(x) (ll(1)<<x)
 
//Short for-loops.
#define ff(i,__,___) for(int i=__;i<=___;i++)
#define rr(i,__,___) for(int i=__;i>=___;i--)
 
//Typedefs.
#define bi BigInt
typedef long long ll;
typedef long double ld;
typedef short sh;
//---------END-------//
ll par[200001];
ll par_e[200001];
ll rep[200001];
ll tl[200001];
ll tr[200001];
vector<ll> dsu_buc[200001];
ll dsu_top[200001];
vector<pii(ll)> gt[200001],down[200001];
ll eu[200001],ev[200001],ec[200001];
ll n,m,i,j,k,t,t1,u,v,a,b;
vector<ll> cur;
void dfs(ll x, ll y)
{
	rep[x]=y;
	t++;
	tl[x]=t;
	for (auto g : gt[x]) if (!rep[g.fi])
	{
		par[g.fi]=x;
		par_e[g.fi]=g.se;
		down[x].push_back(g);
		if (ec[g.se]>1) dfs(g.fi,g.fi);
		else dfs(g.fi,y);
	}
	tr[x]=t;
}
int main()
{
	fio;
	cin>>n>>m;
	for (i=1;i<n;i++)
	{
		cin>>eu[i]>>ev[i]>>ec[i];
		gt[eu[i]].emplace_back(ev[i],i);
		gt[ev[i]].emplace_back(eu[i],i);
	}
	dfs(1,1);
	for (i=1;i<=n;i++) {dsu_buc[rep[i]].push_back(i); dsu_top[i]=i;}
	for (i=1;i<n;i++) if (par[eu[i]]==ev[i]) swap(eu[i],ev[i]);
	for (i=1;i<=m;i++)
	{
		cin>>t1;
		if (t1==2)
		{
			cin>>j>>a;
			ec[j]=a;
			par_e[ev[j]]=j;
			if (ec[j]==1)
			{
				u=eu[j];
				v=ev[j];
				u=rep[u];
				v=rep[v];
				if (tl[dsu_top[u]]<tl[dsu_top[v]]) b=dsu_top[u]; else b=dsu_top[v];
				if (dsu_buc[u].size()<dsu_buc[v].size())
				{
					for (ll g : dsu_buc[u])
					{
						rep[g]=v;
						dsu_buc[v].push_back(g);
					}
					dsu_buc[u].clear();
					dsu_top[v]=b;
				}
				else
				{
					for (ll g : dsu_buc[v])
					{
						rep[g]=u;
						dsu_buc[u].push_back(g);
					}
					dsu_buc[v].clear();
					dsu_top[u]=b;
				}
			}
		}
		else
		{
			cin>>u>>v>>a;
			while(true)
			{
				if (a==0) break;
				u=dsu_top[rep[u]];
				if ((tl[u]<=tl[v])and(tr[v]<=tr[u])) break;
				else
				{
					a/=ec[par_e[u]];
			//		cout<<a<<endl;
					u=par[u];
				}
			}
			if (a==0) cout<<a<<endl;
			else
			{
		//		cout<<u<<' '<<v<<endl;
				cur.clear();
				while(true)
				{
					if (cur.size()>60) break;
		//			cout<<v<<" to "<<dsu_top[rep[v]]<<endl;
				v=dsu_top[rep[v]];
				if (u==v) break;
				else
				{
					cur.push_back(ec[par_e[v]]);
		//			cout<<v<<" to "<<par[v]<<endl;
					v=par[v];
				}
				}
				for (j=cur.size()-1;j>=0;j--) 
				{
		//			cout<<cur[j]<<' ';
				a/=cur[j]; 
		//			cout<<a<<endl;
				}
				cout<<a<<endl;
			}
		}
	}
}