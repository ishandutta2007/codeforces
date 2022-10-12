#include <bits/stdc++.h>
using namespace std;

const int N = 303;

int n;
int a[N][N];
int p[N], pos[N];

int ans[N];
int received[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &a[i][j]);
      --a[i][j];
    }
  }

  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i]);
    pos[--p[i]] = i;
    received[i] = -1;
  }

  vector<int> v;
  for (int k = 0; k < n; ++k) {
    v.push_back(k);
    sort(v.begin(), v.end(), [&](int p, int q) {
      return pos[p] < pos[q];
    });

    for (int i = 0; i < n; ++i) {
      int give = -1;
      if (v[0] != i) give = v[0];
      else if (v[0] == i && v.size() > 1) give = v[1];
      if (give == -1) continue;

      for (int j = 0; j < n; ++j) {
        if (a[i][j] == give) {
          if (received[i] == -1 || received[i] > j) {
            received[i] = j;
            ans[i] = k;
          }
        }
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    printf("%d%c", ans[i]+1, " \n"[i == n-1]);
  }
  return 0;
}


int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}