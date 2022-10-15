#ifndef CPL_TEMPLATE
#define CPL_TEMPLATE
/*
	Normie's Template v2.5
	Changes:
    Added warning against using pragmas on USACO.
*/
// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;
 
// ordered_set library.
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>
 
// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;

//Pragmas (Comment out these three lines if you're submitting in szkopul or USACO.)
// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast,unroll-loops,tree-vectorize")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
 
//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
 
//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0)
#define nfio cin.tie(0)
#define endl "\n"
 
//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))
 
//min/max redefines, so i dont have to resolve annoying compile errors.
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

// Fast min/max assigns to use with AVX.
// Requires g++ 9.2.0.
// template<typename T>
// __attribute__((always_inline)) void chkmin(T& a, const T& b) {
//     a=(a<b)?a:b;
// }

// template<typename T>
// __attribute__((always_inline)) void chkmax(T& a, const T& b) {
//     a=(a>b)?a:b;
// }
 
//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320
const long double PI=3.14159265358979;
 
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

// Binpow and stuff
ll BOW(ll a, ll x, ll p)
{
	if (!x) return 1;
	ll res=BOW(a,x/2,p);
	res*=res;
	res%=p;
	if (x%2) res*=a;
	return res%p;
}
ll INV(ll a, ll p)
{
	return BOW(a,p-2,p);
}
//------END-------//
#endif

struct upd {
	int tar;
	ld c0,c1,c2;
	upd(int _tar, ld _c0, ld _c1, ld _c2) {
		tar=_tar;
		c0=_c0;
		c1=_c1;
		c2=_c2;
	}
};

struct dsu {
	int par[100001],h[100001],las[100001];
	ld a0[100001],a1[100001],a2[100001];
	void reset(int n) {
		for (int i=1;i<=n;i++) {
			par[i]=i;
			h[i]=0;
			a0[i]=a1[i]=a2[i]=0;
		}
	}
	int get_par(int x) {
		if (par[x]==x) return x;
		else return par[x]=get_par(par[x]);
	}
	void merg(int u, int v) {
		u=get_par(u);
		v=get_par(v);
		if (u-v) {
			if (h[u]<h[v]) {
				par[u]=v;
				a0[v]+=a0[u];
				a1[v]+=a1[u];
				a2[v]+=a2[u];
			}
			else if (h[u]>h[v]) {
				par[v]=u;
				a0[u]+=a0[v];
				a1[u]+=a1[v];
				a2[u]+=a2[v];
			}
			else {
				par[v]=u;
				a0[u]+=a0[v];
				a1[u]+=a1[v];
				a2[u]+=a2[v];
				h[u]++;
			}
		}
	}
};
dsu gr;

vector<int> vec;
int n,m,i,j,k,t,t1,u,v,a,b;
int x[100001],y[100001],z[100001];
int reg[100001];

ld va[3],vb[3],vc[3];

vector<upd> ulist[1000001];
vector<pii(int)> mlist[1000001];
vector<int> qlist[1000001];

