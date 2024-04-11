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
const int INT_INF = 2*(int)1e9;
const i64 I64_INF = (i64)1e18;
const double PI = acos(-1.0);

using namespace std;

bool p[(int)1e6 + 100];
int a, b, k;
int sum[(int)1e6 + 100];

bool check(int l) {
 for (int x = a; x <= b - l + 1; x++)
  if  (sum[x + l - 1] - sum[x - 1] < k) return 0;
 return 1;
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  memset(p, 1, sizeof p);
  cin >> a >> b >> k;
  p[1] = 0;
  for (int i = 2; i <= b; i++)
   if  (p[i]) {
    for (int j = 2*i; j <= b; j += i)
     p[j] = 0;
   }

  sum[0] = 0;
  for (int i = 1; i <= b; i++)
   sum[i] = sum[i - 1] + p[i];

  int L = 1; int R = b - a + 2;
  while (L != R - 1) {
   int M = (L + R) / 2;
   if  (!check(M)) L = M; else R = M;
  }

  if  (!check(L)) L++;

  if  (check(L) && L <= b - a + 1) printf("%d\n", L); else puts("-1"); 
  return 0;
}