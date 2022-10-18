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

int n;
int cnt[10];
vector <pii> res;

bool solve () {
  if  (cnt[1] != n / 3)
    return false;

  if  (cnt[7])
    return false;

  if  (cnt[5])
    return false;

  if  (cnt[4] <= cnt[2]) {
    forn(i, cnt[4])
      res.pb(mp(2, 4));
    cnt[2] -= cnt[4];
  } else
    return false;

  if  (cnt[3] <= cnt[6]) {
    forn(i, cnt[3])
      res.pb(mp(3, 6));
    cnt[6] -= cnt[3];
  } else
    return false;

  if  (cnt[6] == cnt[2]) {
    forn(i, cnt[6])
      res.pb(mp(2, 6));
  } else
    return false;

  return true;
}

int main() { 
  scanf("%d", &n);

  memset (cnt, 0, sizeof cnt);

  forn(i, n) {
    int a;
    scanf("%d", &a);
    cnt[a]++;
  }

  if  (solve())
    forn(i, n / 3)
      printf("1 %d %d\n", res[i].f, res[i].s);
  else
    puts("-1");
  return 0;
}