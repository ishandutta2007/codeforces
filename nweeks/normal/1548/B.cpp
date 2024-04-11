#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
typedef long long ll;
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef vector<int> vi;
typedef pair<int, int> pi;
const int mn = 200005;
int logg[mn];
ll l[mn], g[18][mn];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int z;
  cin >> z;
  logg[0] = 0;
  logg[1] = 0;
  for (int k = 2; k < mn; k++)
    logg[k] = 1 + logg[k >> 1];
  for (int zi = 0; zi < z; zi++) {
    int n, m = 1;
    cin >> n;
    for (int k = 0; k < n; k++) {
      cin >> l[k];
      if (k > 0)
        g[0][k - 1] = abs(l[k] - l[k - 1]);
    }
    g[0][n - 1] = 1;
    for (int lo = 1; lo < 18; lo++) {
      for (int i = 0; i < n - (1 << lo); i++)
        g[lo][i] = gcd(g[lo - 1][i], g[lo - 1][i + (1 << (lo - 1))]);
      for (int i = n - (1 << lo); i < n; i++)
        g[lo][i] = 1;
    }
    for (int i = 0; i < n - 1; i++)
      if (g[0][i] != 1) {
        int deb = i, fin = n;
        while (fin - deb > 1) {
          int mi = (fin + deb) / 2;
          int lo = logg[mi - i];
          if (gcd(g[lo][i], g[lo][mi - (1 << lo) + 1]) != 1)
            deb = mi;
          else
            fin = mi;
        }
        m = max(m, fin + 1 - i);
      }
    cout << m << "\n";
  }
}