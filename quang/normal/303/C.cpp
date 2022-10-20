#include <bits/stdc++.h>

using namespace std;

const int N = 5010;

int n, k, cnt;
int a[N], maxval;
long long pa[N], delta;
vector <pair<int, int> > b[1000010];

int get(int u) {
  if (pa[u] <= delta) {
    return u + delta;
  }
  return pa[u] = get(pa[u] - delta);
}

bool check(int u, int v) {
  int u1 = get(u) - delta;
  int v1 = get(v) - delta;
  if (u1 == v1) {
    return 1;
  }
  pa[u1] = v1 + delta;
  return 0;
}

void check(int i) {
  cnt = 0;
  for (int j = i; j <= maxval + 1; j += i) {
    for (int kk = 0; kk < b[j].size(); kk++) {
      int u = b[j][kk].first;
      int v = b[j][kk].second;
      if (!check(u, v)) {
        cnt++;
        if (cnt > k) {
          return;
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  #ifdef Doflamingo
  freopen("input", "r", stdin);
  #endif // Doflamingo
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    maxval = max(maxval, a[i]);
  }
  if (k >= n - 1) {
    cout << 1;
    return 0;
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (b[a[j] - a[i]].size() <= 4) {
        b[a[j] - a[i]].push_back(make_pair(i, j));
      }
    }
  }
  for (int i = 2; i <= maxval + 1; i++) {
    check(i);
    delta += n;
    if (cnt <= k) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}