#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const int MAXN = 1e5 + 5;

int N;
int A[MAXN];
vector<int> adj[MAXN];

lint ans[MAXN];
map<int, int> cnt[MAXN];
map<int, lint> sum[MAXN];

void Dfs(int n, int p = 0) {
  cnt[n][A[n]]++;
  sum[n][cnt[n][A[n]]] += A[n];
  for (auto i : adj[n]) if (i != p) {
    Dfs(i, n);
    if (cnt[n].size() < cnt[i].size()) {
      swap(sum[n], sum[i]);
      swap(cnt[n], cnt[i]);
    }
    for (auto c : cnt[i]) {
      sum[n][cnt[n][c.first]] -= c.first;
      cnt[n][c.first] += c.second;
      sum[n][cnt[n][c.first]] += c.first;
    }
  }
  ans[n] = rbegin(sum[n])->second;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  for (int i = 1; i < N; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  Dfs(1);
  for (int i = 1; i <= N; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
  return 0;
}