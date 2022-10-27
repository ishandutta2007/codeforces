#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 100005, mod = 1e9 + 7, i2 = (mod + 1) >> 1;
int n, q, a[N], pw[N], ip[N], fa[N], id[N];
int st[N], top, sz[N], ans[N], s[N], sum[N];
bool inf[N];
vector<pair<int, int>> qy[N];
inline int reduce(int x) { return x + (x >> 31 & mod); }
inline int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  ip[0] = pw[0] = 1;
  for (int i = 1; i <= n; i++) {
    ip[i] = 1ll * ip[i - 1] * i2 % mod, pw[i] = 2 * pw[i - 1] % mod;
    s[i] = reduce((s[i - 1] + 1ll * pw[i] * a[i]) % mod);
  }
  for (int i = 1; i <= q; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    qy[r].push_back(make_pair(l, i));
  }
  for (int i = 1; i <= n; i++) {
    st[++top] = a[i], sz[top] = 1, inf[top] = 0, fa[i] = id[top] = i;
    while (top > 1 && st[top] > 0) {
      fa[id[top - 1]] = i, id[top - 1] = i;
      if (sz[top - 1] >= 31 || 1ll * pw[sz[top - 1]] * st[top] + st[top - 1] >= mod || inf[top - 1]) inf[top] = 1;
      if (inf[top]) {
        inf[top - 1] = 1;
        st[top - 1] = (st[top - 1] + mod + 1ll * pw[sz[top - 1]] * st[top]) % mod;
        sz[top - 1] += sz[top];
        top--;
        continue;
      }
      st[top - 1] += 1ll * pw[sz[top - 1]] * st[top];
      sz[top - 1] += sz[top];
      top--;
    }
    sum[i] = reduce((sum[id[top - 1]] + st[top]) % mod);
    for (auto [l, id] : qy[i]) {
      if (l == i) {
        ans[id] = reduce(a[i]);
        continue;
      }
      int t = find(l + 1);
      ans[id] = (sum[i] - sum[t] + mod + 1ll * ip[l + 1] * (s[t] - s[l] + mod)) % mod;
      ans[id] = (2ll * ans[id] + a[l] + mod) % mod;
    }
  }
  for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
}