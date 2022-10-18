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

#define pb push_back
#define LL long long
#define uLL unsigned long long
#define mp make_pair
#define pii pair <int,int>
#define vi vector <int>
#define vii vector <pii>
#define f first
#define s second
#define foran(i,a,b) for (int i=a;i<(int)b;i++)
#define forn(i,n) for (int i=0;i<(int)n;i++)
#define ford(i,n) for (int i=(int)n-1;i>=0;i--)
#define sqr(x) ((x) * (x))
#define sz(A) ((int)(A).size())
#define y1 asxfdsfs
#define y0 dsfgdfggdf


const double EPS = 1e-9;
const int INT_INF = 2 * (int)1e9;
const LL LL_INF = 8 * (LL)1e18;
const double PI = acos(-1.0);

using namespace std;

int k, m;
int a[110];
int n;
int b[110][110];
int d[110];
bool was[110];
bool good[110];
int cnt0[110];

int MakeGood(int i) {
    int cntgood = 0;
    memset(was, 0, sizeof was);
    forn(j, d[i]) {
        if  (b[i][j] >= 0 && good[ b[i][j] ]) cntgood++;
        if  (b[i][j] >= 0) was[ b[i][j] ] = 1;
    }

    int cntadd = 0;
    forn(j, k)
        if  (!was[ a[j] ] && cntadd < cnt0[i])
            cntadd++, cntgood++;
    return cntgood;
}

int MakeBad(int i) {
    int cntgood = 0;
    memset(was, 0, sizeof was);
    forn(j, d[i]) {
        if  (b[i][j] >= 0 && good[ b[i][j] ]) cntgood++;
        if  (b[i][j] >= 0) was[ b[i][j] ] = 1;
    }

    int cntadd = 0;
    forn(j, m)
        if  (!good[j] && !was[j] && cntadd < cnt0[i])
            cntadd++;

    return cntgood + cnt0[i] - cntadd;
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> m >> k;
  memset(good, 0, sizeof good);
  forn(i, k) scanf("%d", a + i), good[--a[i]] = 1;
  scanf("%d\n", &n);

  forn(i, n) {
    char c = getchar();
    while (c != '\n') c = getchar();

    scanf("%d", &d[i]);
    cnt0[i] = 0;
    forn(j, d[i]) {
        scanf("%d", &b[i][j]); b[i][j]--;
        if  (b[i][j] == -1) cnt0[i]++;
    }
    scanf("\n");
  }

  forn(i, n) {
      int cur = MakeGood(i);
      int ma = -1;
      forn(j, n)
        if  (j != i) ma = max(ma, MakeBad(j));
      bool can1 = 0;
      if  (ma <= cur) can1 = 1;

      cur = MakeBad(i);
      ma = -1;
      forn(j, n)
        if  (j != i) ma = max(ma, MakeGood(j));
      bool can2 = 0;
      if  (ma > cur) can2 = 1;
/*
      printf("%d ->\n", i);
      printf("%d %d %d\n", MakeGood(i), MakeBad(i), ma);

      forn(j, d[i])
        printf("%d ", b[i][j]);
    puts("");
*/
      if  (can1 && can2)
        puts("2");
      else if  (can1)
        puts("0");
      else
        puts("1");
  }

  return 0;
}