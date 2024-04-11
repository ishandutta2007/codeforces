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

int c[2][2];
int n;

char s[2 * MAXN];
char t[2 * MAXN];

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  memset (c, 0, sizeof c);

  scanf("%d\n", &n);
  gets(s);
  gets(t);

  forn(i, n+n)
    c[s[i] - '0'][t[i] - '0']++;

  int c1 = 0, c2 = 0;
  forn(i, n) {
    if  (c[1][1] > 0) {
      c1++;
      c[1][1]--;
    } else if  (c[1][0] > 0) {
      c[1][0]--;
      c1++;
    } else if  (c[0][1] > 0) {
      c[0][1]--;
    } else c[0][0]--;

    if  (c[1][1] > 0) {
      c2++;
      c[1][1]--;
    } else if  (c[0][1] > 0) {
      c[0][1]--;
      c2++;
    } else if  (c[1][0] > 0) {
      c[1][0]--;
    } else c[0][0]--;
  }

  if  (c1 == c2)
    puts("Draw");
  else if  (c1 > c2)
    puts("First");
  else
    puts("Second");

//  printf("%d %d\n", c1, c2);
  return 0;
}