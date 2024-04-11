/*
	Normie's Template v2.1
	Changes:
	Added vectorization optimizations.
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
#define rep(i,n)for(int i=0;i<(int)(n);++i)
 
ll powmod(ll x,ll e,ll mod){
  ll prod=1%mod;
  for(int i=63;i>=0;--i){
    prod=prod*prod%mod;
    if(e&1LL<<i)prod=prod*x%mod;
  }
  return prod;
}
ll tonellishanks(ll p,ll a){
  mt19937 mt;
  if(powmod(a,(p-1)/2,p)!=1)return -1;
  ll q=p-1;
  ll m=0;
  while(q%2==0)q/=2,m++;
  ll z;
  do{
    z=mt()%p;
  }while(powmod(z,(p-1)/2,p)!=p-1);
  ll c=powmod(z,q,p);
  ll t=powmod(a,q,p);
  ll r=powmod(a,(q+1)/2,p);
  for(;m>1;--m){
    ll tmp=powmod(t,1<<(m-2),p);
    if(tmp!=1)
      r=r*c%p,t=t*(c*c%p)%p;
    c=c*c%p;
  }
  return r;
}
 
void add(ll &x,ll y,ll m){
  x=(x+y)%m;
}
 
int main(){
  ll m;
  int n;
  scanf("%lld%d",&m,&n);
  vector<ll>a(n);
  rep(i,n)scanf("%lld",&a[i]);
  if(m<=3){
    sort(a.begin(),a.end());
    rep(x,m){
      rep(d,m){
	vector<ll> b(n);
	rep(i,n)b[i]=(x+d*i)%m;
	sort(b.begin(),b.end());
	if(a==b){
	  printf("%d %d\n",x,d);
	  return 0;
	}
      }
    }
    puts("-1");
    return 0;
  }
  if(n==m){
    puts("0 1");
    return 0;
  }
  ll sum=0;
  ll squsum=0;
  rep(i,n){
    add(sum,a[i],m);
    add(squsum,a[i]*a[i],m);
  }
  ll avg=sum*powmod(n,m-2,m)%m;
  ll vari=squsum*powmod(n,m-2,m)%m;
  add(vari,avg*(m-avg),m);
  ll d;
  if(2<=n&&n<=m-2){
    ll d2=vari*12%m;
    d2=d2*powmod(((ll)n*n-1)%m,m-2,m)%m;
    
    d=tonellishanks(m,d2);
    if(d==-1){
      puts("-1");
      return 0;
    }
  }else if(n==1){
    d=0;
  }else{
    d=1;
  }
  ll x=avg;
  ll tmp=(n-1)*d%m;
  tmp=(tmp*(m+1)/2)%m;
  add(x,m-tmp,m);
  vector<ll> b(n);
  rep(i,n)b[i]=(x+d*i)%m;
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  if(a==b){
    printf("%lld %lld\n",x,d);
  }else{
    puts("-1");
  }
}