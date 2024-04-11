#ifndef CPL_TEMPLATE
#define CPL_TEMPLATE
/*
	Normie's Template v2.4
	Changes:
    Added include-guards to help with writing in multiple source files.
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
vector<int> vec;
vector<int> gt[1200001],rgt[200001];
int n,m,i,j,k,t,t1,u,v,a,b,q;
int pr[1000022];
int reg[1200001];
int arr[200001];
void dfs(int x)
{
    reg[x]=t;
    for (auto g : gt[x]) if (!reg[g]) dfs(g);
}
int main()
{
	fio;
    cin>>n>>q;
    m=1000001;
    for (i=1;i<=n;i++) cin>>arr[i];
    for (i=2;i<=m;i++) for (j=i;j<=m;j+=i) if (!pr[j]) pr[j]=i;
    for (i=1;i<=n;i++)
    {
        u=arr[i];
        a=0;b=0;
        while(u>1)
        {
            b=pr[u];
            if (b>a)
            {
                gt[i].push_back(n+b);
                gt[n+b].push_back(i);
            }
            a=b;
            u/=b;
        }
    }
    for (i=1;i<=n;i++) if (!reg[i])
    {
        t++;
        dfs(i);
    }
    for (i=1;i<=n;i++) 
    {
    //    cout<<reg[i]<<' ';
    }
    //cout<<endl;
    for (i=1;i<=n;i++)
    {
        u=arr[i]+1;
        vec.clear();
        a=0;b=0;
        vec.clear();
        vec.push_back(reg[i]);
        while(u>1)
        {
            b=pr[u];
            if ((b>a)and(reg[n+b]))
            {
                vec.push_back(reg[n+b]);
            }
            a=b;
            u/=b;
        }
        sort(vec.begin(),vec.end());
        vec.erase(unique(vec.begin(),vec.end()),vec.end());
        for (k=0;k<vec.size();k++)
        for (j=k+1;j<vec.size();j++)
        {
            rgt[vec[j]].push_back(vec[k]);
            rgt[vec[k]].push_back(vec[j]);
        }
    }
    for (i=1;i<=t;i++) sort(rgt[i].begin(),rgt[i].end());
    for (t1=0;t1<q;t1++)
    {
        cin>>u>>v;
    //    cout<<u<<' '<<v<<endl;
    //    cout<<reg[u]<<' '<<reg[v]<<endl;
        
        if (reg[u]==reg[v]) cout<<0<<endl;
        else 
        {
            auto it=lower_bound(rgt[reg[u]].begin(),rgt[reg[u]].end(),reg[v]);
            if ((it!=rgt[reg[u]].end())and((*it)==reg[v]))
            {
                cout<<1<<endl;
            }
            else 
            {
                cout<<2<<endl;
            }
        }
    }
}