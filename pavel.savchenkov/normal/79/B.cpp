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

int n, m, k, t;
int a[1010]; int b[1010];

string names[] = { "Carrots", "Kiwis", "Grapes" };

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n >> m >> k >> t;
  forn(i, k)
   scanf("%d%d", &a[i], &b[i]);

  forn(T, t)
  {
      int i, j; scanf("%d%d", &i, &j);
      int all = (i - 1) * m + j - 1;
      int bad = 0; bool waste = 0;

      forn(ii, k)
       if  (a[ii] < i || a[ii] == i && b[ii] < j) bad++; else
        if  (a[ii] == i && b[ii] == j) waste = 1;

      all -= bad;
      if  (waste) puts("Waste"); else printf("%s\n", names[all % 3].c_str());
  }
  return 0;
}