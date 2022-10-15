
// Problem : E. Mike and Geometry Problem
// Contest : Codeforces - Codeforces Round #361 (Div. 2)
// URL : https://codeforces.com/problemset/problem/689/E
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MAX 300001
#define mag 320
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<ll,ll>
#define piii pair<ll,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
const ll mod = 1e9 + 7;
 
ll pw(ll a, ll n){
  if(n == 0) return 1;
  ll b = pw(a, n>>1);
  b = b * b % mod;
  if(n & 1) b = b * a % mod;
  return b;
}
 
int main(){
	fio;
  ll half = pw(2, mod-2);
  ll sixth = pw(6, mod-2);
  ll p2 = 2;
  int n = 1;
  
  int k; cin >> k;
  for(int i=0;i<k;i++){
    ll x; cin >> x;
    p2 = pw(p2, x);
    n = n * (x % 2);
  }
 
  ll denom = (p2 * half) % mod;
 
  if(n % 2 == 0){
    p2 = p2 + 2;
  }
  else{
    p2 = p2 - 2;
  }
  ll num = (p2 * sixth) % mod;
  cout << (num + mod) % mod << "/" << (denom + mod) % mod << endl;
}