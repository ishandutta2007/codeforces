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

int gcd(int a, int b) { return (b) ? gcd(b, a % b) : a; }

int get(int n, int a)
{
   int sum = 0;
   while (n)
   {
       sum += n % a;
       n /= a;
   }
   return sum + n;
}

int a;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> a;
  int x = 0; int y = a - 2;
  for (int i = 2; i <= a - 1; i++)
   x += get(a, i);

  int g = gcd(x, y);
  x /= g; y /= g;
  printf("%d/%d\n", x, y);
  return 0;
}