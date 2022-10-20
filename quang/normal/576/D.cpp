#include <bits/stdc++.h>

using namespace std;

const int N = 151;

int n, m;
pair<pair<int, int>, int> a[N];
int b[N], cnt;

struct matrix {
  bitset<N> a[N];
};

bitset<N> mul(matrix u, bitset<N> v) {
  bitset<N> res;
  for (int i = 0; i < n; i++) {
    res[i] = (u.a[i] & v).any();
  }
  return res;
}

matrix turn(matrix u) {
  matrix res;
  for (int i = 0; i < n; i++ ){
    for (int j = 0 ; j < n; j++) {
      res.a[i][j] = u.a[j][i];
    }
  }
  return res;
}

matrix mul2(matrix u, matrix v) {
  matrix res;
  matrix w = turn(v);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      res.a[i][j] = (u.a[i] & w.a[j]).any();
    }
  }
  return res;
}

matrix mpow(matrix u, int v) {
  matrix res;
  for (int i = 0; i < n; i++) {
    res.a[i][i] = 1;
  }
  while (v) {
    if (v & 1) {
      res = mul2(res, u);
    }
    u = mul2(u, u);
    v >>= 1;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  #ifdef Doflamingo
  freopen("input.txt", "r", stdin);
  #endif // Doflamingo
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    a[i] = make_pair(make_pair(u, v), w);
    b[i] = w;
  }
  b[0] = 0;
  sort(b + 1, b + m + 1);
  cnt = unique(b, b + m + 1) - b;
  b[cnt] = 2000000000;
  bitset<N> root;
  root[0] = 1;
  matrix c;
  for (int i = 0; i < cnt; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[j].second == b[i]) {
        c.a[a[j].first.second][a[j].first.first] = 1;
      }
    }
    int cur = b[i] + 1;
    while (1) {
      int x[10];
      root = mul(c, root);
      if (root[n - 1]) {
        cout << cur << endl;
        return 0;
      }
      if (cur == b[i + 1] || cur == b[i] + n) {
        break;
      }
      cur++;
    }
    root = mul(mpow(c, b[i + 1] - cur), root);
  }
  cout << "Impossible";
  return 0;
}