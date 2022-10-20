#include <bits/stdc++.h>

using namespace std;

const int N = 300010;
const int MOD = 1000000009;
typedef pair <int, int> pi;

int n, m;
int a[N], f[N], d[N], F[N], s[N];

int range;
vector <pi> b;
vector <int> c[N];

void build() {
  f[0] = F[0] = 0;
  f[1] = F[1] = 1;
  for (int i = 2; i <= n; i++) {
    F[i] = (1ll * F[i - 1] + F[i - 2]) % MOD;
    f[i] = (1ll * F[i] + f[i - 1]) % MOD;
  }
}

int get(int x, int y, int l, int r) {
  if (x > r || y < l) {
    return 0;
  }
  if (x <= l && r <= y) {
    return f[r - l + 1];
  }
  if (x >= l) {
    int foo = min(y, r);
    return (1ll * f[foo - l + 1] - f[x - l] + MOD) % MOD;
  }
  return f[y - l + 1];
}

void update() {
  sort(b.begin(), b.end());
  int cur = 0;
  int pre2 = 0, pre1 = 0;
  for (int i = 1; i <= n; i++) {
    d[0] = 0;
    d[i] = (1ll * pre2 + pre1) % MOD;
    pre2 = pre1;
    pre1 = d[i];
    while (cur < b.size() && b[cur].first == i) {
      pre1 = (pre1 + 1) % MOD;
      d[i] = (d[i] + 1) % MOD;
      c[b[cur].second].push_back(b[cur].second - b[cur].first + 1);
      cur++;
    }
    while (!c[i].empty()) {
      int x = c[i].back();
      c[i].pop_back();
      pre1 = (1ll * pre1 + MOD - F[x]) % MOD;
      pre2 = (1ll * pre2 + MOD - F[x - 1]) % MOD;
    }
    a[i] = (1ll * a[i] + d[i]) % MOD;
    s[i] = (1ll * a[i] + s[i - 1]) % MOD;
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    s[i] = (1ll * s[i - 1] + a[i]) % MOD;
  }
  build();
  range = sqrt(m);
  while (m--) {
    int type, l, r;
    scanf("%d %d %d", &type, &l, &r);
    if (type == 1) {
      b.push_back(pi(l ,r));
    } else {
      if (b.size() >= range) {
        update();
        b.clear();
      }
      int res = (1ll * s[r] - s[l - 1] + MOD) % MOD;
      for (int i = 0; i < b.size(); i++) {
        int foo = get(l, r, b[i].first, b[i].second);
        res = (1ll * res + foo) % MOD;
      }
      printf("%d\n", res);
    }
  }
  return 0;
}