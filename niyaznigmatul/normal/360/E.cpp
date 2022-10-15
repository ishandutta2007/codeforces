#include <cstdio>
#include <set>

using namespace std;

const long long INF = 1LL << 60;
const int N = 323456;

int he[N], ne[N], ss[N], ff[N];
long long lw[N], rw[N], d[N], ans[N];

int n, m;

bool gpath(int s1, int s2, int f0, int d1, int d2) {
  for (int i = 0; i < m; i++) ans[i] = rw[i];
  if (s1 == s2) {
    return d1 < d2;
  }
  for (int i = 0; i < n; i++) d[i] = INF;
  d[s1] = d1;
  d[s2] = d2;
  set<pair<long long, int> > q;
  q.insert(make_pair(d[s1], s1));
  q.insert(make_pair(d[s2], s2));
  while (!q.empty()) {
    pair<long long, int> st = *(q.begin());
    q.erase(q.begin());
    int v = st.second;
    if (d[v] != st.first) continue;
    for (int e = he[v]; e >= 0; e = ne[e]) {
      long long cw = ((d1 & 1) == (d[v] & 1) ? lw[e] : rw[e]);
      if (d[ff[e]] > d[v] + cw) {
        q.erase(make_pair(d[ff[e]], ff[e]));
        d[ff[e]] = d[v] + cw;
        q.insert(make_pair(d[ff[e]], ff[e]));
        ans[e] = cw;
      }
    }
  }
  if ((d1 & 1) == (d[f0] & 1)) return true;
  return false;
}

int main() {
  int k, s1, s2, f0;
  scanf("%d%d%d%d%d%d", &n, &m, &k, &s1, &s2, &f0);
  --s1;
  --s2;
  --f0;
  for (int i = 0; i < m; i++) {
    scanf("%d%d%I64d", ss + i, ff + i, lw + i);
    rw[i] = lw[i];
    --ss[i];
    --ff[i];
  }
  for (int i = m; i < m + k; i++) {
    scanf("%d%d%I64d%I64d", ss + i, ff + i, lw + i, rw + i);
    --ss[i];
    --ff[i];
  }
  m += k;
  for (int i = 0; i < m; i++) {
    lw[i] *= 2;
    rw[i] *= 2;
  }
  for (int i = 0; i < n; i++) he[i] = -1;
  for (int i = 0; i < m; i++) {
    ne[i] = he[ss[i]];
    he[ss[i]] = i;
  }
  if (gpath(s1, s2, f0, 1, 0)) {
    puts("WIN");
    for (int i = m - k; i < m; i++) {
      if (i > m - k) putchar(' ');
      printf("%I64d", (ans[i] / 2));
    }
    puts("");
    return 0;    
  }
  if (gpath(s1, s2, f0, 0, 1)) {
    puts("DRAW");
    for (int i = m - k; i < m; i++) {
      if (i > m - k) putchar(' ');
      printf("%I64d", (ans[i] / 2));
    }
    puts("");
    return 0;        
  }
  puts("LOSE");
}