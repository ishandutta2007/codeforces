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
deque<int> vec;
ll n,m,nn,mm,i,j,k,t,t1,u,v,a,b;
int arr[1001][1001];
int rmin[1001][1001];
int minn[1001][1001];
ll summ[1001][1001];
ll fin[1001][1001];
bool used[1001][1001];
priority_queue<piii(ll),vector<piii(ll)>,greater<piii(ll)>> lmao; 
vector<pii(ll)> res;
int main()
{
	fio;
    cin>>n>>m>>nn>>mm;
    for (i=1;i<=n;i++) for (j=1;j<=m;j++)
    {
        cin>>arr[i][j];
    }
    for (i=1;i<=n;i++)
    {
        vec.clear();
        for (j=1;j<=m;j++)
        {
            while ((vec.size())and(vec.back()>arr[i][j]))
            {
                vec.pop_back();
            }
            vec.push_back(arr[i][j]);
            if ((j>mm)and(vec.front()==arr[i][j-mm])) vec.pop_front();
            rmin[i][j]=vec.front();
        }
    }
    for (j=1;j<=m;j++)
    {
        vec.clear();
        for (i=1;i<=n;i++)
        {
            while ((vec.size())and(vec.back()>rmin[i][j]))
            {
                vec.pop_back();
            }
            vec.push_back(rmin[i][j]);
            if ((i>nn)and(vec.front()==rmin[i-nn][j])) vec.pop_front();
            minn[i][j]=vec.front();
        }
    }
    for (i=1;i<=n;i++) for (j=1;j<=m;j++)
    {
        summ[i][j]=summ[i-1][j]+summ[i][j-1]-summ[i-1][j-1]+arr[i][j];
        if ((i>=nn)and(j>=mm))
        {
            fin[i][j]=summ[i][j]-summ[i-nn][j]-summ[i][j-mm]+summ[i-nn][j-mm]-nn*mm*minn[i][j];
            lmao.push({fin[i][j],{i,j}});
        }
    }
    while(lmao.size())
    {
        auto pp=lmao.top();
        lmao.pop();
        if (used[pp.p2][pp.p3]) continue;
        res.push_back(pp.se);
        for (i=max(1,pp.p2-nn+1);i<=min(n,pp.p2+nn-1);i++)
        for (j=max(1,pp.p3-mm+1);j<=min(m,pp.p3+mm-1);j++) if (!used[i][j])
        {
            used[i][j]=1;
        }
    }
    cout<<res.size()<<endl;
    for (auto g : res) cout<<g.fi-nn+1<<' '<<g.se-mm+1<<' '<<fin[g.fi][g.se]<<endl;
}