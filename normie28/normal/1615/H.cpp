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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>
 
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
template<typename T>
__attribute__((always_inline)) void chkmin(T& a, const T& b) {
    a=(a<b)?a:b;
}

template<typename T>
__attribute__((always_inline)) void chkmax(T& a, const T& b) {
    a=(a>b)?a:b;
}
 
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
//---------END-------//
#endif

namespace CPL_MCF {

	const ll MAXN = 1011;
	const ll INF = 1e16;

	template<class T>
	struct edge {
		T u, v, cap, cost, rev;
		edge(T a, T b, T c, T d, T e) {
			u=a;
			v=b;
			cap=c;
			cost=d;
			rev=e;
		}
	};

	template<class T>
	struct mcf {
		vector<edge<T>> lis;
		vector<edge<T>> lis_t;
		vector<T> adj[MAXN];
		
		T n, s, t, lim, m, coeff;
		pair<T,T> res;
		T dis[MAXN];
		T lead[MAXN];

		void reset(T nn) {
			for (int i=0;i<nn;i++) adj[i].clear();
			n=nn;
			res={0,0};
			lis.clear();
			lis_t.clear();
		}

		void add_edge(T u, T v, T cap, T cost) {
			// cout<<"add "<<u<<' '<<v<<' '<<cap<<' '<<cost<<endl;
			lis.push_back(edge<T>(u,v,cap,cost,-1));
			// a
			// lis.push_back(edge<T>(v,u,0,-cost,i));
		}

		void reduce() {
			for (int i=0;i<m;i++) if (lis_t[i].rev>i) {
				lis_t[i].cost+=dis[lis_t[i].u]-dis[lis_t[i].v];
				lis_t[lis_t[i].rev].cost=0;
			}
		}

		void disBF() {
			// cout<<"disBF\n";
			T inq[n],cnt[n];
			deque<T> q;
			for (int i=0;i<n;i++) {
				cnt[i]=0;
				inq[i]=0;
				dis[i]=INF;
			}
			q.push_back(s);
			dis[s]=0;
			inq[s]=1;
			cnt[s]++;
			while(q.size())
			{
				T cur=q.front();
		       	// cout<<"relaxing "<<cur<<' '<<dis[cur]<<endl;
				for (T g : adj[cur])
				{
					// cout<<g<<endl;
					if ((dis[cur]+lis_t[g].cost<dis[lis_t[g].v])and(lis_t[g].cap))
					{
						dis[lis_t[g].v]=dis[cur]+lis_t[g].cost;
						if (!inq[lis_t[g].v])
						{
							inq[lis_t[g].v]=1;
							cnt[lis_t[g].v]++;
							if (cnt[lis_t[g].v]>n) break;
							q.push_back(lis_t[g].v);
						}
					}
				}
				q.pop_front();
				inq[cur]=0;
			}
		}

		void disDIJ() {
			priority_queue<pair<T,T>,vector<pair<T,T>>,greater<pair<T,T>>> pq;
			for (int i=0;i<n;i++) {
				dis[i]=INF;
			}
			dis[s]=0;
			pq.push({0,s});
			while(pq.size()) {
				// cout<<"dij loop\n";
				auto pp = pq.top();
				// cout<<pp.fi<<' '<<pp.se<<endl;
				pq.pop();
				if (dis[pp.se]<pp.fi) continue;
				for (auto g : adj[pp.se]) {
					edge<T> ed = lis_t[g];
					if (ed.cap && dis[ed.v]>pp.fi+ed.cost) {
						dis[ed.v] = pp.fi+ed.cost;
						lead[ed.v] = g;
						pq.push({dis[ed.v],ed.v});
					}
				}
			}
		}

		void augment() {
			vector<T> path;
			T uu = t;
			while (uu != s) {
				// cout<<"augment loop\n";
				path.push_back(lead[uu]);
				uu = lis_t[lead[uu]].u;
			}
			T added;
			added = lim-res.fi;
			for (auto g : path) {
				added=min(added,lis_t[g].cap);
			}
			for (auto g : path) {
				lis_t[g].cap-=added;
				lis_t[lis_t[g].rev].cap+=added;
			}
			res.fi+=added;
		}

		

