
// Problem : G. Max and Min
// Contest : Codeforces - VK Cup 2015 - Finals, online mirror
// URL : https://codeforces.com/contest/566/problem/G
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
//x[i]*y[j]-x[j]*y[i]
//>0=>CCW
vector<pii(ll)> maxmv,minmv,conv;
ll n,m,i,j,k,t,t1,u,v,a,b,maxx,maxy;
int main()
{
	fio;
	cin>>n>>m>>a>>b;
	for (i=1;i<=n;i++)
	{
		cin>>u>>v;
		maxmv.push_back({u,v});
	}
	for (i=1;i<=m;i++)
	{
		cin>>u>>v;
		maxx=max(maxx,u);
		maxy=max(maxy,v);
		minmv.push_back({u,v});
	}
	minmv.push_back({maxx,0});
	minmv.push_back({0,maxy});
	sort(minmv.begin(),minmv.end(),[](pii(ll) a, pii(ll) b){
		if (a.fi*b.se-a.se*b.fi) return (a.fi*b.se-a.se*b.fi<0);
		return (a.fi*a.fi+a.se*a.se<b.fi*b.fi+b.se*b.se);
	});
	if ((minmv.size()>=2)and(minmv[0].fi*minmv[1].se==minmv[0].se*minmv[1].fi))
	minmv.erase(minmv.begin());
	for (i=0;i<m+2;i++)
	{
		while (conv.size()>=2)
		{
			u=conv[conv.size()-1].fi-conv[conv.size()-2].fi;
			v=conv[conv.size()-1].se-conv[conv.size()-2].se;
			a=minmv[i].fi-conv[conv.size()-2].fi;
			b=minmv[i].se-conv[conv.size()-2].se;
			if (u*b-a*v<0) break;
			else conv.pop_back();
		}
		conv.push_back(minmv[i]);
	}
	//	for (auto g : minmv) cout<<g.fi<<' '<<g.se<<endl;
	//	for (auto g : conv) cout<<g.fi<<' '<<g.se<<endl;
	for (i=0;i<n;i++)
	{
		auto it=upper_bound(conv.begin(),conv.end(),maxmv[i],[](pii(ll) a, pii(ll) b){
		if (a.fi*b.se-a.se*b.fi) return (a.fi*b.se-a.se*b.fi<0);
		return (a.fi*a.fi+a.se*a.se<b.fi*b.fi+b.se*b.se);
		});
		it--;
		auto it2=it; it2++;
		if (((it->fi)-maxmv[i].fi)*((it2->se)-maxmv[i].se)-
		((it->se)-maxmv[i].se)*((it2->fi)-maxmv[i].fi)<0) 
		{
		
		}
		else
		{
			cout<<"Max";
			return 0;
		}
	}
	cout<<"Min";
}