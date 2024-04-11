#include <cstdio>
#include <iostream>
#include <vector>
#define fst first
#define sec second
using namespace std;
typedef long long ll;
const int N = 6005;
vector<pair<int, int>> a[2][2];
ll ans;
inline int gcd(int n, int m) { return !m ? n : gcd(m, n % m); }
inline int c2(int n) { return n * (n - 1) / 2; }
inline ll c3(int n) { return 1ll * n * (n - 1) * (n - 2) / 6; }
ll solve0(vector<pair<int, int>> a) {
  if (a.size() < 3) return 0;
  ll ans = 0;
  if (a[0].fst & 1)
    for (int i = 0; i < (int)a.size(); i++) a[i].fst++;
  if (a[0].sec & 1)
    for (int i = 0; i < (int)a.size(); i++) a[i].sec++;
  int c[3][2] = {0};
  for (int i = 0; i < (int)a.size(); i++) c[a[i].fst % 4][a[i].sec % 4 / 2]++;
  for (int i = 0; i < 4; i++)
    for (int j = i; j < 4; j++)
      for (int k = j; k < 4; k++) {
        int x1 = ((j & 2) - (i & 2)) >> 1, y1 = (j & 1) - (i & 1);
        int x2 = ((k & 2) - (i & 2)) >> 1, y2 = (k & 1) - (i & 1);
        if ((gcd(x1, abs(y1)) + gcd(x2, abs(y2)) + gcd(x2 - x1, abs(y2 - y1))) & 1) continue;
        if (i == j) {
          if (j != k)
            ans += 1ll * c2(c[i & 2][i & 1]) * c[k & 2][k & 1];
          else
            ans += c3(c[i & 2][i & 1]);
        } else {
          if (j != k)
            ans += 1ll * c[i & 2][i & 1] * c[j & 2][j & 1] * c[k & 2][k & 1];
          else
            ans += 1ll * c[i & 2][i & 1] * c2(c[j & 2][j & 1]);
        }
      }
  return ans;
}
int main() {
  int n;
  cin >> n;
  while (n--) {
    int x, y;
    cin >> x >> y;
    a[x & 1][y & 1].push_back(make_pair(x, y));
  }
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) ans += solve0(a[i][j]);
  cout << ans;
}