// Problem : D. Graph and Queries
// Contest : Codeforces - Codeforces Round #673 (Div. 1)
// URL : https://codeforces.com/contest/1416/problem/D
// Memory Limit : 256 MB
// Time Limit : 1500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)
 
/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
struct cmp
{
	int operator() (pii a, pii b)
	{
		if (a.se-b.se!=0) return (a.se<b.se);
		return (a.fi<b.fi);
	}
};
vector<pii> events1;
vector<vector<int>> events2;
vector<int> buf;
struct dsu
{
	int n,par[200001],h[200001];
	vector<int> cont[200001];
	dsu (ll n)
	{
		for (ll i=1;i<=n;i++)
		{
			par[i]=i;
			cont[i].push_back(i);
		}
		this->n=n;
	}
	ll get_par(ll x)
	{
		if (par[par[x]]==par[x]) return par[x];
		else return par[x]=get_par(par[x]);
	}
	ll check_same(ll a, ll b)
	{
		return (get_par(a)==get_par(b));
	}
	void add_edge(ll a, ll b)
	{
		ll ha=get_par(a),hb=get_par(b);
		if (ha!=hb)
		{
		buf.clear();
		buf.push_back(2);
			if (cont[ha].size()<cont[hb].size())
			{
				par[ha]=hb;
				for (int g : cont[ha]) {cont[hb].push_back(g); buf.push_back(g);}
			}
			else
			if (cont[ha].size()>cont[hb].size())
			{
				par[hb]=ha;
				for (int g : cont[hb]) {cont[ha].push_back(g); buf.push_back(g);}
			}
			else
			{
				par[hb]=ha;
				for (int g : cont[hb]) {cont[ha].push_back(g); buf.push_back(g);}
			}
			events2.push_back(buf);
		}
	}
};
int n,m,k,val[200001],curb[200001],t,t1,i,j;
int eu[300001],ev[300001],deled[300001];
int u,v,a,b;
int fucc;
set<pii,cmp> buc[4000001]; 
dsu gr(200000);
int main()
{
//  ofile;
    fio;
    cin>>n>>m>>t;
    t1=n;
    for (i=1;i<=n;i++) cin>>val[i];
    
    for (i=1;i<=m;i++) cin>>eu[i]>>ev[i];
    for (i=1;i<=t;i++)
    {
    	cin>>u>>v;
    	events1.push_back({u,v});
    	if (u==2)
    	{
    		deled[v]=1;
    	}
    }
    for (i=1;i<=m;i++) if (!deled[i]) events1.push_back({2,i});
    for (i=events1.size()-1;i>=0;i--)
    {
    	if (events1[i].fi==2)
    	gr.add_edge(eu[events1[i].se],ev[events1[i].se]);
    	else events2.push_back({1,events1[i].se});
    }
    for (i=1;i<=n;i++) if (gr.par[i]==i)
    {
    	for (int g : gr.cont[i])
    	{
    		curb[g]=i;
    		buc[i].insert({g,val[g]});
    	}
    }
    for (i=events2.size()-1;i>=0;i--)
    {
    	if (events2[i][0]==1)
    	{
  //  		cout<<1<<' '<<events2[i][1]<<endl<<endl;
   // 		for (pii g : buc[curb[events2[i][1]]]) cout<<g.fi<<' '<<g.se<<' '<<endl;
   // 		cout<<endl;
    		auto it=buc[curb[events2[i][1]]].end();
    		it--;
    		cout<<(*it).se<<endl;
    		pii toer=(*it);
    		buc[curb[events2[i][1]]].erase(toer);
    		toer.se=0;
    		buc[curb[events2[i][1]]].insert(toer);
    		val[toer.fi]=toer.se;
    	}
    	else
    	{
    		t1++;
    //		cout<<2<<' ';
    		for (j=1;j<events2[i].size();j++)
    		{
    //			cout<<events2[i][j]<<' ';
    			fucc=curb[events2[i][j]];
    			buc[fucc].erase({events2[i][j],val[events2[i][j]]});
    			buc[t1].insert({events2[i][j],val[events2[i][j]]});
    			curb[events2[i][j]]=t1;
    		}
  //  		cout<<endl;
    	}
    }
}