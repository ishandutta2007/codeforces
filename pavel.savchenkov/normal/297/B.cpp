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
const int MAXN = int(1e5) + 10;

int n, m, k;
int a[MAXN];
int b[MAXN];

int main() {;
  scanf("%d %d %d", &n, &m, &k);

  forn(i, n) {
    scanf("%d", &a[i]);
    a[i] = -a[i];
  }

  forn(i, m) {
    scanf("%d", &b[i]);
    b[i] = -b[i];
  }

  sort(a, a + n);
  sort(b, b + m);
  
  forn(i, min(n, m))
    if  (-a[i] > -b[i]) {
      puts("YES");
      return 0; 
    }
    
  puts(n > m ? "YES" : "NO");
  return 0;
}