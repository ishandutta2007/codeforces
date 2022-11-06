#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifndef ONLINE_JUDGE
using namespace std;
#define print(...) cout<<"Line:"<<__LINE__<<" ", __f(#__VA_ARGS__, __VA_ARGS__)
template<typename A, typename B>
string to_string(pair<A, B> a) {
  return "{"+to_string(a.first)+","+to_string(a.second)+"}";
}
template<typename A>
string to_string(A v) {
  bool first=1;
  std::string res="{";
  for (auto x:v) {
    if (!first)
      res+=",";
    else
      first=0;
    res+=to_string(x);
  }
  res+="}";
  return res;
}
template<typename T>
void __f(const char* name, T arg1) {
  cout<<name<<" : "<<to_string(arg1)<<endl;
}
template<typename T, typename ... Args>
void __f(const char* names, T arg1, Args... args) {
  const char* comma=strchr(names+1,',');
  cout.write(names,comma-names)<<" : "<<to_string(arg1)<<" | ";
  __f(comma+1,args...);
}
#else
#define print(...)
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef long double f80;
#define double long double
#define pii pair<int,int>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl=0x3f3f3f3f3f3f3f3fLL;
const int infi=0x3f3f3f3f;
const int mod=998244353;
//const int mod=1000000007;
typedef vector<int> vi;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) { uniform_int_distribution<int> uid(0,lim-1); return uid(rang); }
// int cnt[100005] = {};
void pre() {
}
int c[26] = {};

int sqrt1(int a) {
  int l = 0, r = 10000000000ll;
  while (l < r) {
    int m = (l+r+1)/2ll;
    // print(l, r, a, m);
    if (m * m <= a) {
      l = m;
    } else {
      r = m - 1;
    }
  }
  return l;
}

void solve() {
  int l, r;
  cin >> l >> r;
  int l2 = sqrt1(l);
  int r2 = sqrt1(r);
  int cnt = 0;
  cnt += (r2 - l2) * 3;
  if (l != l2 * l2) {
    cnt -= ((l - l2 * l2 - 1) / l2 + 1);
  }
  cnt += (r - r2 * r2) / r2 + 1;
  cout << cnt << '\n';
}
signed main() {
 ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  cout<<fixed<<setprecision(10);
  int t=1;
 cin>>t;
  fr(i,1,t)
    solve();
#ifndef ONLINE_JUDGE
  cout<<endl<<endl<<"Time elapsed: "<<(f80)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
}