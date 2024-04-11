#include <bits/stdc++.h>

#define Task "A"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 300100, MOD = 1000000009;

int n, m;
int Pow[N * 2];
map <int, int> x;

int main() {
  ios_base::sync_with_stdio(0);
  //fi, fo;
  cin >> n >> m;
  vector <string> s;
  s.resize(n + 10);
  Pow[0] = 1;
  for (int i = 1; i <= 300001; i++) {
    Pow[i] = (1ll * Pow[i - 1] * 100007) % MOD;
  }
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    int foo = 0;
    for (int j = 0; j < s[i].size(); j++) {
      foo = (1ll * foo + (1ll * (s[i][j] - 'a' + 1) * Pow[j]) % MOD) % MOD;
    }
    for (int j = 0; j < s[i].size(); j++) {
      int fooo = (1ll * foo + MOD - (1ll * (s[i][j] - 'a' + 1) * Pow[j]) % MOD) % MOD;
      for (int k = 1; k <= 3; k++) {
        if (k != s[i][j] - 'a' + 1) {
          int xx = (1ll * fooo + 1ll * k * Pow[j]) % MOD;
          x[xx] = i;
        }
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    string ss;
    cin >> ss;
    int foo = 0;
    for (int j = 0; j < ss.size(); j++) {
      foo = (1ll * foo + 1ll * (ss[j] - 'a' + 1) * Pow[j]) % MOD;
    }
    if (x[foo]) {
      int flag = 0;
      if (ss.size() != s[x[foo]].size()) {
        cout << "NO\n";
      } else {
        int vt = x[foo];
        for (int j = 0; j < ss.size(); j++) {
          if (ss[j] != s[vt][j]) {
            flag++;
          }
        }
        cout << ((flag == 1) ? "YES\n" : "NO\n");
      }
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}