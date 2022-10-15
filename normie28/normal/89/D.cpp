
// Problem : D. Space mines
// Contest : Codeforces - Codeforces Beta Round #74 (Div. 1 Only)
// URL : https://codeforces.com/problemset/problem/89/D
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
struct sphere
{
	ll ox,oy,oz,r;
	sphere(ll _ox, ll _oy, ll _oz, ll _r)
	{
		ox=_ox;
		oy=_oy;
		oz=_oz;
		r=_r;
	}
};
vector<sphere> balls;
ll ax,ay,az,vx,vy,vz;
ld res=1e18;
ll n,m,i,j,k,t,t1,u,v,a,b,c,d,x,y,z;
ld eq(ld a, ld b, ld c)
{
	if (b*b-4*a*c<0) return 1e18;
	ld d=sqrt(b*b-4*a*c);
	ld x1=(-b-d)/2/a;
	ld x2=(-b+d)/2/a;
	if ((x1<0)and(x2<0)) return 1e18;
	else if (x1<0) return x2;
	else if (x2<0) return x1;
	else return min(x1,x2);
}
void solve(sphere cur)
{
	ld bruh=eq(
	vx*vx+vy*vy+vz*vz,
	(
	vx*ax-cur.ox*vx+
	vy*ay-cur.oy*vy+
	vz*az-cur.oz*vz
	)
	*2,
	(
	-cur.ox*ax-cur.oy*ay-cur.oz*az
	)*2-cur.r*cur.r
	+ax*ax+ay*ay+az*az
	+cur.ox*cur.ox
	+cur.oy*cur.oy
	+cur.oz*cur.oz
	);
	res=min(res,bruh);
}
int main()
{
	fio;
	cin>>ax>>ay>>az>>vx>>vy>>vz>>u;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>x>>y>>z>>v>>m;
		balls.emplace_back(x,y,z,u+v);
		for (j=1;j<=m;j++)
		{
			cin>>a>>b>>c;
			balls.emplace_back(a+x,b+y,c+z,u);
		}
	}
	for (auto g : balls) solve(g);
	if (res==1e18) cout<<-1;
	else cout<<fixed<<setprecision(9)<<res;
}