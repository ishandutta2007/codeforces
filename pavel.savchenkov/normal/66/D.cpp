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
const int MAXN = int(1e6);

bool p[MAXN];
int n;
int a[60];

bool check () {
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if  (__gcd(a[i], a[j]) == 1)
        return false;

  int g = a[0];
  for (int i = 1; i < n; i++)
    g = __gcd(a[i], g);

  return g == 1;
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  memset (p, true, sizeof p);

  for (int i = 2; i < MAXN; i++)
    for (int j = i + i; j < MAXN; j += i)
      p[j] = false;

  scanf("%d", &n);
  
  if  (n == 2) {
    puts("-1");
    return 0;
  }

  a[n - 1] = 3 * 5;
  for (int i = 0; i < n - 1; i++)
    a[i] = 2;
  for (int i = 0; i < (n - 1) / 2; i++)
    a[i] *= 3;
  for (int i = (n - 1) / 2; i < n - 1; i++)
    a[i] *= 5;

  int j = 0;
  for (int i = 7; i < MAXN && j < n - 1; i++)
    if  (p[i]) {
      a[j++] *= i;
    }

  if  (!check()) {
    puts("!!!!!!!!!!!!");
  }

  forn(i, n)
    printf("%d\n", a[i]);
  return 0;
}