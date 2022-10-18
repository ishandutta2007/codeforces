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
#define y1 asxfdsfsdsjhfgidf
#define y0 dsfgdfggdfjdhriwurehiw

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1e9 + 7;
const int P = 29;

using namespace std;

char s[5010];
bool p[5010][5010];
int n;

int d[5010][5010];


int main() {
 // freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  gets(s);
  n = (int)strlen(s);

  for (int len = 1; len <= n; len++)
    for (int l = 0; l <= n - len; l++) {
        int r = l + len - 1;
        if  (l == r)
            p[l][r] = 1;
        else if  (l == r - 1)
            p[l][r] = (s[l] == s[r]);
        else
            p[l][r] = p[l + 1][r - 1] && (s[l] == s[r]);
    }

  for (int len = 1; len <= n; len++)
    for (int l = 0; l <= n - len; l++) {
        int r = l + len - 1;
        if  (l == r)
            d[l][r] = 1;
        else if  (l == r - 1)
            d[l][r] = (s[l] == s[r]) + 2;
        else
            d[l][r] = d[l + 1][r] + d[l][r - 1] - d[l + 1][r - 1] + p[l][r];
    }
/*
  forn(i, n) {
    cnt_end[i] = 0;
    for (int l = 0; l <= i; l++)
        cnt_end[i] += p[l][i];
  }

  forn(i, n) {
    cnt_start[i] = 0;
    for (int r = n - 1; r >= i; r--)
        cnt_start[i] += p[i][r];
  }

  forn(i, n) {
    cnt_inter[i] = 0;
    if  (i > 0)
        cnt_inter[i] = cnt_inter[i - 1] - cnt_end[i] + 1;
    cnt_inter[i] += cnt_start[i] - 1;
  }

  memset(cnt_all, 0, sizeof cnt_all);
  forn(i, n) {
    if  (i > 0)
        cnt_all[i] = cnt_all[i - 1];
    cnt_all[i] += cnt_end[i];
  }
*/

  int q; cin >> q;
  forn(i, q) {
    int l, r; scanf("%d%d", &l, &r);
  //  l = rand() % n;
  //  r = rand() % (n - l);
  //  r += l;

    l--; r--;
   // printf("(%d; %d)\n", l, r);
   // printf("brut = %d\n", brut(l, r));
    printf("%d\n", d[l][r]);
    continue;

  }


  return 0;
}