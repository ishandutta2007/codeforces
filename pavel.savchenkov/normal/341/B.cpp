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
const int INF = int(1e9);

int a[MAXN];
int dp[MAXN];
int n;

int main() {
  scanf("%d", &n);

  forn(i, n) {
    scanf("%d", &a[i]);
    a[i]--;
  }

  dp[0] = -1;
  for (int i = 1; i <= n; i++)
    dp[i] = INF;

  forn(i, n) {
    int pos = upper_bound(dp, dp + n + 1, a[i]) - dp;

    if  (dp[pos - 1] < INF && a[i] < dp[pos])
      dp[pos] = a[i];
  }

  ford(i, n + 1)
    if  (dp[i] < INF) {
      printf("%d\n", i);
      return 0;
    }

  return 0;
}