#include <bits/stdc++.h>

using namespace std;

const int N = 300010;
const long long INF = (1ll << 61);

int n, m;
struct data {
  long long t, w;
  int id;
} a[N];

bool cmp(data u, data v) {
  return u.t != v.t ? u.t > v.t : u.id < v.id;
}

int pos[N];
pair<long long, int> foo[N];

long long t[N * 4];
int cnt[N * 4];

void update(int node, int l, int r, int id, long long val) {
  if (id > r || id < l) {
    return;
  }
  if (l == r) {
    t[node] = val;
    cnt[node] = 1;
    return;
  }
  int m = (l + r) >> 1;
  update(node << 1, l, m, id, val);
  update(node << 1 | 1, m + 1, r, id, val);
  t[node] = min(t[node] + val, INF);
  cnt[node]++;
}

int get(int node, int l, int r, long long val) {
  if (l == r) {
    return (val >= t[node]) & cnt[node];
  }
  int m = (l + r) >> 1;
  if (t[node << 1] <= val) {
    return cnt[node << 1] + get(node << 1 | 1, m + 1, r, val - t[node << 1]);
  } else {
    return get(node << 1, l, m, val);
  }
  exit(1);
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d %I64d", &a[i].t, &a[i].w);
    a[i].id = i;
    foo[i] = make_pair(a[i].w - a[i].t + 1, i);
  }
  sort(foo + 1, foo + n + 1);
  for (int i = 1; i <= n; i++) {
    pos[foo[i].second] = i;
  }
  sort(a + 1, a + n + 1, cmp);
  int now = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i].id == 1) {
      now = i;
    }
  }
  for (int i = 1; i < now; i++) {
    update(1, 1, n, pos[a[i].id], a[i].w - a[i].t + 1);
  }
  int res = now;
  for (int i = now; i <= n; i++) {
    if (i != now) {
      res = min(res, i - 1 - get(1, 1, n, a[now].t - a[i].t));
    }
    int j = i;
    while (j < n && a[j + 1].t == a[i].t) {
      j++;
    }
    for (int k = i; k <= j; k++) {
      if (k != now)
      update(1, 1, n, pos[a[k].id], a[k].w - a[k].t + 1);
    }
    i = j;
  }
  res = min(res, n - get(1, 1, n, a[now].t));
  cout << res << endl;
  return 0;
}