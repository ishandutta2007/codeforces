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

char s[MAXN];
int pow10 = 0;

bool was[300];

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  gets(s);

  memset (was, false, sizeof was);
  for (int i = 0; s[i]; i++)
    if  (s[i] == '?')
      pow10++;
    else if  ('A' <= s[i] && s[i] <= 'J')
      was[int(s[i])] = true;

  int cnt = 10; int res = 1;
  if  ('A' <= s[0] && s[0] <= 'J') {
    res = 9;
    cnt = 9;
    was[int(s[0])] = false;
  } else if  (s[0] == '?') {
    pow10--;
    res = 9;
  }

  for (char c = 'A'; c <= 'J'; c++)
    if  (was[int(c)]) {
      res *= cnt;
      cnt--;  
    }

  if  (res == 0) {
    puts("0");
    return 0;
  }

  printf("%d", res);
  forn(i, pow10)
    printf("0");
  puts("");
  return 0;
}