#include <bits/stdc++.h>

using namespace std;

const int N = 100100;

int n, p;
int a[N], b[N], id[N];
long long res[N];

bool cmp(int u, int v) {
  if (b[u] != b[v]) {
    return b[u] < b[v];
  }
  return a[u] < a[v];
}

struct query{
  int l, r, t, id;

  void load(int x) {
    scanf("%d %d %d", &l, &r, &t);
    id = x;
  }

  bool operator < (const query &foo) const {
    return t < foo.t;
  }
} q[N];

struct node {
  int cur;
  vector <int> A, B, Id;
  vector <double> C;

  void init() {
    cur = 0;
    A.clear();
    B.clear();
    C.clear();
    Id.clear();
  }

  void sethull(int a, int b, int _id) {
    double cross = -123456789123456789.0;
    while (!B.empty()) {
      if (B.back() == b) {
        B.pop_back();
        A.pop_back();
        C.pop_back();
        Id.pop_back();
        continue;
      }
      cross = 1.0 * (A.back() - a) / (b - B.back());
      if (cross <= C.back()) {
        B.pop_back();
        A.pop_back();
        C.pop_back();
        Id.pop_back();
      } else {
        break;
      }
    }
    Id.push_back(_id);
    A.push_back(a);
    B.push_back(b);
    C.push_back(cross);
  }

  pair<long long, int> gethull(int t) {
    while (cur < ((int)A.size() - 1) && t >= C[cur + 1]) {
      cur++;
    }
    C[cur] = t;
    return make_pair(1ll * B[cur] * t + A[cur], Id[cur]);
  }
} t[N * 4];

void build(int x, int l, int r) {
  t[x].init();
  for (int i = l; i <= r; i++) {
    id[i] = i;
  }
  sort(id + l, id + r + 1, cmp);
  for (int i = l; i <= r; i++) {
    t[x].sethull(a[id[i]], b[id[i]], id[i]);
  }
  if (l != r) {
    int m = (l + r) / 2;
    build(x * 2, l, m);
    build(x * 2 + 1, m + 1, r);
  }
}

pair<long long, int>  getquery(int f, int l, int r, int x, int y, int timenow) {
  if (x > r || y < l) {
    return make_pair(-123456789123456789ll, -123456789);
  }
  if (x <= l && r <= y) {
    return t[f].gethull(timenow);
  }
  int m = (l + r) >> 1;
  pair<long long, int> f1 = getquery(f * 2, l, m, x, y, timenow);
  pair<long long, int> f2 = getquery(f * 2 + 1, m + 1, r, x, y, timenow);
  return max(f1, f2);
}

int main() {
  //freopen("E.inp", "r", stdin);
  scanf("%d %d", &n, &p);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", a + i, b + i);
  }
  for (int i = 1; i <= p; i++) {
    q[i].load(i);
  }
  sort(q + 1, q + p + 1);
  build(1, 1, n);
  for (int i = 1; i <= p; i++) {
    res[q[i].id] = getquery(1, 1, n, q[i].l, q[i].r, q[i].t).second;
  }
  for (int i = 1; i <= p; i++) {
    printf("%I64d\n", res[i]);
  }
  return 0;
}