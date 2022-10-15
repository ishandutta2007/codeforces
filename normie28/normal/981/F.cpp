
// Problem : F. Round Marriage
// Contest : Codeforces - Avito Code Challenge 2018
// URL : https://codeforces.com/contest/981/problem/F
// Memory Limit : 256 MB
// Time Limit : 3000 ms
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
const ll N = 1000020;
 
ll n, L;
ll a[N];
ll b[N];
ll s[N];
 
bool check(ll x) {
 
  memset(s, 0, sizeof s);
  for(ll i = n + 1; i <= n + n; ++i) {
    ll l = lower_bound(b + 1, b + n + n + n + 1, a[i] - x) - b;
    ll r = upper_bound(b + 1, b + n + n + n + 1, a[i] + x) - b - 1;
    if(l > r) {
      continue;
    }
    l = i - l + n + n;
    r = i - r + n + n;
    ++s[r];
    --s[l + 1];
  }
  for(ll i = 0; i < N; ++i) {
    if(i > 0) {
      s[i] += s[i - 1];
    }
    if(s[i] >= n) {
      return true;
    }
  }
  return false;
}
 
int main(){
    fio;
  cin >> n >> L;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
 
  for(int i = 1; i <= n; ++i) {
    cin >> b[i];
  }
 
  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1);
 
  for(int i = n + 1; i <= 3 * n; ++i) {
    a[i] = a[i - n] + L;
    b[i] = b[i - n] + L;
  }
 
  ll low = 0, high = L / 2, ans = L;
  while(low <= high) {
    int mid = (low + high) >> 1;
    if(check(mid)) {
      ans = mid;
      high = mid - 1;
    }
    else {
      low = mid + 1;
    }
  }
  cout << ans;
}