#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
const int MOD = 998244353;

int n;
int a[N];

bool nonDecreasing(int n, int a[]) {
  for (int i = 1; i < n; ++i) {
    if (a[i-1] > a[i]) return false;
  }
  return true;
}

bool vis[N];
int mex(int n, int a[]) {
  for (int i = 0; i <= n; ++i) vis[i] = false;
  for (int i = 0; i < n; ++i) {
    vis[a[i]] = true;
  }

  for (int i = 0; ; ++i) if (!vis[i]) return i;
  return -1;
}

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  vector<int> ans;
  while (!nonDecreasing(n, a)) {
    int m = mex(n, a);
    if (m >= n) {
      for (int i = 0; i < n; ++i) if (a[i] != i) {
        ans.push_back(i);
        a[i] = m;
        break;
      }
    } else {
      ans.push_back(m);
      a[m] = m;
    }
  }

  printf("%d\n", (int) ans.size());
  for (int u: ans) {
    printf("%d ", u+1);
  }
  printf("\n");
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}