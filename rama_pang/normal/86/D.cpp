#include <bits/stdc++.h>
#define int long long
using namespace std;
const int BLOCK = 800;

int n, t;
int cnt[1000005];
int ans[200005], a[200005];


int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> n >> t;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  auto mo = [&](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    if (a.first.first / BLOCK == b.first.first / BLOCK) {
      return a.first.second < b.first.second;
    }
    return a.first.first < b.first.first;
  };

  vector<pair<pair<int, int>, int>> query;
  for (int qi = 0; qi < t; qi++) {
    int l, r;
    cin >> l >> r;
    query.push_back({{l, r}, qi});
  }

  sort(begin(query), end(query), mo);

  long long cur = 0;
  int l = 1, r = 1;
  cur = a[1];
  cnt[a[1]]++;

  auto remove = [&](int id) {
    cur -= 1ll * cnt[a[id]] * cnt[a[id]] * a[id];
    cnt[a[id]]--;
    cur += 1ll * cnt[a[id]] * cnt[a[id]] * a[id];
  };

  auto add = [&](int id) {
    cur -= 1ll * cnt[a[id]] * cnt[a[id]] * a[id];
    cnt[a[id]]++;
    cur += 1ll * cnt[a[id]] * cnt[a[id]] * a[id];
  };

  for (int qi = 0; qi < query.size(); qi++) {
    while (query[qi].first.first < l) {
      add(l - 1);
      l--;
    }
    while (l < query[qi].first.first) {
      remove(l);
      l++;
    }
    while (query[qi].first.second < r) {
      remove(r);
      r--;
    }
    while (r < query[qi].first.second) {
      add(r + 1);
      r++;
    }
    ans[query[qi].second] = cur;
  }

  for (int i = 0; i < t; i++) {
    cout << ans[i] << "\n";
  }
}