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
#define dbg(x) cerr<<(#x)<<": "<<(x)<<'\n',aaa
#define dbga(x,n) cerr<<(#x)<<"[]: ";for(int _=0;_<n;_++)cerr<<x[_]<<' ';cerr<<'\n',aaa
#define dbgs(x) cerr<<(#x)<<"[stl]: ";for(auto _:x)cerr<<_<<' ';cerr<<'\n',aaa
#define dbgp(x) cerr<<(#x)<<": "<<x.fi<<' '<<x.se<<'\n',aaa

using namespace std;

//pii d[205][2]; ///.fi/.se cat au daca (0 primul e la mutare / 1 al doilea e la mutare)
//               ///se e cel care nu muta atunci
//
//void umax (int &a, int b) {
//  a = max(a, b);
//}
//
//void umin (int &a, int b) {
//  a = min(a, b);
//}

ll scor[2], now;
ll sim (int pin) {
  if (now == 0) return scor[0];
  if (now == 4) {
    scor[pin] += now/2;
    now /= 2;
    return sim(pin^1);
  }
  if (now%2 == 1 || (now/2)%2 == 0) {
    scor[pin]++;
    now--;
    return sim(pin^1);
  } else {
    scor[pin] += now/2;
    now /= 2;
    return sim(pin^1);
  }
}

int main () {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int t; cin >> t;
  while (t--) {
    ll n; cin >> n;
    scor[0] = scor[1] = 0;
    now = n;
    cout << sim(0) << '\n';
  }
//  int n; cin >> n;
//  int i, j, z;
//  for (i = 1; i <= n; i++)
//    for (j = 0; j <= 1; j++) {
//      d[i][j].se = inf;
//      if (~i&1) {
//        umax(d[i][j].fi, i/2 + d[i/2][j^1].se);
//        umin(d[i][j].se, d[i/2][j^1].fi);
//      }
//      umax(d[i][j].fi, 1 + d[i-1][j^1].se);
//      umin(d[i][j].se, d[i-1][j^1].fi);
//    }
//  cout << d[n][0].fi << ' ' << d[n][0].se << '\n';

  return 0;
}