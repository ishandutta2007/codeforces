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
 
int n, r, c, logR;
string s[MAXN];
int sum[MAXN];

int dp[MAXN][23];
int len[MAXN][23];

int get_sum (int l, int r) {
  return sum[r + 1] - sum[l];
}

int get_pos (int i) {
  if  (get_sum(i, i) > c)
    return -1;

  int L = i; int R = n;

  while (L != R - 1) {
    int M = (L + R) / 2;
    if  (get_sum(i, M) + M - i <= c)
      L = M;
    else
      R = M;
  }

  return L;
}

void precalc () {
  logR = 1;
  while ((1 << logR) <= r) logR++;
  logR--;

  memset (dp, -1, sizeof dp);
  memset (len, -1, sizeof len);

  forn(i, n)
    dp[i][0] = get_pos(i);

  for (int p = 1; p <= logR; p++)
    for (int i = 0; i < n; i++) {
      int j = dp[i][p - 1] + 1;
      if  (j >= n || j <= 0)
        continue;

      if  (dp[j][p - 1] != -1)
        dp[i][p] = dp[j][p - 1];
    }
}

int get_len (int i, int need, int p) {
  if  (need == 0)
    return 0;

  while (p >= 0 && ((1 << p) > need || dp[i][p] == -1)) p--;

  if  (p == -1 || dp[i][p] == -1)
    return 0;

  return (dp[i][p] - i + 1) + get_len(dp[i][p] + 1, need - (1 << p), p); 
}

void build (int i, int str) {
  if  (str == r || dp[i][0] == -1)
    return;

  for (int j = i; j <= dp[i][0]; j++) {
    printf("%s", s[j].c_str());
    if  (j == dp[i][0])
      puts("");
    else
      printf(" ");
  }

  build(dp[i][0] + 1, str + 1);
}


void read (int i) {
  char C;
  while (1) {
    C = getchar();
    if  (C != ' ') {
      s[i] += C;
      break;
    }
  }

  while (scanf("%c", &C) >= 1 && C >= 'a' && C <= 'z') {
    s[i] += C;
  }
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  scanf("%d %d %d\n", &n, &r, &c);

  sum[0] = 0;
  forn(i, n) {
    read(i);
    sum[i + 1] = sum[i] + int(s[i].length());
  }

  precalc();

  int pos_ans = -1;
  int ans = 0;
  forn(i, n) {
    int cur = get_len(i, r, 22);
    if  (cur > ans) {
      ans = cur;
      pos_ans = i;
    }
  }

  build(pos_ans, 0);
  return 0;
}