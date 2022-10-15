#include <cstdio>
#include <iostream>

using namespace std;

int const N = 2222;
int f[N][N];
int z[N];
int can1[N], can2[N];

int main() {
  string t, s1, s2;  
  cin >> t >> s1 >> s2;
  int n = t.length();
  int m1 = s1.length();
  int m2 = s2.length();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (t[i] == t[j]) {
        if (i > 0 && j > 0) f[i][j] = f[i - 1][j - 1] + 1; else f[i][j] = 1;
      } else f[i][j] = 0;
    }
  }
  for (int i = 0; i + m1 <= n; i++) {
    bool ok = true;
    for (int j = 0; j < m1; j++) if (t[i + j] != s1[j]) {
      ok = false;
      break;
    }
    can1[i] = ok;
  }
  for (int i = 0; i + m2 <= n; i++) {
    bool ok = true;
    for (int j = 0; j < m2; j++) if (t[i + j] != s2[j]) {
      ok = false;
      break;
    }
    can2[i + m2 - 1] = ok;
  }
  for (int i = 0; i < n; i++) {
    int mx = 0;
    for (int j = 0; j < i; j++) {
      if (f[i][j] > mx) mx = f[i][j];
    }
    z[i] = mx;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      int len = j - i + 1;
      if (len < m1 || len < m2) continue;
      if (!can1[i]) continue;
      if (!can2[j]) continue;
      if (len <= z[j]) continue;
      ++ans;
    }
  }
  printf("%d\n", ans);
}