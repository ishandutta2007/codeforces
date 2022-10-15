#include <cstdio>
#include <algorithm>

int const N = 2222;

long long ans;
int n, m;
int g[N][N], h[N][N], up[N][N], left[N][N], right[N][N], he[N], f[N], ne[N], col[N], s[N][N], ss[N][N];

int get(int x) {
  int ret = 0;
  for (int i = x; i >= 0; i = (i & (i + 1)) - 1) ret += f[i];
  return ret;
}

void add(int x, int y) {
  for (int i = x; i < m; i |= i + 1) f[i] += y;
}

void solve() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '#') {
        up[i][j] = 0;
        left[i][j] = 0;
      } else {
        up[i][j] = (i > 0 ? up[i - 1][j] : 0) + 1;
        left[i][j] = (j > 0 ? left[i][j - 1] : 0) + 1;
      }
    }
    for (int j = m - 1; j >= 0; j--) {
      if (s[i][j] == '#') {
        right[i][j] = 0;
      } else {
        right[i][j] = (j + 1 < m ? right[i][j + 1] : 0) + 1;
      }
    }
  }
  for (int low = 1; low + 1 < n; low++) {
    int cn = 0;
    for (int i = 0; i < n; i++) he[i] = -1;
    for (int i = 0; i < m; i++) f[i] = 0;
    add(0, 1);
    add(m - 1, 1);
    for (int i = 1; i + 1 < m; i++) {
      int q = low - up[low][i];
      if (q >= 0) {
        ne[cn] = he[q];
        col[cn] = i;
        he[q] = cn++;
      }
    }
    for (int i = low - 1; i > 0; i--) {
      for (int e = he[i]; e >= 0; e = ne[e]) {
        add(col[e], 1);
      }
      if (i < low - 1) {
        {
          int v = std::min(std::min(right[i][0], right[low][0]), m - 1);
          ans += v - get(v - 1);
        }
        {
          int v = std::min(std::min(left[i][m - 1], left[low][m - 1]), m - 1);
          ans += v - (get(m - 1) - get(m - v - 1));
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    std::fill(g[i], g[i] + m, 0);
    std::fill(h[i], h[i] + m, 0);
  }
  for (int i = 0; i < n; i++) {
    g[i][right[i][0] - 1]++;
    h[i][m - left[i][m - 1]]++;
    for (int j = 1; j < m; j++) h[i][j] += h[i][j - 1];
    for (int j = m - 2; j >= 0; j--) g[i][j] += g[i][j + 1];
  }
/*  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", g[i][j]);
    }
      puts("");
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", h[i][j]);
    }
      puts("");
  }*/
  for (int j = 1; j + 1 < m; j++) {
    for (int i1 = 1; i1 + 1 < n; ) {
      if (s[i1][j] == '#') {
        ++i1;
        continue;
      }
      int i2 = i1;
      int c1 = 0;
      int c2 = 0;
      while (i2 + 1 < n && s[i2][j] == '.') {
        c1 += g[i2][j];
        c2 += h[i2][j];
        ans -= g[i2][j] * h[i2][j];
        ++i2;
      }
      ans += c1 * c2;
      i1 = i2;
    }
  }
  for (int i = 1; i + 1 < n; i++) {
    if (right[i][0] == m) ++ans;
  }
  for (int i = 1; i + 1 < n; i++) {
    for (int j = 0; j + 1 < m; j++) {
      if (s[i][j] == '#') break;
      if (j > 0 && up[i][j] >= i + 1) ans++;      
    }
  }
/*  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) printf("%d ", right[i][j]);
    puts("");
  }*/
  for (int j = 1; j + 1 < m; j++) {
    for (int i = n - 1; i > 0; i--) {
      if (s[i][j] == '#') break;
      if (i + 1 < n && j + right[i][j] == m) ans++;
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int c = getchar();
      while (c <= 32) c = getchar();
      s[i][j] = c;
    }
  }
  ans = 0;
  for (int it = 0; it < 2; it++) {
    solve();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        ss[m - j - 1][i] = s[i][j];
      }
    }
    std::swap(n, m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) s[i][j] = ss[i][j];
    }
  }
  printf("%I64d\n", ans);
}