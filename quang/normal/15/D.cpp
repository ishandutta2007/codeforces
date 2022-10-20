#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, m, a, b, cnt, Cnt = 0;
int dd[N][N], A[N][N];
long long sum[N][N];
int Min[N][N], MinRow[N][N];

struct node {
  long long Val;
  int u, v;
  node (long long _Val = 0, int _u = 0, int _v = 0) {
    Val = _Val;
    u = _u;
    v = _v;
  }
} List[N * N], Res[N * N];

int st[N], top, bot;

void Pre() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + A[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    top = bot = 0;
    for (int j = 1; j <= m; j++) {
      while (top > bot && A[i][st[top - 1]] >= A[i][j]) {
        top--;
      }
      st[top++] = j;
      if (st[bot] + b == j) {
        bot++;
      }
      if (j >= b) {
        MinRow[i][j - b + 1] = A[i][st[bot]];
      }
    }
  }
  for (int j = 1; j <= m - b + 1; j++) {
    top = bot = 0;
    for (int i = 1; i <= n; i++) {
      while(top > bot && MinRow[st[top - 1]][j] >= MinRow[i][j]) {
        top--;
      }
      st[top++] = i;
      if (st[bot] + a == i) {
        bot++;
      }
      if (i >= a) {
        Min[i - a + 1][j] = MinRow[st[bot]][j];
      }
    }
  }
}

bool cmp(node x, node y) {
  if (x.Val != y.Val) {
    return x.Val < y.Val;
  }
  if (x.u != y.u) {
    return x.u < y.u;
  }
  return x.v < y.v;
}

void Mark(int u, int v) {
  int u1 = max(1, u - a + 1);
  int v1 = max(1, v - b + 1);
  int u2 = u + a - 1;
  int v2 = v + b - 1;
  for (int i = u1; i <= u2; i++) {
    for (int j = v1; j <= v2; j++) {
      dd[i][j] = 1;
    }
  }
}

void Process() {
  for (int i = 1; i <= n - a + 1; i++) {
    for (int j = 1; j <= m - b + 1; j++) {
      long long SumHeight = sum[i + a - 1][j + b - 1] + sum[i - 1][j - 1] - sum[i - 1][j + b - 1] - sum[i + a - 1][j - 1];
      long long Delta = SumHeight - 1ll * a * b * Min[i][j];
      List[++cnt] = node(Delta, i, j);
    }
  }
  sort(List + 1, List + cnt + 1, cmp);
  for (int i = 1; i <= cnt; i++) {
    if (!dd[List[i].u][List[i].v]) {
      Mark(List[i].u, List[i].v);
      Res[++Cnt] = List[i];
    }
  }
  printf("%d\n", Cnt);
  for (int i = 1; i <= Cnt; i++) {
    printf("%d %d %I64d\n", Res[i].u, Res[i].v, Res[i].Val);
  }
}

int main() {
  //ios_base::sync_with_stdio(0);
  //freopen("D.inp", "r", stdin);
  cin >> n >> m >> a >> b;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &A[i][j]);
    }
  }
  Pre();
  Process();
}