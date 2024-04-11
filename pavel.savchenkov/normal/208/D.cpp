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

int a[5];
i64 r[5];
int n;
int p[50];

int main() {
//  freopen("in.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n;
  forn(i, n) cin >> p[i];
  forn(i, 5) cin >> a[i];

  memset(r, 0, sizeof r);

  i64 b = 0;

  forn(i, n)
  {
   b += 1LL * p[i];

   ford(j, 5)
    r[j] += b / (a[j] * 1LL), b %= a[j] * 1LL;
  }

  forn(i, 5)
   cout << r[i] << ' '; puts("");
  cout << b << ' ';
  return 0;
}