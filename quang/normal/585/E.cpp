#include <bits/stdc++.h>

using namespace std;

const int N = 500010, MOD = 1000000007, MAXA = 10000000;

int n;
int a[N];
int pre[10000010], sign[10000010], cnt[10000010];
int p[30], k;
int val[10000], bitcount[10000], L[10000];
int p2[N];
int tot = 0;
map<int, int> mem;

 int add(int u, int v) {
  u += v;
  if (u >= MOD) {
    u -= MOD;
  }
  return u;
}

 int sub(int u, int v) {
  u -= v;
  if (u < 0) {
    u += MOD;
  }
  return u;
}

void cal() {
  for (int i = 2; i <= MAXA; i++) {
    if (!sign[i] || !cnt[i]) {
      continue;
    }
    if (sign[i] == 1) {
      tot = add(tot, sub(p2[cnt[i]], 1));
    } else {
      tot = sub(tot, sub(p2[cnt[i]], 1));
    }
  }
}

int main() {
  //freopen("input.txt", "r", stdin);
  for (int i = 1; i <= 2000; i++) {
    bitcount[i] = bitcount[i - (i & -i)] + 1;
    L[i] = log2(i);
  }
  scanf("%d", &n);
  p2[0] = 1;
  for (int i = 1; i <= n; i++) {
    p2[i] = add(p2[i - 1], p2[i - 1]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 2; i <= MAXA; i++) {
    if (pre[i]) {
      continue;
    }
    for (int j = i; j <= MAXA; j += i) {
      if (!pre[j]) {
        pre[j] = i;
      }
    }
  }
  for (int i = 2; i <= MAXA; i++) {
    sign[i]++;
    for (int j = i + i; j <= MAXA; j += i) {
      sign[j] -= sign[i];
    }
  }
  for (int i = 1; i <= n; i++) {
    k = 0;
    int foo = a[i];
    while (foo > 1) {
      int x = pre[foo];
      if (k == 0 || p[k - 1] != x) {
        p[k++] = x;
      }
      foo /= x;
    }
    val[0] = 1;
    for (int mask = 1; mask < (1 << k); mask++) {
      int x = L[mask];
      val[mask] = val[mask ^ (1 << x)] * p[x];
      cnt[val[mask]]++;
    }
  }
  cal();
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (mem[a[i]]) {
      ans = add(ans, mem[a[i]]);
      continue;
    }
    k = 0;
    int foo = a[i];
    while (foo > 1) {
      int x = pre[foo];
      if (k == 0 || p[k - 1] != x) {
        p[k++] = x;
      }
      foo /= x;
    }
    val[0] = 1;
    int res = tot;
    for (int mask = 1; mask < (1 << k); mask++) {
      int x = L[mask];
      val[mask] = val[mask ^ (1 << x)] * p[x];
      int y = val[mask];
      if (cnt[y]) {
        if (sign[y] == 1) {
          res = sub(res, sub(p2[cnt[y]], 1));
        } else {
          res = add(res, sub(p2[cnt[y]], 1));
        }
      }
      cnt[y]--;
      if (cnt[y]) {
        if (sign[y] == 1) {
          res = add(res, sub(p2[cnt[y]], 1));
        } else {
          res = sub(res, sub(p2[cnt[y]], 1));
        }
      }
      int foo = bitcount[mask];
      if (foo & 1) {
        res = sub(res, sub(p2[cnt[y]], 1));
      } else {
        res = add(res, sub(p2[cnt[y]], 1));
      }
      cnt[y]++;
    }
    ans = add(ans, res);
    mem[a[i]] = res;
  }
  cout << ans << endl;
  return 0;
}