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
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;

const double EPS = 1e-9;
const int MAXN = int(1e6) + 10;

int dp[MAXN];
int n;

int main() {
  scanf("%d\n", &n);

  dp[0] = 0;

  for (int i = 1; i <= n; i++) {
    dp[i] = int(1e9);

    int tmp = i;
    while (tmp > 0) {
      int c = tmp % 10;

      if  (i - c >= 0 && dp[i - c] + 1 < dp[i])
        dp[i] = dp[i - c] + 1;

      tmp /= 10;
    }
  }

  printf("%d\n", dp[n]);

  return 0;
}