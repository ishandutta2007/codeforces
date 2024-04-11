/*
	Normie's Template v2.2
	Changes:
	Added modulo binpow and inverse.
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
//#include <atcoder/maxflow>
//using namespace atcoder;
 
//Pragmas (Comment out these three lines if you're submitting in szkopul.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,unroll-loops,tree-vectorize")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
 
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
namespace CPL_PRFlow
{
    struct mf_graph
    {
    struct edge
    {
        int v,rev;
        int forward;
        ll flow,cap;
        edge(int _v, int _rev, ll _flow, ll _cap, ll _f) : v(_v),rev(_rev),flow(_flow),cap(_cap),forward(_f) {}
    };
    vector<vector<edge>> gt;
    vector<int> h,po;
    vector<ll> excess;
    queue<int> q;
    vector<vector<int>> buc;
    int cur_height;
    int n,ss,tt;
    mf_graph(int _n=1000) : gt(_n),h(_n),excess(_n),n(_n),po(_n),buc(2*_n+1) {}
    void add_edge(int s, int t, ll cap, ll rcap=0)
    {
        if (s-t)
        {
            gt[s].push_back({t,gt[t].size(),0,cap,1});
            gt[t].push_back({s,gt[s].size()-1,cap,0,0});
        }
    }
    void push(int u, int x, ll f) // Push flow along edge gt[u][x].
    {
        if (!f) return;
        gt[u][x].flow+=f;
        gt[u][x].cap-=f;
        excess[u]-=f;

        int v=gt[u][x].v,y=gt[u][x].rev;

        if ((!excess[v])and(v-ss)and(v-tt))
        {
            buc[h[v]].push_back(v);
            if (cur_height<h[v]) cur_height=h[v];
        }
        gt[v][y].flow-=f;
        gt[v][y].cap+=f;
        excess[v]+=f;
        //cout<<"end push "<<u<<' '<<x<<' '<<f<<endl;

    }
    void rise(int u) // Increases u's height.
    {
        //cout<<"rise "<<u<<endl;
        int minn=1e9+7;
        for (auto g : gt[u]) if (g.cap) minn=min(minn,h[g.v]);
        if (minn<1e9)
        h[u]=minn+1;
        //cout<<"end rise "<<u<<endl;
    }
    void discharge(int u) // Get rid of all excess in u.
    {
        
        //cout<<"discharge "<<u<<' '<<h[u]<<endl;
        while(excess[u])
        {
            if (po[u]<gt[u].size())
            {
//                cout<<u<<' '<<gt[u][po[u]].v<<' '<<gt[u][po[u]].flow<<' '<<gt[u][po[u]].cap<<' '<<excess[u]<<endl;
                if ((h[u]==h[gt[u][po[u]].v]+1)and(gt[u][po[u]].cap)) 
                {
                    push(u,po[u],min(excess[u],gt[u][po[u]].cap));
                }
                po[u]++;
            }
            else
            {
                rise(u);
                po[u]=0;
            }
        }
        //cout<<"end discharge "<<u<<' '<<h[u]<<endl;
    }
    ll calc_flow(int s, int t)
    {
        ss=s;
        tt=t;
        h.assign(n,0);
        po.assign(n,0);
        h[s]=n;
        for (int i=0;i<n;i++)
        for (auto& g : gt[i]) if (g.forward)
        {
            g.flow=0;
            g.cap=g.cap+gt[g.v][g.rev].cap;
            gt[g.v][g.rev].cap=0;
            gt[g.v][g.rev].flow=g.cap;
        }
        excess.assign(n,0);
        excess[s]=1e18+7;
        cur_height=n;
        for (int i=0;i<gt[s].size();i++)
        {
            push(s,i,gt[s][i].cap);
        }
        
        while(cur_height>=0)
        {
            if (!buc[cur_height].size()) cur_height--;
            else
            {
                auto u=buc[cur_height].back();
                buc[cur_height].pop_back();
                discharge(u);
            }
        }
        
        ll res=0;
        for (auto g : gt[t]) res+=g.cap;
        return res;
    }
    };
}
using namespace CPL_PRFlow;



vector<ll> vec;
ll n,m,i,j,k,t,t1,u,v,a,b;
ll x[1001],y[1001];
int main()
{
//	fio;
    cin>>n;
    mf_graph gr(2*n+2);
    for (i=0;i<n;i++)
    {
        cin>>x[i]>>y[i]>>u;
        v+=u;
        gr.add_edge(i*2,i*2+1,u);
    }
    for (i=0;i<n;i++)
    {
        if ((x[i]%2)and(y[i]%2))
        {
            gr.add_edge(2*n,i*2,1e12+1);
            for (j=0;j<n;j++)
            {
                if ((abs(x[j]-x[i])==1)and(y[j]==y[i])) 
                gr.add_edge(i*2+1,j*2,1e12+1);
            }
        }
        if ((x[i]%2==0)and(y[i]%2))
        {
            for (j=0;j<n;j++)
            {
                if ((abs(y[j]-y[i])==1)and(x[i]==x[j]))
                gr.add_edge(i*2+1,j*2,1e12+1);
            }
        }
        if ((x[i]%2==0)and(y[i]%2==0))
        {
            for (j=0;j<n;j++)
            {
                if ((abs(x[j]-x[i])==1)and(y[j]==y[i])) 
                gr.add_edge(i*2+1,j*2,1e12+1);
            }
        }
        if ((x[i]%2)and(y[i]%2==0))
        {
            gr.add_edge(i*2+1,2*n+1,1e12+1);
        }
    }
    cout<<v-gr.calc_flow(2*n,2*n+1);
}