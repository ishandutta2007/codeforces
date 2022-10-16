#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define reset(a,b) memset(a, b, sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl;
#define BUGP(x) cout << #x << " = " << x._1 << ", " << x._2 << endl;
#define pb push_back
#define _1 first
#define _2 second
#define PR(x,a,b) { cout << #x << " = "; FOR(_,a,b) cout << x[_] << ' '; cout << endl; }
#define CON(x) { cout << #x << " = "; for (auto i: x) cout << i << ' '; cout << endl; }
#define eps 1e-9
#define sqr(x) ((x) * (x))
#define all(x) x.begin(), x.end()
#define mod 1000000007

long long t, n, m, cap, lis[200500], high, low;

long long f(long long x) {
  long long res = 0, cnt = 0, buf = 0;
  REP (i, n) if (lis[i] <= x) {
    if (!cnt) {
      res += buf;
      buf = 0;
    }
    cnt++;
    buf += lis[i];
    res += lis[i];
    if (cnt == m) {
      cnt = 0;
    }
  }
  return res;
}

long long g(long long x) {
  long long res = 0, task = 0, cnt = 0, buf = 0;
  REP (i, n) if (lis[i] <= x) {
    if (!cnt) {
      res += buf;
      buf = 0;
    }
    if (res + lis[i] > cap) break;
    res += lis[i];
    cnt++;
    buf += lis[i];
    task++;
    if (cnt == m) {
      cnt = 0;
    }
  }
  return task;
}

int main() {
  ios::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n >> m >> cap;
    REP (i, n) cin >> lis[i];
    high = cap, low = 1;
    while (high > low) {
      long long chs = (high + low) / 2;
      if (f(chs) > cap) high = chs;
      else low = chs + 1;
    }
    long long gh = g(high), gh1 = g(high - 1);
    if (gh > gh1 || high == 1) cout << gh << ' ' << high << endl;
    else cout << gh1 << ' ' << high - 1 << endl;
  }
}