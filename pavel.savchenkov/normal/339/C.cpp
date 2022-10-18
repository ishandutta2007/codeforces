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
const int MAXN = 1010;

bool dp[15][15][MAXN];
int m;
bool a[15];
char s[15];
vi res;

void restore (int last, int diff, int i) {
  if  (i == 0)
    return;

  for (int plast = 0; plast <= 10; plast++)
    for (int pdiff = 0; pdiff <= 10; pdiff++)
        if  (dp[plast][pdiff][i - 1]) {
          if  (a[last - 1] && plast != last && last > pdiff) {
            if  (last - pdiff == diff) {
              res.pb(last);

              restore(plast, pdiff, i - 1);

              return;
            } 
          }
        }  
}

int main() {
  gets(s);
  scanf("%d", &m);

  forn(i, 10)
    a[i] = (s[i] == '1');

  memset (dp, false, sizeof dp);

  dp[0][0][0] = true;

  for (int i = 0; i < m; i++)
    for (int last = 0; last <= 10; last++)
      for (int diff = 0; diff <= 10; diff++)
        if  (dp[last][diff][i]) {
          for (int next = 1; next <= 10; next++)
            if  (a[next - 1] && last != next && next > diff) {
              dp[next][next - diff][i + 1] = true;    
            }
        }

  for (int last = 1; last <= 10; last++)
    for (int diff = 1; diff <= 10; diff++)
      if  (dp[last][diff][m]) {
        restore(last, diff, m);

        puts("YES");

        ford(i, sz(res))
          printf("%d ", res[i]);

        return 0;
      }

  puts("NO");
  return 0;
}