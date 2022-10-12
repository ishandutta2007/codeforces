#include <bits/stdc++.h>
using namespace std;

const int N = 500005;

int n;
int a[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  vector<tuple<int, int, int>> v;
  for (int i = 0; i < n; ++i) {
    v.emplace_back((i + 1) / (a[i] + 1), a[i] == 0 ? N : (i + 1) / a[i], i);
  }
  sort(v.begin(), v.end());

  vector<int> ans(n);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  for (int i = 0, j = 0; i < n; ++i) {
    while (j < n && get<0>(v[j]) == i) {
      pq.emplace(get<1>(v[j]), get<2>(v[j]));
      j++;
    }

    ans[pq.top().second] = i;
    pq.pop();
  }

  for (int i = 0; i < n; ++i) {
    printf("%d ", ans[i] + 1);
  }
  printf("\n");
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc + 1);
    solve();
  }
  return 0;
}