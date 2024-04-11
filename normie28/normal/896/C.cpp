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
stringstream sio;
ll seed,vmax,n,m,i,j,k,t,t1,u,v,a,b,l,r;
ll arr[100001];
 
struct cmp1{int operator()(piii(ll) a, piii(ll) b) const {
	return (a.se.se<b.se.se);
}};
struct cmp2{int operator()(piii(ll) a, piii(ll) b) const {
	if (a.fi-b.fi) return (a.fi<b.fi);
	return (a.se.se<b.se.se);
}};
 
 
set<piii(ll),cmp1> se;
set<piii(ll),cmp2> se2;
vector<piii(ll)> toadd;
 
ll rnd()
{
    ll ret = seed;
    seed = (seed * 7 + 13) % 1000000007;
    return ret;
}
void gen(stringstream& sio)
{
	for (ll i=1;i<=n;i++)
	{
    sio<<((rnd() % vmax) + 1)<<' ';
	}
	for (ll i=1;i<=m;i++)
{
    ll op = ((rnd() % 4) + 1);
    ll l = ((rnd() % n) + 1);
    ll r = ((rnd() % n) + 1);
    if (l > r)
         swap(l, r);
 
	sio<<op<<' '<<l<<' '<<r<<' ';
    if (op == 3)
       sio<< ((rnd() % (r - l + 1)) + 1)<<' ';
    else
        sio<<( (rnd() % vmax) + 1)<<' ';
 
    if (op == 4)
        sio<< ((rnd() % vmax) + 1)<<' ';
}
}
ll bow(ll a, ll x, ll p)
{
	if (!x) return 1;
	ll res=bow(a,x/2,p);
	res*=res;
	res%=p;
	if (x%2) res*=a;
	return res%p;
}
void solve(stringstream& sio)
{
//	cout<<sio.str()<<endl;
	for (i=1;i<=n;i++)
	{
		sio>>arr[i];
	}
	j=1;
	for (i=1;i<=n;i++) if ((i>1)and(arr[i]-arr[i-1]))
	{
		se.insert({arr[j],{j,i-1}});
		j=i;
	}
	{
		se.insert({arr[j],{j,i-1}});
		j=i;
	}
		
	//	cout<<"---set contents---\n";
//	for (auto g : se) cout<<g.fi<<' '<<g.se.fi<<' '<<g.se.se<<endl;
		//cout<<"---end set contents---\n";
	for (i=1;i<=m;i++)
	{
		sio>>t;
		toadd.clear();
		se2.clear();
		if (t==1)
		{
			sio>>l>>r>>a;
			auto it=se.lower_bound({0,{l,l}});
			while(true)
			{
				toadd.push_back({it->fi+a,{max(it->se.fi,l),min(it->se.se,r)}});
				if (it->se.fi<l) toadd.push_back({it->fi,{it->se.fi,l-1}});
				if (it->se.se>r) toadd.push_back({it->fi,{r+1,it->se.se}});
				if (it->se.se>=r) 
				{
					se.erase(it);
					break;
				}
				it=se.erase(it);
			}
			for (auto g : toadd) se.insert(g);
		}
		else if (t==2)
		{
			sio>>l>>r>>a;
			toadd.push_back({a,{l,r}});
			auto it=se.lower_bound({0,{l,l}});
			while(true)
			{
				if (it->se.fi<l) toadd.push_back({it->fi,{it->se.fi,l-1}});
				if (it->se.se>r) toadd.push_back({it->fi,{r+1,it->se.se}});
				if (it->se.se>=r) 
				{
					se.erase(it);
					break;
				}
				it=se.erase(it);
			}
			for (auto g : toadd) se.insert(g);
		}
		else if (t==3)
		{
			sio>>l>>r>>a;
			auto it=se.lower_bound({0,{l,l}});
			while(true)
			{
				se2.insert({it->fi,{max(it->se.fi,l),min(it->se.se,r)}});
				if (it->se.se>=r) break;
				it++;
			}
			u=0;
			for (auto g : se2)
			{
				u+=g.se.se-g.se.fi+1;
				if (u>=a) 
				{
					cout<<g.fi<<endl;
					break;
				}
			}
		}
		else if (t==4)
		{
			sio>>l>>r>>a>>b;
			auto it=se.lower_bound({0,{l,l}});
			while(true)
			{
				toadd.push_back({it->fi,{max(it->se.fi,l),min(it->se.se,r)}});
				if (it->se.se>=r) break;
				it++;
			}
			u=0;
			for (auto g : toadd)
			{
				u+=bow(g.fi%b,a,b)*(g.se.se-g.se.fi+1);
				u%=b;
			}
			cout<<u<<endl;
		}
		
	//	cout<<"---set contents---\n";
	//for (auto g : se) cout<<g.fi<<' '<<g.se.fi<<' '<<g.se.se<<endl;
		//cout<<"---end set contents---\n";
	}
}
int main()
{
	fio;
	cin>>n>>m>>seed>>vmax;
	gen(sio);
  	solve(sio);
}