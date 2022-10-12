#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int MOD = 1000000007;
const int INF = 1e9;

int n, m, k;
int a[N];
char s[N];

int solve() {
  scanf("%d %d", &n, &m);
  vector<int> blocks[2];
  for (int i = 0; i < m; ++i) {
    int r, c;
    scanf("%d %d", &r, &c);
    --r, --c;
    blocks[r].push_back(c);
  }
  blocks[0].push_back(-1); blocks[1].push_back(-1);
  sort(blocks[0].begin(), blocks[0].end());
  sort(blocks[1].begin(), blocks[1].end());

  int mask = 0, lst = n;
  while (blocks[0].back() >= 0 || blocks[1].back() >= 0) {
    if (blocks[0].back() == blocks[1].back()) {
      if (mask != 0) return 0 * printf("NO\n");
      lst = blocks[0].back();
      blocks[0].pop_back();
      blocks[1].pop_back();
    } else if (blocks[0].back() > blocks[1].back()) {
      if (mask == 0) {
        mask = 2;
      } else if (mask == 1) {
        if ((lst - blocks[0].back()) % 2 != 0) return 0 * printf("NO\n");
        mask = 0;
      } else if (mask == 2) {
        if ((lst - blocks[0].back()) % 2 == 0) return 0 * printf("NO\n");
        mask = 0;
      }
      lst = blocks[0].back();
      blocks[0].pop_back();
    } else if (blocks[1].back() > blocks[0].back()) {
      if (mask == 0) {
        mask = 1;
      } else if (mask == 1) {
        if ((lst - blocks[1].back()) % 2 == 0) return 0 * printf("NO\n");
        mask = 0;
      } else if (mask == 2) {
        if ((lst - blocks[1].back()) % 2 != 0) return 0 * printf("NO\n");
        mask = 0;
      }
      lst = blocks[1].back();
      blocks[1].pop_back();
    }
  }

  if (mask != 0) return 0 * printf("NO\n");
  printf("YES\n");
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