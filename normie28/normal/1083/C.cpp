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
//#include <atcoder/all>
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
vector<int> vec;
int n,m,i,j,k,t,t1,u,v,a,b;
int par[200001],dep[200001];
int per[200001];
vector<int> gt[200001];
int l[200001],r[200001];
int minn[400001][20];
// DFS to initialize in/out times.
void dfs(int x)
{
    t++;
    minn[t][0]=x;
    l[x]=t;
    for (auto g : gt[x])
    {
        dfs(g);
        t++;
        minn[t][0]=x;
    }
    r[x]=t;
}
// Precalc arrays.
int lg2[400001];
int pw2[400001];
// Standard O(1) LCA algorithm.
int lca(int u, int v)
{
    int uu=l[u],vv=l[v];
    if (uu>vv) swap(uu,vv);
    int aa=lg2[vv-uu+1];
    int b=minn[uu][aa];
    int c=minn[vv-pw2[aa]+1][aa];
    if (dep[b]<dep[c]) return b;
    else return c;
}
// LCA3 calculates the intersection of paths ab,bc and ca, or the middle point of the three if they lie on a path.
// It is *extremely* powerful in this problem.
int lca3(int a, int b, int c)
{
    int ab=lca(a,b);
    int bc=lca(b,c);
    int ca=lca(a,c);
    if ((dep[ab]>=dep[bc])and(dep[ab]>=dep[ca])) return (ab);
    if ((dep[bc]>=dep[ca])and(dep[bc]>=dep[ab])) return (bc);
    if ((dep[ca]>=dep[ab])and(dep[ca]>=dep[bc])) return (ca);
}
// Each path is represented by a pair containing the endpoints, or {-1,-1} if the current set does not form a path, or {0,0} if it's empty.
// This function merges two paths.
pii(int) merg(pii(int) a, pii(int) b)
{
//    cout<<"merg "<<a.fi<<' '<<a.se<<" | "<<b.fi<<' '<<b.se<<endl;
    if (a.fi==0) return b;
    if (b.fi==0) return a;
    if (a.fi==-1) return {-1,-1};
    if (b.fi==-1) return {-1,-1};
    int u=lca3(a.fi,a.se,b.fi);
    int v=lca3(a.fi,a.se,b.se);
    int w=lca3(a.fi,b.fi,b.se);
    int x=lca3(a.se,b.fi,b.se);
    // Checking all possible pairs, as in editorial.
    // I did think of another approach, but it wasnt as straightforward to code.
    if ((u==b.fi)and(v==b.se)) return a;
    if ((w==a.fi)and(x==a.se)) return b;
    if ((u==a.se)and(w==b.se)) return {a.fi,b.fi};
    if ((v==a.fi)and(x==b.fi)) return {a.se,b.se};
    if ((v==a.se)and(w==b.fi)) return {a.fi,b.se};
    if ((u==a.fi)and(x==b.se)) return {a.se,b.fi};
    return {-1,-1};
}
// The problem is that the merg function runs really slowly, since it calls 16 functions and executes ~200 instructions, but we'll see.
// Right, it's time for segtree.

int star[200001];
struct seg
{
    pii(int) val[800001];
    void reset(int c, int l, int r)
    {
        if (l==r)
        {
            val[c]={star[l],star[l]};
        }
        else
        {
            int mid=(l+r)/2;
            reset((c<<1),l,mid);
            reset((c<<1)+1,mid+1,r);
            val[c]=merg(val[(c<<1)],val[(c<<1)+1]);
      //      cout<<"= "<<val[c].fi<<' '<<val[c].se<<endl;
        }
    }
    void upd(int c, int l, int r, int t)
    {
        if ((l<=t)and(t<=r))
        {
     //       cout<<"upd "<<c<<' '<<l<<' '<<r<<' '<<t<<endl;
            if (l==r) val[c]={star[t],star[t]};
            else
            {
                int mid=(l+r)/2;
                upd((c<<1),l,mid,t);
                upd((c<<1)+1,mid+1,r,t);
                val[c]=merg(val[(c<<1)],val[(c<<1)+1]);
       //     cout<<"= "<<val[c].fi<<' '<<val[c].se<<endl;
            }
        }
    }
    int get()
    {
        int c=1,l=1,r=n,mid;
        pii(int) pp1,pp2;
        while(true)
        {
    //        cout<<" "<<c<<' '<<l<<' '<<r<<endl;
            if (l==r)
            {
                pp2=merg(pp1,val[c]);
        //        cout<<"= "<<pp2.fi<<' '<<pp2.se<<endl;
                if (pp2.fi==-1) return l-1;
                else return l;
            }
            else
            {
                mid=(l+r)/2;
                pp2=merg(pp1,val[(c<<1)]);
        //        cout<<"= "<<pp2.fi<<' '<<pp2.se<<endl;
                if (pp2.fi==-1)
                {
                    c<<=1;
                    r=mid;
                }
                else
                {
                    c<<=1;
                    c++;
                    l=mid+1;
                    pp1=pp2;
                }
            }
        }
    }
};
seg st;
int main()
{
	fio;
    cin>>n;
    par[1]=1; dep[1]=1;
    for (i=1;i<=n;i++) cin>>per[i];
    for (i=2;i<=n;i++)
    {
        cin>>par[i];
        dep[i]=dep[par[i]]+1;
        gt[par[i]].push_back(i);
    }
    dfs(1);
    for (i=1;i<20;i++)
    {
        for (j=1;j<=t;j++)
        {
            a=minn[j][i-1];
            if (j+(1<<(i-1))<=t)
            b=minn[j+(1<<(i-1))][i-1];
            else b=a;
            if (dep[a]<dep[b]) minn[j][i]=a;
            else minn[j][i]=b;
        }
    }
    pw2[0]=1;
    for (i=1;i<20;i++) pw2[i]=pw2[i-1]*2;
    lg2[1]=0;
    for (i=2;i<=t;i++) lg2[i]=lg2[i/2]+1;
    for (i=1;i<=n;i++)
    {
        star[per[i]+1]=i;
    }
    st.reset(1,1,n);
    cin>>m;
    for (i=1;i<=m;i++)
    {
        cin>>u;
        if (u==1)
        {
            cin>>a>>b;
            star[per[a]+1]=b;
            star[per[b]+1]=a;
            st.upd(1,1,n,per[a]+1);
            st.upd(1,1,n,per[b]+1);
            swap(per[a],per[b]);
        }
        else
        {
            cout<<st.get()<<endl;
        }
    }
}