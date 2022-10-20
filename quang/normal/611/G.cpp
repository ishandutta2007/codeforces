#include <bits/stdc++.h>

using namespace std;

const int N = 1000010, MOD = 1000000007;

inline int add(int u, int v) {
  u += v;
  if (u >= MOD) {
    u -= MOD;
  }
  return u;
}

inline int sub(int u, int v) {
  return add(u, MOD - v);
}

inline int mul(int u, int v) {
  return (long long) u * v % MOD;
}

int n;
int x[N], y[N];
long long pref[N], area;
int sumx[N], sumy[N], sumpref[N], prefmod[N];

bool check(int start, int cur) {
  if (start + n == cur + 1) {
    return 0;
  }
  unsigned long long foo = pref[cur - 1] - pref[start - 1];
  foo += -1ll * x[cur] * y[start] + 1ll * x[start] * y[cur];
  return abs(foo) * 2 < area;
}

int main() {
  //freopen("input.txt", "r", stdin);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", x + i, y + i);
    x[i + n] = x[i];
    y[i + n] = y[i];
  }
  x[n + n + 1] = x[1], y[n + n + 1] = y[1];
  for (int i = 1; i <= n + n; i++) {
    long long cross = - 1ll * x[i] * y[i + 1] + 1ll * x[i + 1] * y[i];
    pref[i] = pref[i - 1] + cross;
    prefmod[i] = add(prefmod[i - 1], (cross % MOD + MOD) % MOD);
    sumpref[i] = add(sumpref[i - 1], prefmod[i]);
    sumx[i] = add(sumx[i - 1], (x[i] % MOD + MOD) % MOD);
    sumy[i] = add(sumy[i - 1], (y[i] % MOD + MOD) % MOD);
  }
  area = pref[n];
  int cur = 0, cnt = 0;
  int tot = 0;
  for (int i = 1; i <= n; i++) {
    if (cur < i + 1) {
      cur = i + 1;
    }
    while (check(i, cur + 1)) {
      cur++;
    }
    if (cur == i + 1) {
      continue;
    }
    cnt = add(cnt, cur - i - 1);
    int foo = sub(sumpref[cur - 1], sumpref[i]);
    foo = sub(foo, mul(prefmod[i - 1], cur - i - 1));
    int xx = sub(sumx[cur], sumx[i + 1]);
    foo = sub(foo, mul(xx, (y[i] % MOD + MOD) % MOD));
    int yy = sub(sumy[cur], sumy[i + 1]);
    foo = add(foo, mul(yy, (x[i] % MOD + MOD) % MOD));
    tot = add(tot, foo);
  }
  int res = mul(cnt, area % MOD);
  res = sub(res, mul(2, tot));
  cout << res << endl;
  return 0;
}