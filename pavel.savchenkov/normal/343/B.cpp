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
const int MAXN = int(1e5) + 10;

char a[MAXN];
int cnt[MAXN];
int sz = 0;

int main() {
  char c;

  while (scanf("%c", &c) >= 1 && (c == '+' || c == '-')) {
    if  (sz == 0) {
      a[sz++] = c;
      cnt[0] = 1;
      continue;
    }

    if  (c != a[sz - 1]) {
      if  (cnt[sz - 1] % 2 == 0) {
        while (sz > 0 && a[sz - 1] != c) sz--;
      }

      cnt[sz] = (sz > 0 && a[sz - 1] == c) ? cnt[sz - 1] + 1 : 1;
    }
    else
      cnt[sz] = cnt[sz - 1] + 1;

    a[sz++] = c;
  }

  puts(cnt[sz - 1] % 2 == 1 || cnt[sz - 1] != sz ? "No" : "Yes");
  return 0;
}