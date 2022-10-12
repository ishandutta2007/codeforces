#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int MOD = 1000000007;
const int INF = 1e9;

int n[4], m[3];
int a[4][N];

vector<int> edgesL[4][N], edgesR[4][N];

int solve() {
  for (int i = 0; i < 4; ++i) scanf("%d", &n[i]);
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < n[i]; ++j) {
      scanf("%d", &a[i][j]);
    }
  }

  for (int i = 0; i < 3; ++i) {
    scanf("%d", &m[i]);
    for (int j = 0; j < m[i]; ++j) {
      int u, v;
      scanf("%d %d", &u, &v);
      --u, --v;

      edgesR[i][u].push_back(v);
      edgesL[i + 1][v].push_back(u);
    }
  }

  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < n[i]; ++j) {
      sort(edgesL[i][j].begin(), edgesL[i][j].end());
      edgesL[i][j].resize(unique(edgesL[i][j].begin(), edgesL[i][j].end()) - edgesL[i][j].begin());
      sort(edgesR[i][j].begin(), edgesR[i][j].end());
      edgesR[i][j].resize(unique(edgesR[i][j].begin(), edgesR[i][j].end()) - edgesR[i][j].begin());
    }
  }

  vector<pair<int, int>> sorted0(n[0]);
  for (int i = 0; i < n[0]; ++i) sorted0[i] = make_pair(a[0][i], i);
  sort(sorted0.begin(), sorted0.end());

  vector<pair<int, int>> sortedPairL(n[1]);
  for (int i = 0; i < n[1]; ++i) {
    bool found = false;
    for (int j = 0; j < n[0]; ++j) {
      if (!binary_search(edgesL[1][i].begin(), edgesL[1][i].end(), sorted0[j].second)) {
        found = true;
        sortedPairL[i] = make_pair(a[1][i] + sorted0[j].first, i);
        break;
      }
    }
    if (!found) {
      sortedPairL[i] = make_pair(INF, i);
    }
    // cerr << sortedPairL[i].first << " " << sortedPairL[i].second << endl;
  }

  vector<pair<int, int>> sorted3(n[3]);
  for (int i = 0; i < n[3]; ++i) sorted3[i] = make_pair(a[3][i], i);
  sort(sorted3.begin(), sorted3.end());

  vector<pair<int, int>> sortedPairR(n[2]);
  for (int i = 0; i < n[2]; ++i) {
    bool found = false;
    for (int j = 0; j < n[3]; ++j) {
      if (!binary_search(edgesR[2][i].begin(), edgesR[2][i].end(), sorted3[j].second)) {
        found = true;
        sortedPairR[i] = make_pair(a[2][i] + sorted3[j].first, i);
        break;
      }
    }
    if (!found) {
      sortedPairR[i] = make_pair(INF, i);
    }
    // cerr << sortedPairR[i].first << " " << sortedPairR[i].second << endl;
  }

  sort(sortedPairR.begin(), sortedPairR.end());

  int ans = INF;
  for (int i = 0; i < n[1]; ++i) {
    for (int j = 0; j < n[2]; ++j) {
      if (!binary_search(edgesR[1][i].begin(), edgesR[1][i].end(), sortedPairR[j].second)) {
        ans = min(ans, sortedPairL[i].first + sortedPairR[j].first);
        break;
      }
    }
  }

  if (ans >= INF) ans = -1;

  printf("%d\n", ans);
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}