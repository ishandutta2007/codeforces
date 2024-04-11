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

int id1[1000][1000];
const int MAXN = 3000;
vector<int> G[MAXN];
int couple[MAXN];
int used[MAXN];

bool kun(int v, int c) {
  if (used[v] == c)
    return false;
  used[v] = c;
  for (int u : G[v]) {
    if (couple[u] == -1) {
      couple[u] = v;
      return true;
    }
  }
  for (int u : G[v]) {
    if (kun(couple[u], c)) {
      couple[u] = v;
      return true;
    }
  }
  return false;
}

void dfs(int v, vector<bool> &used1, vector<bool> &used2) {
  used1[v] = true;
  for (int u : G[v]) {
    used2[u] = true;
    if (!used1[couple[u]])
      dfs(couple[u], used1, used2);
  }
}

int main() {
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif

  int n;
  cin >> n;
  vector<pair<int, int>> A(n);
  vector<int> allx(n);
  vector<int> ally(n);
  for (int i = 0; i < n; ++i) {
    cin >> allx[i] >> ally[i];
    A[i] = make_pair(allx[i], ally[i]);
  }
  sort(allx.begin(), allx.end());
  allx.resize(unique(allx.begin(), allx.end()) - allx.begin());
  sort(ally.begin(), ally.end());
  ally.resize(unique(ally.begin(), ally.end()) - ally.begin());
  for (int i = 0; i < n; ++i) {
    A[i].first = lower_bound(allx.begin(), allx.end(), A[i].first) - allx.begin();
    A[i].second = lower_bound(ally.begin(), ally.end(), A[i].second) - ally.begin();
  }
  int m = allx.size();
  int k = ally.size();
  vector<vector<int>> by_x(m);
  for (int i = 0; i < n; ++i)
    by_x[A[i].first].emplace_back(A[i].second);
  int cnt1 = 0;
  for (int i = 0; i < m; ++i) {
    sort(by_x[i].begin(), by_x[i].end());
    fill(id1[i], id1[i] + k, -1);
    for (int j = 0; j + 1 < by_x[i].size(); ++j) {
      if (by_x[i][j] + 1 != by_x[i][j + 1]) {
        for (int l = by_x[i][j] + 1; l < by_x[i][j + 1]; ++l)
          id1[i][l] = cnt1;
        ++cnt1;
      }
    }
  }
  vector<vector<int>> by_y(k);
  for (int i = 0; i < n; ++i)
    by_y[A[i].second].emplace_back(A[i].first);
  int cnt2 = 0;
  for (int i = 0; i < k; ++i) {
    sort(by_y[i].begin(), by_y[i].end());
    for (int j = 0; j + 1 < by_y[i].size(); ++j) {
      if (by_y[i][j] + 1 != by_y[i][j + 1]) {
        for (int l = by_y[i][j] + 1; l < by_y[i][j + 1]; ++l) {
          if (id1[l][i] != -1)
            G[id1[l][i]].emplace_back(cnt2);
        }
        ++cnt2;
      }
    }
  }
  fill(used, used + cnt1, -1);
  fill(couple, couple + cnt2, -1);
  for (int i = 0; i < cnt1; ++i)
    kun(i, i);
  vector<bool> has_couple(cnt1);
  for (int i = 0; i < cnt2; ++i) {
    if (couple[i] != -1)
      has_couple[couple[i]] = true;
  }
  vector<bool> used1(cnt1, false);
  vector<bool> used2(cnt2, false);
  for (int i = 0; i < cnt1; ++i) {
    if (!has_couple[i])
      dfs(i, used1, used2);
  }
  vector<pair<int, pair<int, int>>> ans_v;
  int cnt11 = 0;
  for (int i = 0; i < m; ++i) {
    int cur_l = by_x[i][0];
    for (int j = 0; j + 1 < by_x[i].size(); ++j) {
      if (by_x[i][j] + 1 != by_x[i][j + 1]) {
        if (!used1[cnt11]) {
          ans_v.emplace_back(i, make_pair(cur_l, by_x[i][j]));
          cur_l = by_x[i][j + 1];
        }
        ++cnt11;
      }
    }
    ans_v.emplace_back(i, make_pair(cur_l, by_x[i].back()));
  }
  vector<pair<int, pair<int, int>>> ans_h;
  int cnt22 = 0;
  for (int i = 0; i < k; ++i) {
    int cur_l = by_y[i][0];
    for (int j = 0; j + 1 < by_y[i].size(); ++j) {
      if (by_y[i][j] + 1 != by_y[i][j + 1]) {
        if (used2[cnt22]) {
          ans_h.emplace_back(i, make_pair(cur_l, by_y[i][j]));
          cur_l = by_y[i][j + 1];
        }
        ++cnt22;
      }
    }
    ans_h.emplace_back(i, make_pair(cur_l, by_y[i].back()));
  }
  cout << ans_h.size() << '\n';
  for (auto t : ans_h)
    cout << allx[t.second.first] << ' ' << ally[t.first] << ' ' << allx[t.second.second] << ' ' << ally[t.first] << '\n';
  cout << ans_v.size() << '\n';
  for (auto t : ans_v)
    cout << allx[t.first] << ' ' << ally[t.second.first] << ' ' << allx[t.first] << ' ' << ally[t.second.second] << '\n';
  return 0;
}