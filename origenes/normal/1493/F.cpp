#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 1123;

bool ask(int h, int w, int i1, int j1, int i2, int j2) {
  cout << "? " << h << ' ' << w << ' ' << i1 << ' ' << j1 << ' ' << i2 << ' ' << j2 << endl;
  int ret;
  cin >> ret;
  return ret == 1;
}

bool vis[maxn];

int main() {
  int n, m;
  cin >> n >> m;
  int cn = 1, cm = 1;
  FOR(i, 2, 1000) if (!vis[i]) {
    for (int j = i + i; j <= 1000; j += i) vis[j] = true;
    while (n % i == 0) {
      bool good = true;
      int step = n / i;
      if (i == 2) {
        good = ask(step, m, 1, 1, 1 + step, 1);
      } else {
        int h = i / 2;
        good = ask(step * h, m, 1, 1, 1 + step * h, 1) && ask(step * h, m, 1, 1, 1 + step * (h + 1), 1);
      }
      if (!good) break;
      cn *= i;
      n /= i;
    }
    while (m % i == 0) {
      bool good = true;
      int step = m / i;
      if (i == 2) {
        good = ask(n, step, 1, 1, 1, 1 + step);
      } else {
        int h = i / 2;
        good = ask(n, step * h, 1, 1, 1, 1 + step * h) && ask(n, step * h, 1, 1, 1, 1 + step * (h + 1));
      }
      if (!good) break;
      cm *= i;
      m /= i;
    }
  }
  int cnt[2] = {};
  FOR(i, 1, cn) if (cn % i == 0) cnt[0]++;
  FOR(i, 1, cm) if (cm % i == 0) cnt[1]++;
  cout << "! " << cnt[0] * cnt[1] << endl;
}