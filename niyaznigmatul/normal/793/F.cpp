#include <bits/stdc++.h>

using namespace std;

int const N = 123456;

int const T = 1 << 19;
vector<int> f[N];
int const INF = 1 << 30;

struct node {
  int mx;
  int smin;
};

struct query {
  int left;
  int right;
  int ans;
};

query qs[N];
vector<int> sq[N];
node tr[2 * T + 5];

int getmax(int v) {
  return std::min(tr[v].mx, tr[v].smin);
}

void relax(int v) {
  if (tr[v].smin == INF) return;
  tr[v].mx = getmax(v);
  tr[v * 2].smin = std::min(tr[v * 2].smin, tr[v].smin);
  tr[v * 2 + 1].smin = std::min(tr[v * 2 + 1].smin, tr[v].smin);
  tr[v].smin = INF;
}

void setmin(int v, int left, int right, int L, int R, int val) {
  if (right <= L || R <= left) return;
  if (L <= left && right <= R) {
    tr[v].smin = std::min(tr[v].smin, val);
    return;
  }
  relax(v);
  int mid = (left + right) >> 1;
  setmin(v * 2, left, mid, L, R, val);
  setmin(v * 2 + 1, mid, right, L, R, val);
  tr[v].mx = std::max(getmax(v * 2), getmax(v * 2 + 1));
}

int getmin(int v, int left, int right, int L, int R, int val) {
  // printf("%d %d %d %d %d %d\n", v, left, right, L, R, val);
  if (right <= L || R <= left) return -1;
  if (L <= left && right <= R) {
    if (getmax(v) <= val) return -1;
  }
  if (left == right - 1) {
    return left;
  }
  relax(v);
  int mid = (left + right) >> 1;
  int got = getmin(v * 2, left, mid, L, R, val);
  if (got >= 0) return got;
  return getmin(v * 2 + 1, mid, right, L, R, val);
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    --x;
    --y;
    f[x].push_back(y);
  }
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    qs[i] = {x - 1, y - 1, -5};
    sq[x - 1].push_back(i);
  }
  for (int i = 0; i < 2 * T; i++) tr[i] = {INF, INF};
  for (int i = n - 1; i >= 0; i--) {
    for (int y : f[i]) {
      setmin(1, 0, T, i, y, y);
    }
    for (int qid : sq[i]) {
      int got = getmin(1, 0, T, i, n, qs[qid].right);
      assert(got >= 0);
      qs[qid].ans = got;
    }
  }
  for (int i = 0; i < q; i++) {
    printf("%d\n", qs[i].ans + 1);
  }
}