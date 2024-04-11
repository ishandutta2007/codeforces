#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <bitset>
#include <random>
#include <string>
#include <vector>
#include <complex>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;

int main() {
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif

  const int K = 52;
  char pos[K];
  for (int i = 0; i < 26; ++i)
    pos[i] = char('a' + i);
  for (int i = 0; i < 26; ++i)
    pos[26 + i] = char('A' + i);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; ++i)
      cin >> s[i];
    vector<pair<int, int>> states;
    vector<array<int, 2>> ids[K];
    for (int j = 0; j < K; ++j) {
      ids[j].resize(n);
      for (int i = 0; i < n; ++i) {
        ids[j][i][0] = ids[j][i][1] = -1;
        for (int l = 0; l < (int) s[i].size(); ++l) {
          if (s[i][l] == pos[j]) {
            if (ids[j][i][0] == -1)
              ids[j][i][0] = l;
            else
              ids[j][i][1] = l;
          }
        }
      }
      for (int mask = 0; mask < (1 << n); ++mask) {
        bool ok = true;
        for (int i = 0; i < n; ++i) {
          if (ids[j][i][(mask >> i) & 1] == -1)
            ok = false;
        }
        if (ok)
          states.emplace_back(j, mask);
      }
    }
    if (states.empty()) {
      cout << 0 << '\n' << '\n';
      continue;
    }
    sort(states.begin(), states.end(), [&ids, &n](const pair<int, int> &a, const pair<int, int> &b) {
      for (int i = 0; i < n; ++i) {
        int j1 = ids[a.first][i][(a.second >> i) & 1], j2 = ids[b.first][i][(b.second >> i) & 1];
        if (j1 < j2)
          return true;
        if (j2 < j1)
          return false;
      }
      return false;
    });
    vector<int> dp(states.size(), 1);
    vector<int> par(states.size(), -1);
    vector<int> dp_submask[K];
    vector<int> id_mx[K];
    for (int j = 0; j < K; ++j) {
      dp_submask[j].resize(1 << n);
      id_mx[j].resize(1 << n);
    }
    for (int id = 0; id < (int) states.size(); ++id) {
      int j = states[id].first, mask = states[id].second;
      for (int pr = 0; pr < K; ++pr) {
        int mask2 = 0;
        bool ok = true;
        for (int i = 0; i < n; ++i) {
          if (ids[pr][i][1] != -1 && ids[pr][i][1] < ids[j][i][(mask >> i) & 1])
            mask2 += (1 << i);
          else if (ids[pr][i][0] != -1 && ids[pr][i][0] < ids[j][i][(mask >> i) & 1])
            mask2 += (0 << i);
          else
            ok = false;
        }
        if (!ok)
          continue;
        if (dp[id] < dp_submask[pr][mask2] + 1) {
          dp[id] = dp_submask[pr][mask2] + 1;
          par[id] = id_mx[pr][mask2];
        }
      }
      dp_submask[j][mask] = dp[id];
      id_mx[j][mask] = id;
      for (int i = 0; i < n; ++i) {
        if (!(mask & (1 << i)))
          continue;
        int submask = mask ^ (1 << i);
        if (dp_submask[j][mask] < dp_submask[j][submask]) {
          dp_submask[j][mask] = dp_submask[j][submask];
          id_mx[j][mask] = id_mx[j][submask];
        }
      }
    }
    int mx = 0;
    for (int i = 1; i < (int) states.size(); ++i) {
      if (dp[i] > dp[mx])
        mx = i;
    }
    cout << dp[mx] << '\n';
    string ans;
    while (mx != -1) {
      ans += pos[states[mx].first];
      mx = par[mx];
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
  }
  return 0;
}