		T fakeAugment() {
			T sus=0;
			vector<T> path;
			T uu = t;
			while (uu != s) {
				// cout<<"augment loop\n";
				path.push_back(lead[uu]);
				uu = lis_t[lead[uu]].u;
			}
			T added;
			added = lim-res.fi;
			for (auto g : path) {
				added=min(added,lis_t[g].cap);
			}
			for (auto g : path) {
				// cout<<lis_t[g].u<<' '<<lis_t[g].v<<' '<<lis[g].cost<<endl;
				
				if (g<m/2) sus+=lis[g].cost*added;
				if (g>=m/2) sus-=lis[g-m/2].cost*added;
			}
			return sus;
		}

		void get_result() {
			for (int i=0;i<m/2;i++) {
				res.se += lis_t[lis_t[i].rev].cap * lis[i].cost;
			}
		}

		pair<T,T> calc_flow(T ss, T tt, T limm) {
			s=ss;
			t=tt;
			lim=limm;
			m=lis.size();
			lis_t=lis;
			res={0,0};
			
			for (int i=0;i<m;i++) {
				lis_t.push_back(edge<T>(lis_t[i].v,lis_t[i].u,0,-lis_t[i].cost,i));
				lis_t[i].rev=i+m;
			}
			
			m=lis_t.size();
			for (int i=0;i<m;i++) {
				adj[lis_t[i].u].push_back(i);
			}

			disBF();
			coeff=dis[s]-dis[t];
			reduce();
			
			while(true) {
				// cout<<"outer loop\n";
				// for (auto g : lis_t) cout<<g.u<<' '<<g.v<<' '<<g.cap<<' '<<g.cost<<endl;
				disDIJ();
				if (dis[t]==INF) break;
				reduce();
				// cout<<fakeAugment()<<endl;
				if (fakeAugment()>=0) break;
				augment();
				if (res.fi == lim) break;
			}
			get_result();
			return res;
		}
	};

}

CPL_MCF::mcf<ll> gr;

vector<pii(ll)> edges;
vector<pii(ll)> gt[1003];
ll n,m,i,j,k,t,t1,u,v,a,b;
ll arr[1003];
ll dis[1003];
ll flg[1003];
int main()
{
	fio;
	cin>>n>>m;
	gr.reset(n+2);
	for (i=1;i<=n;i++) {
		cin>>arr[i];
		gr.add_edge(0,i,1,0);
		gr.add_edge(i,n+1,1,0);
	}
	for (i=1;i<=m;i++) {
		cin>>u>>v;
		edges.push_back({u,v});
		gr.add_edge(u,v,1e4,arr[v]-arr[u]);
	}
	auto pp = gr.calc_flow(0,n+1,1e4);
	// if (-pp.se>1e9) cout<<-pp.se<<endl;
	a=gr.lis.size();
	for (int i=0;i<a;i++) {
		if (gr.lis_t[i].cap) {
			gt[gr.lis_t[i].u].push_back({gr.lis_t[i].v,-gr.lis[i].cost});	
			// cout<<"edge "<<gr.lis_t[i].u<<' '<<gr.lis_t[i].v<<' '<<-gr.lis[i].cost<<endl;
		}
		if (gr.lis_t[i+a].cap) {
			gt[gr.lis_t[i+a].u].push_back({gr.lis_t[i+a].v,gr.lis[i].cost});
			// cout<<"edge "<<gr.lis_t[i+a].u<<' '<<gr.lis_t[i+a].v<<' '<<gr.lis[i].cost<<endl;
		}	
	}
	for (i=0;i<=n+1;i++) dis[i]=-1e18;
	dis[0]=0;
	flg[0]=1;
	while(true) {
		int a=0;
		for (i=0;i<=n+1;i++) if (flg[i]) {
			a=1;
			flg[i]=0;
			for (auto g : gt[i]) if (dis[g.fi]<dis[i]+g.se) {
				dis[g.fi]=dis[i]+g.se;
				flg[g.fi]=1;
			} 
		}
		if (!a) break;
	}
	for (i=1;i<=n;i++) cout<<arr[i]+dis[i]<<' ';
}