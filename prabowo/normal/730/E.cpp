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

#define maxn 111

int n, a[maxn], d[maxn];

int main() {
  cin >> n;
  FOR (i, 1, n)
    cin >> a[i] >> d[i];

  int res = 0;

  FOR (i, 1, n)
    FOR (j, i + 1, n) {
      bool cur = a[i] >= a[j];

      bool last = a[i] + d[i] >= a[j] + d[j];

      if (cur != last) res++;
      else {
        bool middle1 = a[i] >= a[j] + d[j];
        bool middle2 = a[i] + d[i] >= a[j];

        if (middle2 != cur || middle1 != cur) res += 2;
      }
    }

  cout << res << endl;
  return 0;
}