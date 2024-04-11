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

bool larger(int i, int j) {
  cout << "? " << i << " " << j << endl;
  fflush(stdout);

  char cmp;
  cin >> cmp;

  return cmp == '=' || cmp == '>';
} 

int main() {
  int n, t;
  cin >> t;

  while (t--) {
    cin >> n;

    if (n == 1) {
      cout << "! 1 1" << endl;
      fflush(stdout);
      continue;
    }

    int imin = 1, imax = 2;
    if (larger(1, 2)) {
      imax = 1;
      imin = 2;
    }

    for (int i = 3; i < n; i+= 2) {
      int amin = i, amax = i + 1;
      if (larger(amin, amax)) swap(amin, amax);

      if (larger(amax, imax)) imax = amax;
      if (larger(imin, amin)) imin = amin;
    }

    if (n % 2) {
      if (larger(n, imax)) imax = n;

      if (larger(imin, n)) imin = n;
    }

    cout << "! " << imin << " " << imax<< endl;
    fflush(stdout);
  }
  
  return 0;
}