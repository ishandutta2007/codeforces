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
struct cmp
{
    int operator()(piii(ll) a, piii(ll) b) const
    {
        return (a.p2<b.p2);
    }
};
set<piii(ll),cmp> rngs;
vector<ll> divs[200001];
ll n,m,i,j,k,t,t1,u,v,a,b;
ll res;
ll fin;
vector<ll> lis[200001];
void add(ll l, ll r)
{
    int val=r;
  //  cout<<"add "<<l<<' '<<r<<endl;
    vector<piii(ll)> toadd;
    auto it=rngs.lower_bound({l,{l,0}});
    while(true)
    {
        if (it->p3>=r) 
        {
            r=it->p1-1;
            break;
        }
        res+=(r-it->p3)*(min(r,it->p2)-max(l,it->p1)+1);
        if (it->p1<l) toadd.push_back({it->p1,{l-1,it->p3}});
        if (it->p2>r) toadd.push_back({r+1,{it->p2,it->p3}});
        if (r<=it->p2)
        {
            rngs.erase(it);
            break;
        }
        it=rngs.erase(it);
    }
    if (l<=r) toadd.push_back({l,{r,val}});
    for (auto g : toadd) rngs.insert(g);
  //  cout<<"-----------------------DEBUG------------------\n";
  //  for (auto g : rngs) cout<<g.p1<<' '<<g.p2<<' '<<g.p3<<endl;
  //  cout<<"-----------------------DEBUG------------------\n";
}
int main()
{
	fio;
    cin>>n;
    for (i=1;i<=200000;i++) for (j=i;j<=200000;j+=i) divs[j].push_back(i);
    for (i=1;i<=n;i++)
    {
        cin>>u;
        for (auto g: divs[u])
        {
            lis[g].push_back(i);
            if (lis[g].size()==5) lis[g].erase(lis[g].begin()+2);
        }
    }
    for (i=1;i<=n;i++) rngs.insert({i,{i,i-1}});
    res=0;
    for (i=200000;i>=1;i--)
    {
        if (lis[i].size()>=2)
        {
            if (lis[i][0]+1<lis[i][lis[i].size()-1]) add(lis[i][0]+1,lis[i][lis[i].size()-1]-1);
            if (lis[i][1]<n) add(lis[i][1]+1,n);
            if (lis[i][lis[i].size()-2]>1) add(1,lis[i][lis[i].size()-2]-1);
        }
   //     if (res) cout<<i<<' '<<res<<endl;
        fin+=res;
    }
    cout<<fin;
}