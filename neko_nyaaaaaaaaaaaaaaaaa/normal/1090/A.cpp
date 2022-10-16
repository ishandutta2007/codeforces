#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;

  Long mx = 0;
  vector<vector<Long>> vs(n);
  for (auto& v : vs) {
    int sz;
    cin >> sz;
    v.resize(sz);
    for (auto& x : v) {
      cin >> x;
      mx = max(x, mx);
    }
    sort(v.rbegin() , v.rend());
  }

  Long res = 0;

  for (auto& v : vs) {
    res += 1LL * (mx - v[0]) * v.size();
  }

  cout << res;


}