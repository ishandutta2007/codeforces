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
#define all(A) A.begin(), A.end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;

const double EPS = 1e-9;
const int MAXN = 510;

int a[MAXN];
int n, x;

int mid (int N) {
  return (N + 1) / 2 - 1;
}

int main() {
  scanf("%d%d", &n, &x);

  forn(i, n)
    scanf("%d", &a[i]);

  sort(a, a + n);

  bool was = false;
  forn(i, n)
    if  (a[i] == x) {
      was = true;
    }

  int res = 0;

  if  (!was) {
    a[n++] = x;
    sort(a, a + n);
    res = 1;
  }

  if  (a[mid(n)] > x) {
    int k = 0;
    while (a[mid(n + k) - k] != x) k++;
    res += k;
  } else if  (a[mid(n)] < x) {
    int k = 0;
    while (a[mid(n + k)] != x) k++;
    res += k;
  }

  printf("%d\n", res);
  return 0;
}