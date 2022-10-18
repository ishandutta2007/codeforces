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
const int MAXV = int(1e7);

bool can[MAXV+10];
vector <int> a;
int n;

int main() {
  memset (can, true, sizeof can);

  scanf("%d", &n);

  for (int i = 2; i <= MAXV && n > 0; i++)
    if  (can[i]) {
      n--;
      a.pb(i);

      for (int j = i + i; j <= MAXV; j += i)
        can[j] = false;
    }

  forn(i, sz(a))
    printf("%d%c", a[i], " \n"[i == sz(a) - 1]);
  return 0;
}