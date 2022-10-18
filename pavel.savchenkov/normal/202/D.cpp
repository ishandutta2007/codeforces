#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <utility>
#include <math.h>
#include <cstdlib>
#include <memory.h>
#include <queue>
#include <assert.h>

#define pb push_back
#define i64 long long
#define mp make_pair
#define pii pair <int,int>
#define vi vector <int>
#define vii vector <pii>
#define f first
#define s second
#define foran(i,a,b) for (int i=a;i<(int)b;i++)
#define forn(i,n) for (int i=0;i<(int)n;i++)
#define ford(i,n) for (int i=(int)n-1;i>=0;i--)
#define sqr(x) (x) * (x)
#define y1 fucking_y1

const double EPS = 1e-9;
const int INT_INF = 1 << 31 - 1;
const i64 I64_INF = 1ll << 63 - 1ll;
const double PI = acos(-1.0);

using namespace std;

int n, m;
int c[1000][1000];

int X = 0, Y = 0;
i64 answer = I64_INF;

void upd(int x, int y, i64 nanswer)
{
  if  (nanswer < answer) { X = x; Y = y; answer = nanswer; }
  if  (answer != nanswer) return;
  if  (x < X) { X = x; Y = y; answer = nanswer; }
  if  (x != X) return;
  if  (y < Y) { X = x; Y = y;  answer = nanswer; }
}

i64 str[1001];
i64 stb[1001];

i64 sumstr[1000];
i64 sumstb[1000];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  scanf("%d%d", &n, &m);
  memset(str, 0, sizeof str);
  memset(stb, 0, sizeof stb);
  memset(sumstr, 0, sizeof sumstr);
  memset(sumstb, 0, sizeof sumstb);

  forn(i, n)
   forn(j, m)
   {
    scanf("%d", &c[i][j]);
    sumstr[i] += c[i][j] * 1LL;
    sumstb[j] += c[i][j] * 1LL;
   }

  forn(i, n + 1)
   forn(j, n)
   {
       i64 dist = (i <= j) ? 4ll * (j - i) + 2ll : 4ll * (i - j) - 2ll;
       str[i] += sumstr[j] * sqr(dist);
   }

  forn(i, m + 1)
   forn(j, m)
   {
       i64 dist = (i <= j) ? 4ll * (j - i) + 2ll : 4ll * (i - j) - 2ll;
       stb[i] += sumstb[j] * sqr(dist);
   }

  forn(i, n + 1)
   forn(j, m + 1)
    upd(i, j, str[i] + stb[j]);

  printf("%I64d\n%d %d", answer, X, Y);
  return 0;
}