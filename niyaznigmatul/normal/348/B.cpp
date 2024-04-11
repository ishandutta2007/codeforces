#include <cstdio>

const int N = 223456;
const int CO = 20;
const int INF = 1 << 30;

int he[N], ne[N], ss[N], ff[N], a[N], leaf[N];
long long mm[N];
long long sum;

long long all;

long long gcd(long long a, long long b) {
  return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b) {
  return a / gcd(a, b) * b;
}

bool dfs(int v, int pr, long long mul) {
  all = lcm(all, mul);
  if (all > sum) return false;
  mm[v] = mul;
  int ch = 0;
  for (int e = he[v]; e >= 0; e = ne[e]) {
    if (ff[e] == pr) continue;
    ++ch;
  }
  leaf[v] = ch == 0;
  for (int e = he[v]; e >= 0; e = ne[e]) {
    if (ff[e] == pr) continue;
    if (!dfs(ff[e], v, mul * ch)) return false;
  }
  return true;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    he[i] = -1;
  }
  sum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    sum = sum + a[i];
  }
  for (int i = 0; i < n - 1; i++) {
    scanf("%d%d", ss + i, ff + i);
    --ss[i];
    --ff[i];
    ss[i + n - 1] = ff[i];
    ff[i + n - 1] = ss[i];
  }
  for (int i = 0; i < n + n - 2; i++) {
    ne[i] = he[ss[i]];
    he[ss[i]] = i;
  }
  all = 1;
  if (!dfs(0, -1, 1)) {
    printf("%I64d\n", sum);
    return 0;
  }
  long long ma = 1LL << 60;
  for (int i = 0; i < n; i++) {
//    printf("%I64d\n", mm[i]);
    if (!leaf[i]) continue;
    long long cur = a[i] / (all / mm[i]);
    if (cur < ma) ma = cur;
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (!leaf[i]) continue;
    ans += a[i] - all / mm[i] * ma;
  }
  printf("%I64d\n", ans);
}