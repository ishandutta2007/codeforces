//HACK ME, PLEASE! ^_^
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

const double eps = 1e-9;
const int int_inf = 1 << 31 - 1;
const i64 i64_inf = 1ll << 63 - 1;
const double pi = acos(-1.0);

using namespace std;

int Len;
char s[100500];
char b[20][15]; int L[20];
int n;

vii g;
int mi[1005000];

int len = 0, pos = 0;

void upd(int nlen, int npos)
{
    if  (nlen <= len) return;
    len = nlen; pos = npos;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  gets(s); Len = (int)strlen(s);
  scanf("%d\n", &n);
  forn(i, n)
   gets(b[i]), L[i] = (int)strlen(b[i]);

  forn(i, n)
      for (int from = 0; s[from + L[i] - 1]; from++)
      {
          int j = 0;
          for (; j < L[i]; j++)
           if  (s[from + j] != b[i][j]) break;
          if  (j < L[i]) continue;
          g.pb(mp(from, from + L[i] - 1));
      }

  if  (g.empty()) { printf("%d 0\n", Len); return 0; }

  sort(g.begin(), g.end());
  mi[(int)g.size() - 1] = g[ (int)g.size() - 1 ].s;

  for (int i = (int)g.size() - 2; i >= 0; i--)
   mi[i] = min(g[i].s, mi[i + 1]);
  int w = 0;

  for (int i = 0; s[i]; i++)
  {
      if  (w == (int)g.size()) upd(Len - i, i); else upd(mi[w] - i, i);
      while (g[w].f < i + 1 && w < (int)g.size()) w++;
  }

  printf("%d %d\n", len, pos);
  return 0;
}