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
const int MAXN = 2 * int(1e5) + 10;

ll a[MAXN];
int n;
ll k;

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  cin >> n >> k;
  forn(i, n) scanf("%I64d", &a[i]);

  ll sum = 0; int j = 0; ll d; int N = n;
  forn(i, n) {
    d = sum - ll(j) * ll(N - (j + 1)) * a[i];

//    printf("i = %d d[i] = %I64d sum = %I64d\n", i, d, sum);

    if  (d < k) {
      printf("%d\n", i + 1);
      N--;
      continue;
    }

    sum += ll(j) * a[i];
    j++;
  }
  return 0;
}