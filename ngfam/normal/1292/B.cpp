#include<bits/stdc++.h>
#define int long long

using namespace std;

const int INF = 1e18;

int dist(pair<int, int> x, pair<int, int > y) {
  return abs(x.first - y.first) + abs(x.second - y.second);
}

main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  vector<pair<int, int>> a(100);
  int ax, ay, bx, by, xs, ys, t;
  cin >> a[0].first >> a[0].second >> ax >> ay >> bx >> by;
  cin >> xs >> ys >> t;

  for(int i = 1; i < a.size(); ++i) {
    if(INF / ax < a[i - 1].first || INF / ay < a[i - 1].second) {
      a.resize(i);
      break;
    }
    a[i].first = a[i - 1].first * ax + bx;
    a[i].second = a[i - 1].second * ay + by;
  }

  int ans = 0;
  for(int l = 0; l < a.size(); ++l) {
    for(int r = 0; r < a.size(); ++r) {
      int cst = dist(make_pair(xs, ys), a[l]) + dist(a[l], a[r]);
      if(cst <= t) {
        ans = max(ans, max(l, r) - min(l, r) + 1);
      }
    }
  }

  cout << ans << endl;

  return 0;
}