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

int n;
int c[100500];

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  scanf("%d", &n);

  if  (n % 2 == 0) {
    puts("-1");
    return 0;
  }

  for (int i = 0; i < n - 1; i++)
    c[i] = n - 2 - i;
  c[n - 1] = n - 1;

  forn(i, n)
    printf("%d ", i);
  puts("");

  forn(i, n)
    printf("%d ", (c[i] - i + n) % n);
  puts("");

  forn(i, n)
    printf("%d ", c[i]);
  return 0;
}