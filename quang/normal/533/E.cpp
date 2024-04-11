#include <bits/stdc++.h>

using namespace std;

const int MOD1 = 1000000007, MOD2 = 1000000009, base = 100007;
const int N = 100100;

int n, res = 0, cnt;
int m1[N], m2[N];
string s[2];
int s1[N], s2[N];
pair <int, int> r[2][N * 26];

void make(int u) {
  for (int i = 0; i <= n + 2; i++) {
    s1[i] = s2[i] = 0;
  }
  for (int i = 1; i <= n; i++){
    s1[i] = (1ll * m1[i] * s[u][i - 1] + s1[i - 1]) % MOD1;
    s2[i] = (1ll * m2[i] * s[u][i - 1] + s2[i - 1]) % MOD2;
  }
  for (int i = 0; i <= n; i++) {
    int sum1, sum2;
    sum1 = (1ll * s1[n] - s1[i] + MOD1) % MOD1;
    sum2 = (1ll * s2[n] - s2[i] + MOD2) % MOD2;
    sum1 = (1ll * sum1 * base + s1[i]) % MOD1;
    sum2 = (1ll * sum2 * base + s2[i]) % MOD2;
    for (char j = 'a'; j <= 'z'; j++) {
      int Sum1 = (1ll * sum1 + 1ll * m1[i + 1] * j) % MOD1;
      int Sum2 = (1ll * sum2 + 1ll * m2[i + 1] * j) % MOD2;
      r[u][++cnt] = make_pair(Sum1, Sum2);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  cin >> s[0];
  cin >> s[1];
  m1[0] = m2[0] = 1;
  for (int i = 1; i <= n + 2; i++) {
    m1[i] = 1ll * m1[i - 1] * base % MOD1;
    m2[i] = 1ll * m2[i - 1] * base % MOD2;
  }
  cnt = 0;
  make(0);
  cnt = 0;
  make(1);
  sort(r[0] + 1, r[0] + cnt + 1);
  sort(r[1] + 1, r[1] + cnt + 1);
  r[1][0] = make_pair(r[1][1].first - 1, r[1][1].second);
  for (int i = 1; i <= cnt; i++) {
    if (r[1][i] != r[1][i - 1]) {
      if (binary_search(r[0] + 1, r[0] + cnt + 1, r[1][i])) {
        res++;
      }
    }
  }
  cout << res;
  return 0;
}