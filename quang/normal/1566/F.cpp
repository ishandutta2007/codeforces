#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

int n, m;
vector<long long> a;
vector<vector<pair<int, int>>> chunks;

void Solve(int test) {
  cin >> n >> m;
  a.resize(n);
  for (auto &u : a) {
    cin >> u;
  }
  a.push_back(-INF);
  a.push_back(INF);
  sort(a.begin(), a.end());

  chunks.resize(a.size());
  for (auto &segs : chunks) {
    segs.clear();
  }

  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    auto it = lower_bound(a.begin(), a.end(), l);
    if (r >= *it) continue;
    chunks[it - a.begin()].push_back({l, r});
  }

  for (auto &segs : chunks) {
    sort(segs.begin(), segs.end());
  }

  assert(chunks[0].empty());

  long long dp[2] = {0, 0};
  for (int i = 1; i < chunks.size(); i++) {
    auto &segs = chunks[i];
    
    vector<long long> pref(segs.size() + 1, 0);
    for (int j = 0; j < segs.size(); j++) {
      pref[j + 1] = max(pref[j], segs[j].first - a[i - 1]);
    }
    vector<long long> suff(segs.size() + 1, 0);
    for (int j = (int)segs.size() - 1; j >= 0; j--) {
      suff[j] = max(suff[j + 1], a[i] - segs[j].second);
    }

    long long new_dp[2] = {INF, INF};
    for (int j = 0; j <= segs.size(); j++) {
      new_dp[0] = min(new_dp[0], dp[0] + pref[j] * 2 + suff[j]);
      new_dp[0] = min(new_dp[0], dp[1] + pref[j] + suff[j]);
      new_dp[1] = min(new_dp[1], dp[0] + pref[j] * 2 + suff[j] * 2);
      new_dp[1] = min(new_dp[1], dp[1] + pref[j] + suff[j] * 2);
    }
    swap(dp[0], new_dp[0]);
    swap(dp[1], new_dp[1]);
  }
  cout << min(dp[0], dp[1]) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}