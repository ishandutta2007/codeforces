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
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pii pair <int,int>
#define sz(A) ((int)(A).size())
#define y1 qwertyuiopasdfghjklzxcvbnm
#define y0 ehfoiuvhefroerferjhfjkehfjke

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MAXN = (int) 1e6 + 10;

char s[MAXN];
int n;

int d[MAXN][2];

int solve(int i, bool can) {
  if  (d[i][can] != -1)
    return d[i][can];

  int j = i;
  while (j < n - 1 && s[j] == '1') j++;
  if  (s[j] != '1') j--;

  int curres = min(j - i + 1, 2);
  if  (can) curres = 1;

  if  (j == n - 1)
    return curres;


  int nj = j + 1;
  while (nj < n - 1 && s[nj] == '0') nj++;
  if  (s[nj] == '0') return curres;

  int res = MAXN;

  int sf = solve(nj, false);
  int st = solve(nj, true);

  res = min(res, curres + sf);
  if  (nj - j == 2) {
    int cur = can ? 1 : 2;
    res = min(res, cur + st);
  }

  return d[i][can] = res;
}

int main() {
  gets(s);
  n = (int)strlen(s);

  memset(d, -1, sizeof d);

  printf("%d\n", solve(0, false));
  return 0;
}