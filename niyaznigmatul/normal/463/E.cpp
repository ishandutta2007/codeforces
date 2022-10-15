#include <cstdio>
#include <vector>

using std::vector;

int const N = 1234567;
int const MAXN = 3234567;

int val[N], de[N], ans[N], ne[N], he[N], from[N], to[N];
int has[MAXN], p[MAXN];
vector<int> top[MAXN];

void dfs(int v, int pv, int d) {
  de[v] = d;
  ans[v] = -1;
  for (int z = val[v]; z > 1; z /= p[z]) {
    if (has[p[z]] > 0) {
      if (ans[v] < 0 || de[ans[v]] < de[top[p[z]].back()]) {
        ans[v] = top[p[z]].back();
      }
    }
  }
  for (int z = val[v]; z > 1; z /= p[z]) {
    top[p[z]].push_back(v);
    ++has[p[z]];
  }
  for (int e = he[v]; e >= 0; e = ne[e]) {
    if (to[e] == pv) continue; 
    dfs(to[e], v, d + 1);
  }
  for (int z = val[v]; z > 1; z /= p[z]) {
    top[p[z]].pop_back();
    --has[p[z]];
  }
}

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++) scanf("%d", val + i);
  for (int i = 2; i < MAXN; i++) {
    if (p[i] == 0) {
      for (int j = i; j < MAXN; j += i) p[j] = i;
    }
  }
  for (int i = 0; i < n - 1; i++) {
    scanf("%d%d", from + i, to + i);
    --from[i];
    --to[i];
    from[i + n - 1] = to[i];
    to[i + n - 1] = from[i];
  }
  for (int i = 0; i < n; i++) he[i] = -1;
  for (int i = 0; i < n + n - 2; i++) {
    ne[i] = he[from[i]];
    he[from[i]] = i;
  }
  dfs(0, -1, 0);
  for (int i = 0; i < q; i++) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int v;
      scanf("%d", &v);
      --v;
      printf("%d\n", ans[v] < 0 ? -1 : (1 + ans[v]));
    } else {
      int v, w;
      scanf("%d%d", &v, &w);
      --v;
      val[v] = w;
      dfs(0, -1, 0);
    }
//    for (int j = 0; j < n; j++) printf("%d ", ans[j]);
//    puts("");
  }
}