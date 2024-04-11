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
#define i64 long long
#define ui64 unsigned long long
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
const int INT_INF = 0x7FFFFFFF;
const i64 I64_INF = 0x7FFFFFFFFFFFFFFF;
const double PI = acos(-1.0);

using namespace std;

int d[52][4][13][4][13][4][13];

char M[4] = {'S', 'D', 'H', 'C' };
char C[13] = { '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A' };

int n;
pii s[60];

bool calc(int i, int m1, int c1, int m2, int c2, int m3, int c3)
{
  if  (i == 0) return d[i][m1][c1][m2][c2][m3][c3] = 1;
  if  (i == 1) return d[i][m1][c1][m2][c2][m3][c3] = (m1 == m2 || c1 == c2);
  if  (i == 2) return d[i][m1][c1][m2][c2][m3][c3] = ((m1 == m2 || c1 == c2) && (m1 == m3 || c1 == c3));

  if  (d[i][m1][c1][m2][c2][m3][c3] != -1) return d[i][m1][c1][m2][c2][m3][c3];
  d[i][m1][c1][m2][c2][m3][c3] = 0;

  if  (m1 == s[i - 3].f || c1 == s[i - 3].s)
    d[i][m1][c1][m2][c2][m3][c3] |= calc(i - 1, m2, c2, m3, c3, m1, c1);

  if  (m1 == m2 || c1 == c2) 
   d[i][m1][c1][m2][c2][m3][c3] |= calc(i - 1, m1, c1, m3, c3, s[i - 3].f, s[i - 3].s);

  return d[i][m1][c1][m2][c2][m3][c3];
}

int main() {
//  freopen("in.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  memset(d, -1, sizeof d);
  scanf("%d\n", &n);
  forn(i, n)
  {
   char c = getchar();
   forn(j, 13)
    if  (c == C[j]) s[i].s = j;

   char m = getchar();
   forn(j, 4)
    if  (m == M[j]) s[i].f = j;
   getchar();
  }

 // printf("%d %d\n", s[0].f, s[1].f);

  if  (n == 1) 
   puts("YES");
  else
  if  (n == 2)
   puts(s[0].f == s[1].f || s[0].s == s[1].s ? "YES" : "NO");
  else
   puts(calc(n - 1, s[n - 1].f, s[n - 1].s, s[n - 2].f, s[n - 2].s, s[n - 3].f, s[n - 3].s) ? "YES" : "NO");

  return 0;
}