map<pii(int),pii(int)> sus;
int qp[100001];
ld  qr[100001];
ld get_area() {
		return	sqrt(abs((va[0]*vb[1]-va[1]*vb[0])*(va[0]*vb[1]-va[1]*vb[0])
				   +(va[1]*vb[2]-va[2]*vb[1])*(va[1]*vb[2]-va[2]*vb[1])
				   +(va[2]*vb[0]-va[0]*vb[2])*(va[2]*vb[0]-va[0]*vb[2])))/2;
}
int main()
{
	fio;
	cin>>n;
	for (i=1;i<=n;i++) {
		cin>>x[i]>>y[i]>>z[i];
	}
	cin>>m;
	for (i=1;i<=m;i++) {
		vec.clear();
		cin>>u; vec.push_back(u); reg[u]=i;
		cin>>u; vec.push_back(u); reg[u]=i;
		cin>>u; vec.push_back(u); reg[u]=i;
		sort(vec.begin(), vec.end(), [](int a, int b){
			if (z[a]-z[b]) return (z[a]<z[b]);
			return (a<b);
		});
		if (sus[{vec[0],vec[1]}].fi) sus[{vec[0],vec[1]}].se=i; else sus[{vec[0],vec[1]}].fi=i;
		if (sus[{vec[0],vec[2]}].fi) sus[{vec[0],vec[2]}].se=i; else sus[{vec[0],vec[2]}].fi=i;
		if (sus[{vec[1],vec[2]}].fi) sus[{vec[1],vec[2]}].se=i; else sus[{vec[1],vec[2]}].fi=i;
		if (z[vec[0]]==z[vec[2]]) {
			va[0]=x[vec[1]]-x[vec[0]];
			va[1]=y[vec[1]]-y[vec[0]];
			va[2]=z[vec[1]]-z[vec[0]];

			
			vb[0]=x[vec[2]]-x[vec[0]];
			vb[1]=y[vec[2]]-y[vec[0]];
			vb[2]=z[vec[2]]-z[vec[0]];

			ulist[z[vec[0]]].emplace_back(i,0,0,get_area());
		}
		else {
			vc[0]=ld((ll)x[vec[0]]*(z[vec[2]]-z[vec[1]])+(ll)x[vec[2]]*(z[vec[1]]-z[vec[0]]))/(z[vec[2]]-z[vec[0]]);
			vc[1]=ld((ll)y[vec[0]]*(z[vec[2]]-z[vec[1]])+(ll)y[vec[2]]*(z[vec[1]]-z[vec[0]]))/(z[vec[2]]-z[vec[0]]);
			vc[2]=z[vec[1]];
			
			vb[0]=vc[0]-x[vec[1]];
			vb[1]=vc[1]-y[vec[1]];
			vb[2]=vc[2]-z[vec[1]];

			if (z[vec[2]]-z[vec[1]]) {
				va[0]=x[vec[2]]-x[vec[1]];
				va[1]=y[vec[2]]-y[vec[1]];
				va[2]=z[vec[2]]-z[vec[1]];

				ld areaH=get_area();
				// cout<<"area "<<i<<' '<<areaH<<endl;
				ld lengthH=areaH*2/(z[vec[2]]-z[vec[1]]);
				ulist[z[vec[2]]].emplace_back(i,lengthH/(z[vec[2]]-z[vec[1]]),0,0);
				ulist[z[vec[1]]].emplace_back(i,-lengthH/(z[vec[2]]-z[vec[1]]),-lengthH,0);
			}

			if (z[vec[1]]-z[vec[0]]) {
				va[0]=x[vec[0]]-x[vec[1]];
				va[1]=y[vec[0]]-y[vec[1]];
				va[2]=z[vec[0]]-z[vec[1]];

				ld areaL=get_area();
				// cout<<"area "<<i<<' '<<areaL<<endl;
				ld lengthL=areaL*2/(z[vec[1]]-z[vec[0]]);
				ulist[z[vec[1]]].emplace_back(i,-lengthL/(z[vec[1]]-z[vec[0]]),lengthL,0);
				ulist[z[vec[0]]].emplace_back(i,lengthL/(z[vec[1]]-z[vec[0]]),0,0);
			}
		}
	}
	for (auto g : sus) {
		if (g.se.fi && g.se.se) mlist[z[g.fi.se]].push_back(g.se);
	}
	cin>>t;
	for (t1=1;t1<=t;t1++) {
		cin>>u>>qp[t1];
		qlist[u].push_back(t1);
	}
	gr.reset(m);
	for (k=1e6;k>=0;k--) {
		for (auto g : qlist[k]) {
			if (k>=z[qp[g]]) qr[g]=-1;
			else {
				u=gr.get_par(reg[qp[g]]);
				// cout<<"get "<<k<<' '<<g<<' '<<qp[g]<<' '<<reg[qp[g]]<<' '<<gr.a0[u]<<' '<<gr.a1[u]<<' '<<gr.a2[u]<<endl;
				va[0]=gr.a2[u];
				va[1]=(gr.a1[u]+gr.a1[u]+gr.a0[u]*(gr.las[u]-k))*(gr.las[u]-k)/2;
				qr[g]=va[0]+va[1];
			}
		}
		
		for (auto g : ulist[k]) {
			// cout<<"upd "<<g.tar<<' '<<k<<' '<<g.c0<<' '<<g.c1<<' '<<g.c2<<endl;
			u=gr.get_par(g.tar);
			gr.a2[u]+=(gr.a1[u]+gr.a1[u]+gr.a0[u]*(gr.las[u]-k))*(gr.las[u]-k)/2;
			gr.a1[u]+=gr.a0[u]*(gr.las[u]-k);
			gr.las[u]=k;
			gr.a0[u]+=g.c0;
			gr.a1[u]+=g.c1;
			gr.a2[u]+=g.c2;
		}

		for (auto g : mlist[k]) {
			gr.merg(g.fi,g.se); 
			// cout<<"merg "<<k<<' '<<g.fi<<' '<<g.se<<endl;
		}
	}
	for (t1=1;t1<=t;t1++) {
		if (qr[t1]==-1) cout<<-1<<endl;
		else cout<<fixed<<setprecision(10)<<qr[t1]<<endl;
	}
}
// a;