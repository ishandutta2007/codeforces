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

int n;
bool a[100500];

void go(int from, int d)
{
  if  (n / d < 3) return;
  for (int i = from; i < n; i += d)
   if  (!a[i]) return;

  puts("YES"); exit(0);
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n;
  forn(i, n)
  {
      int c; scanf("%d", &c); a[i] = c;
  }

  for (int i = 1; i * i <= n; i++)
   if  (n % i == 0)
   {
    for (int start = 0; start < i; start++)
     go(start, i);
    for (int start = 0; start < n / i; start++)
     go(start, n / i);
   }

  puts("NO");
  return 0;
}