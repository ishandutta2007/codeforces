#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <math.h>
#include <cstdlib>
#include <memory.h>
#include <queue>
#include <assert.h>
#include <cmath>

using namespace std;

#define pb push_back
#define f first
#define s second
#define mp make_pair 
#define sz(A) ((int)(A).size())
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define foran(i, a, n) for (int i = int(a); i < int(n); i++)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> pii;

const double EPS = 1e-9;
const int MAXN = int(1e6) + 10;

int a[MAXN * 2];
int n, l;
 
double go (int t) {
  double ans = 0;

  int r = 0;
  forn(i, n) {
    while (a[r] - a[i] <= t) r++;
    ans += 0.25 * double(min(r - i - 1, n - 1));
  }

  return ans; 
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  int t;
  scanf("%d %d %d", &n, &l, &t); t *= 2;
  forn(i, n) scanf("%d", &a[i]), a[i + n] = a[i] + l;

  double res = double(t / l) * go(l) + go(t % l);
                                 
  printf("%.10lf\n", res);       
  return 0;
}