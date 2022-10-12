#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n;
int a[N];

int par[N];
bool used[N];

// max, pre, suf, sum
tuple<int, int, int, int> t[N];

int root(int u) {
  if (u == par[u]) return u;
  return par[u] = root(par[u]);
}

// assume u < v
void merge(int u, int v) {
  u = root(u), v = root(v);
  
  int mu, preu, sufu, sumu;
  int mv, prev, sufv, sumv;

  tie(mu, preu, sufu, sumu) = t[u];
  tie(mv, prev, sufv, sumv) = t[v];

  int nsum = sumu + sumv;
  int nsuf = max(sufv, sufu + sumv);
  int npre = max(preu, sumu + prev);
  int nmax = max(max(mu, mv), sufu + prev);

  t[u] = make_tuple(nmax, npre, nsuf, nsum);
  par[v] = u;
}

int solve() {
  scanf("%d", &n);

  vector<pair<int, int>> v;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    t[i] = make_tuple(a[i], a[i], a[i], a[i]);

    v.emplace_back(a[i], i);
    par[i] = i;
  }
  
  sort(v.begin(), v.end());

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int sum = 0, idx = v[i].second;
    if (idx > 0 && used[idx-1]) {
      sum += max(0, get<2>(t[root(idx-1)]));
      merge(idx-1, idx);
    }

    if (idx < n-1 && used[idx+1]) {
      sum += max(0, get<1>(t[root(idx+1)]));
      merge(idx, idx+1);
    }

    ans = max(ans, sum);
    used[idx] = true;
  }

  printf("%d\n", ans);
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}