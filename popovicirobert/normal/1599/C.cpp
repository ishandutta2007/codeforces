#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define fi first
#define se second
#define inf (INT_MAX/2-1)
#define infl (1LL<<60)
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) begin(a),end(a)
#define y0 y5656
#define y1 y7878
#define aaa system("pause");
#define dbg(x) std::cerr<<(#x)<<": "<<(x)<<'\n',aaa
#define dbga(x,n) std::cerr<<(#x)<<"[]: ";for(int _=0;_<n;_++)std::cerr<<x[_]<<' ';std::cerr<<'\n',aaa
#define dbgs(x) std::cerr<<(#x)<<"[stl]: ";for(auto _:x)std::cerr<<_<<' ';std::cerr<<'\n',aaa
#define dbgp(x) std::cerr<<(#x)<<": "<<x.fi<<' '<<x.se<<'\n',aaa

using namespace std;

ll comb (ll n, ll k) {
  assert(n >= k);
  assert(k <= 3);
  if (k == 0) return 1;
  if (k == 1) return n;
  if (k == 2) return n*(n-1)/2;
  return n*(n-1)/2*(n-2)/3;
}

int main () {
  std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
  int n; cin >> n;
  string ps; cin >> ps;

  ll P = 0;
  ll cntp = 1;
  bool after = false;
  for (char ch: ps) {
    if (ch == '.') {
      after = true;
      continue;
    }
    if (after) cntp *= 10;
    P = P * 10 + ch - '0';
  }

  P *= comb(n, 3) * 2;

  int k;

  ///k = nr de harti studiate
  for (k = 0; k <= n; k++) {
    ll p = 0; ///p = prob sa pice o harta studiata

    if (k >= 3) { /// pot sa am 3S 0N la pick
      p += comb(k, 3) * 2;
    }

    if (k >= 2 && n-k >= 1) { ///pot sa am 2S 1N la pick
      p += comb(k, 2) * comb(n-k, 1) * 2;
    }

    if (k >= 1 && n-k >= 2) { ///pot sa am 1S 2N la pick
      p += comb(k, 1) * comb(n-k, 2);
    }

    ///pot sa am 0S 3N la pick => 0 sansa

    if (p * cntp - P >= 0) {
      cout << k;
      return 0;
    }
  }

  cout << n;
  return 0;
}
//#include <bits/stdc++.h>
//#define ll long long
//#define pii pair<int,int>
//#define pll pair<ll,ll>
//#define pli pair<ll,int>
//#define pil pair<int,ll>
//#define fi first
//#define se second
//#define inf (INT_MAX/2-1)
//#define infl (1LL<<60)
//#define vi vector<int>
//#define vl vector<ll>
//#define pb push_back
//#define sz(a) (int)(a).size()
//#define all(a) begin(a),end(a)
//#define y0 y5656
//#define y1 y7878
//#define aaa system("pause");
//#define dbg(x) std::cerr<<(#x)<<": "<<(x)<<'\n',aaa
//#define dbga(x,n) std::cerr<<(#x)<<"[]: ";for(int _=0;_<n;_++)std::cerr<<x[_]<<' ';std::cerr<<'\n',aaa
//#define dbgs(x) std::cerr<<(#x)<<"[stl]: ";for(auto _:x)std::cerr<<_<<' ';std::cerr<<'\n',aaa
//#define dbgp(x) std::cerr<<(#x)<<": "<<x.fi<<' '<<x.se<<'\n',aaa
//
//using namespace std;
//
//ll comb (ll n, ll k) {
//  assert(n >= k);
//  assert(k <= 3);
//  if (k == 0) return 1;
//  if (k == 1) return n;
//  if (k == 2) return n*(n-1)/2;
//  return n*(n-1)/2*(n-2)/3;
//}
//
//int main () {
//  std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
//  int n; cin >> n;
//  double P; cin >> P;
//
//  P *= comb(n, 3) * 2;
//
//  int i, j, z, k;
//
//  ///k = nr de harti studiate
//  for (k = 0; k <= n; k++) {
//    double p = 0; ///p = prob sa pice o harta studiata
//
//    if (k >= 3) { /// pot sa am 3S 0N la pick
//      p += (double)comb(k, 3) * 2;
//    }
//
//    if (k >= 2 && n-k >= 1) { ///pot sa am 2S 1N la pick
//      p += (double)comb(k, 2) * comb(n-k, 1) * 2;
//    }
//
//    if (k >= 1 && n-k >= 2) { ///pot sa am 1S 2N la pick
//      p += (double)comb(k, 1) * comb(n-k, 2);
//    }
//
//    ///pot sa am 0S 3N la pick => 0 sansa
//
//    if (p - P >= 0) {
//      cout << k;
//      return 0;
//    }
//  }
//
//  cout << n;
//  return 0;
//}