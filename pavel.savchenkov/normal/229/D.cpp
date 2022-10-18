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
const int INT_INF = (int)1e9;
const i64 I64_INF = 0x7FFFFFFFFFFFFFFELL;
const double PI = acos(-1.0);

using namespace std;

int n;
int d[5010][5010];
int sum[5010];

int getsum(int l, int r)
{
    return sum[r + 1] - sum[l];
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  cin >> n;
  sum[0] = 0;
  forn(i, n)  { int a; scanf("%d", &a), sum[i + 1] = sum[i] + a; }

  forn(i, n)
   forn(j, i + 1)
    d[i][j] = INT_INF;

  int res = INT_INF;
  forn(i, n)
   ford(j, i + 1)
   {
       if  (j != i) d[i][j] = d[i][j + 1];

       if  (j == 0)
        d[i][j] = min(d[i][j], i);
       else
        if  (getsum(0, j - 1) <= getsum(j, i)) d[i][j] = min(d[i][j], d[j - 1][0] + i - j);
       else
        if  (getsum(j - 1, j - 1) <= getsum(j, i))
        {
            int L = 0; int R = j;
            while (L != R - 1)
            {
                int M = (L + R) / 2;
                if  (getsum(M, j - 1) <= getsum(j, i)) R = M; else L = M;
            }
            int pos = L + 1;
            d[i][j] = min(d[i][j], d[j - 1][pos] + i - j);
        }

       if  (i == n - 1) res = min(res, d[i][j]);
   }

  printf("%d\n", res);
  return 0;
}