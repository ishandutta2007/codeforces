#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < int(n); i++)

using namespace std;

const int N = 20;
const int leng = 300;
string s[N];
int cost[N][leng], c[N][leng], sv[N][leng], a[N][leng];
int d[1 << N];

int main() {
  int n, m;
  cin >> n >> m;
  forn(i, n) cin >> s[i];
  forn(i, n) forn(j, m) cin >> a[i][j];
  
  forn(i, n) {
    forn(j, m) {
      int curv = 0;
      forn(k, n) {
        if (s[i][j] == s[k][j]) {
          sv[i][j] |= (1 << k);
          c[i][j] += a[k][j];
          curv = max(curv, a[k][j]);
        }
      }
      c[i][j] -= curv;
    }
  }
  forn(i, 1 << n) d[i] = 1000000000;
  d[0] = 0;
  forn(mask, 1 << n) {
    if (mask == 0) continue;
    int lowbit = -1;
    forn(i, n) {
      if ((mask >> i) & 1) {
        lowbit = i;
        break;
      }
    }
    forn(i, m) {
      d[mask] = min(d[mask], d[mask & (mask ^ sv[lowbit][i])] + c[lowbit][i]);
      d[mask] = min(d[mask], d[mask ^ (1 << lowbit)] + a[lowbit][i]);
    }
  }
  printf("%d\n", d[(1 << n) - 1]);
}