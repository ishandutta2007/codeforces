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
const int MAXN = 110;

int a[MAXN];
int n;
bool used[MAXN];

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  scanf("%d", &n);
  forn(i, n) scanf("%d", &a[i]);

  memset (used, false, sizeof used);

  forn(i, n)
    if  (a[i] < 0) {
      printf("1 %d\n", a[i]);
      used[i] = true;
      break;
    }

  bool was = false;
  int n2 = 0;
  forn(i, n)
    if  (a[i] > 0) {
      printf("1 %d\n", a[i]);
      used[i] = true;
      was = true;
      n2 = 1;
      break;
    }

  if  (!was) {
    forn(i, n)
      foran(j, i + 1, n)
        if  (!was && !used[i] && !used[j] && a[i] * a[j] > 0) {
          printf("2 %d %d\n", a[i], a[j]);
          used[i] = true;
          used[j] = true;
          n2 = 2;
          was = true;
        } 
  }

  printf("%d ", n - 1 - n2);
  forn(i, n)
    if  (!used[i])
      printf("%d ", a[i]);
  puts("");
  return 0;
}