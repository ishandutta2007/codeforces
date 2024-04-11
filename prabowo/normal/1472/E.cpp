#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int INF = 1e9 + 5;

int n;
int h[N], w[N];
pair<pair<int, int>, int> a[N];

int ans[N];
void run() {
  sort(a, a + n);
  int lst = -1;
  map<int, int> m;
  for (int i = 0; i < n; ++i) {
    if (lst == -1 || a[i].first.second < w[lst]) {
      lst = a[i].second;
      m[a[i].first.first] = lst;
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int ii = 0; ii < 2; ++ii) {
      auto it = m.lower_bound(h[i]);
      if (it != m.begin()) {
        --it;
        int idx = it->second;
        if (h[idx] < h[i] && w[idx] < w[i]) {
          ans[i] = idx;
        }
      }  
      swap(h[i], w[i]);
    }
  }
}

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &a[i].first.first, &a[i].first.second);
    h[i] = a[i].first.first, w[i] = a[i].first.second;
    a[i].second = i;
    ans[i] = -2;
  }

  run();
  for (int i = 0; i < n; ++i) {
    swap(a[i].first.first, a[i].first.second);
    swap(h[i], w[i]);
  }
  run();

  for (int i = 0; i < n; ++i) printf("%d ", ans[i] + 1);
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