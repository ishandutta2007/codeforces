#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int MOD = 1000000007;
const int INF = 1e9;

int n, m, k;
int a[N];

pair<int, int> players[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    players[i] = {a[i], i};
  }

  sort(players, players + n);

  long long sum = 0;
  int idx = -1;
  for (int i = 0; i < n; ++i) {
    sum += players[i].first;
    if (i < n - 1 && sum < players[i + 1].first) {
      idx = i;
    }
  }

  vector<int> ans;
  for (int i = idx + 1; i < n; ++i) ans.push_back(players[i].second);
  sort(ans.begin(), ans.end());

  printf("%d\n", (int) ans.size());
  for (int u : ans) printf("%d ", u + 1);
  printf("\n");
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}