#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORN(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define BUG(x) cerr << #x << " = " << x << endl
#define SIZE(a) ((int) a.size())

#define PI acos(-1)

#define maxn 200111

int n;
long long r;
long long l[maxn], t[maxn];
vector <long long> moments;

long long solve() {
  FOR (i, 1, n)
    if (t[i] < l[i]) return -1;

  long long left = 0;
  long long res = 0;
  long long currentTime = 0;

  FOR (i, 1, n) {
    //to to the end or until drug gone
    long long way = min(left, l[i]);

    currentTime += way;
    left -= way;
    t[i] -= way;
    l[i] -= way;
    if (l[i] == 0) continue;
    //now l[i] != 0 => left= 0;

    //max path should go without drug
    long long x = min(l[i], t[i] - l[i]);

    currentTime += x * 2;
    l[i] -= x;

    while (l[i]) {
      left = 0;
      if (SIZE(moments) < 100000) {
        res++;
        moments.push_back(currentTime);
        
        long long way = min(r, l[i]);

        l[i] -= way;
        left = r - way;
        currentTime += way;
        continue;
      }
      else {
        long long need = (l[i] + r - 1) / r;
        res += need;
        left = (l[i] % r) > 0 ? (r - (l[i] % r)) : 0;
        l[i] = 0;
        break;
      }
    }
  } 

  return res;
}

int main() {
  cin >> n >> r;
  FOR (i, 1, n) cin >> l[i];
  FOR (i, 1, n) cin >> t[i];

  long long res = solve();
  cout << res << endl;
  if (res != -1 && res <= 100000) {
    REP(i, SIZE(moments))
      cout << moments[i] << " ";
  }

  return 0;
}