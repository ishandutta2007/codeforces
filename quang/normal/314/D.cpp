#include <bits/stdc++.h>

using namespace std;

const int N = 100010, INF = (2e9 + 10);

int n;
pair<int, int> a[N];
int sufMin[N], preMin[N], sufMax[N], preMax[N];

bool check(long long u) {
  int cur = 1;
  for (int i = 1; i <= n; i++) {
    int last = i;
    while (last < n && a[last + 1].first == a[i].first) {
      last++;
    }
    while (cur <= n && u + a[i].first >= a[cur].first) {
      cur++;
    }
    int mx = max(preMax[i - 1], sufMax[cur]);
    int mn = min(preMin[i - 1], sufMin[cur]);
    if (mx - mn <= u) {
      return 1;
    }
    i = last;
  }
  return 0;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    a[i].first = u + v;
    a[i].second = u - v;
  }
  sort(a + 1, a + n + 1);
  preMin[0] = sufMin[n + 1] = INF;
  preMax[0] = sufMax[n + 1] = -INF;
  for (int i = 1; i <= n; i++) {
    preMin[i] = min(preMin[i - 1], a[i].second);
    preMax[i] = max(preMax[i - 1], a[i].second);
  }
  for (int i = n; i; i--) {
    sufMin[i] = min(sufMin[i + 1], a[i].second);
    sufMax[i] = max(sufMax[i + 1], a[i].second);
  }
  long long l = -1, r = (1ll << 32);
  while (r - l > 1) {
    long long m = (l + r) >> 1;
    if (check(m)) {
      r = m;
    } else {
      l = m;
    }
  }
  cout << r / 2 << "." << (r % 2) * 5 << endl;
  return 0;
}