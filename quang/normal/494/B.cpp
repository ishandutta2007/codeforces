#include <bits/stdc++.h>
#define Task "B"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 100100, MOD = 1000000007;

char s[N], t[N];
int m, n;
int p[N], tr[N];
int cur, dp[N], a[N];

void KMP() {
  int k = 0;
  for(int i = 2; i <= m; i++) {
    while(k && t[i] != t[k + 1]) k = tr[k];
    if(t[i] == t[k + 1]) k++;
    tr[i] = k;
  }
  k = 0;
  for(int i = 1; i <= n; i++) {
    while(k == m || (k && s[i] != t[k + 1]))
      k = tr[k];
    if(s[i] == t[k + 1]) k++;
    p[i] = (k == m);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  //fi, fo;
  scanf("%s", s + 1);
  scanf("%s", t + 1);
  n = strlen(s + 1), m = strlen(t + 1);
  KMP();
  a[0] = 0;
  for(int i = 1; i <= n; i++) {
    if(p[i])
      a[i] = (i - m + 1 + dp[i - m]) % MOD;
    else
      a[i] = a[i - 1];
    (cur += a[i]) %= MOD;
    dp[i] = (dp[i - 1] + cur) % MOD;
  }
  cout << cur;
  return 0;
}