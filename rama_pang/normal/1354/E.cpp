#include <bits/stdc++.h>
using namespace std;
using lint = long long;

const int MAXN = 5005;

int N, M;
int N1, N2, N3;
vector<int> adj[MAXN];

int vis[MAXN];
vector<int> ls;

void dfs(int n, int c) {
  if (vis[n] != 0 && vis[n] != c) {
    cout << "NO\n";
    exit(0);
  }
  if (vis[n]) return;
  vis[n] = c;
  ls.emplace_back(n);
  for (auto i : adj[n]) dfs(i, (c == 1 ? 2 : 1));
}

vector<pair<vector<int>, vector<int>>> cnt;
int dp[MAXN][MAXN];


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> N >> M;
  cin >> N1 >> N2 >> N3;

  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  for (int i = 1; i <= N; i++) {
    if (vis[i] == 0) {
      ls.clear();
      dfs(i, 1);
      cnt.emplace_back();
      for (auto j : ls) {
        if (vis[j] == 1) cnt.back().first.emplace_back(j);
        if (vis[j] == 2) cnt.back().second.emplace_back(j);
      }
    }
  }

  // for (auto i : cnt) {
  //   cout << i.first.size() << " " << i.second.size() << "\n";
  // }

  dp[0][0] = 1;
  for (int i = 0; i < cnt.size(); i++) {
    for (int j = 0; j <= N; j++) {
      if (j + cnt[i].first.size() <= N) {
        dp[i + 1][j + cnt[i].first.size()] |= dp[i][j];
      }
      if (j + cnt[i].second.size() <= N) {
        dp[i + 1][j + cnt[i].second.size()] |= dp[i][j];
      }
    }
  }

  if (!dp[cnt.size()][N2]) {
    cout << "NO\n";
    return 0;
  }

  string ans(N, '-');
  int cur = N2;
  for (int i = int(cnt.size()); i >= 1; i--) {
    if (cur - int(cnt[i - 1].first.size()) >= 0 && dp[i - 1][cur - int(cnt[i - 1].first.size())]) {
      cur -= int(cnt[i - 1].first.size());
      for (auto j : cnt[i - 1].first) {
        ans[j - 1] = '2';
      }
    } else if (cur - int(cnt[i - 1].second.size()) >= 0 && dp[i - 1][cur - int(cnt[i - 1].second.size())]) {
      cur -= int(cnt[i - 1].second.size());
      for (auto j : cnt[i - 1].second) {
        ans[j - 1] = '2';
      }
    }
    // cout << i-1 << " " << cur << " a\n";
  }

  for (int i = 0; i < N; i++) {
    if (ans[i] != '-') continue;
    if (N1 > 0) {
      N1--;
      ans[i] = '1';
    } else {
      ans[i] = '3';
    }
  }

  cout << "YES\n";
  cout << ans << "\n";
  return 0;

}