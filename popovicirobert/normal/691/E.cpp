#include <bits/stdc++.h>
#define MAXN 100
#define MOD 1000000007

using namespace std;

long long a[MAXN + 1][MAXN + 1];
long long ans[MAXN + 1][MAXN + 1];
long long aux[MAXN + 1][MAXN + 1];
long long v[MAXN + 1];
int n;
long long k;

inline void multiply(long long a[MAXN + 1][MAXN + 1], long long b[MAXN + 1][MAXN + 1]) {
    int i, j, k;
    for(i = 1; i <= n; i++)
      for(j = 1; j <= n; j++) {
         aux[i][j] = 0;
         for(k = 1; k <= n; k++)
            aux[i][j] = (aux[i][j] + 1LL * a[i][k] * b[k][j]) % MOD;
      }
    for(i = 1; i <= n; i++)
      for(j = 1; j <= n; j++)
         a[i][j] = aux[i][j];
}

inline void lgput() {
    for(int i = 1; i <= n; i++)
        ans[i][i] = 1;
    while(k > 0) {
        if(k & 1)
            multiply(ans, a);
        multiply(a, a);
        k >>= 1;
    }
}

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, j;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(i = 1; i <= n; i++)
        cin >> v[i];
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++) {
           int cnt = 0;
           for(int lg = 0; lg < 63; lg++)
              cnt += (((1LL << lg) & (v[i] ^ v[j])) > 0);
           if(cnt % 3 == 0)
              a[i][j] = 1;
        }
    k--;
    lgput();
    int nr = 0;
    for(i = 1; i <= n; i++)
      for(j = 1; j <= n; j++) {
          nr += ans[i][j];
          if(nr >= MOD)
            nr -= MOD;
      }
    cout << nr;
    //cin.close();
    //cout.close();
    return 0;
}