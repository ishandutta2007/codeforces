#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int n[2];
char a[2][N];
long long res = 0;
map<string, int> m;
int cnt[2][N][10];

string sub(int u, int v) {
  string res = "";
  res += a[u][v - 1];
  res += a[u][v];
  return res;
}

void pre(int u) {
  for (int i = 2; i <= n[u]; i++) {
    for (int j = 0; j < 10; j++) {
      cnt[u][i][j] = cnt[u][i - 1][j];
    }
    cnt[u][i][m[sub(u, i)]]++;
  }
}

void get(int u) {
  int cur = 0;
  for (int i = 1; i <= n[u]; i++) {
    if (a[u][i] == a[u ^ 1][cur + 1]) {
      cur++;
      res += i - cur;
      if (cur == 1) {
        continue;
      }
      int x = m[sub(u ^ 1, cur)];
      x ^= 1;
      res -= cnt[u][i][x] - cnt[u][cur][x];
    }
  }
  for (int i = cur + 1; i <= min(n[0], n[1]); i++) {
    res += n[u] - i;
    if (i == 1) {
      continue;
    }
    int x = m[sub(u ^ 1, i)] ^ 1;
    res -= cnt[u][n[u]][x] - cnt[u][i][x];
  }
}

int main() {
  m["GB"] = 6;
  m["BG"] = 7;
  m["GR"] = 2;
  m["RG"] = 3;
  m["RB"] = 4;
  m["BR"] = 5;
  scanf("%s", a[0] + 1);
  scanf("%s", a[1] + 1);
  n[0] = strlen(a[0] + 1);
  n[1] = strlen(a[1] + 1);
  pre(0);
  pre(1);
  res = 1;
  for (int i = 2; i <= min(n[0], n[1]); i++) {
    int x = m[sub(0, i)];
    int y = m[sub(1, i)];
    res += (x ^ y) != 1;
  }
  get(0);
  get(1);
  cout << res << endl;
  return 0;
}