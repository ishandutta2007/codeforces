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
const int INT_INF = 0x7FFFFFFE;
const i64 I64_INF = 0x7FFFFFFFFFFFFFFELL;
const double PI = acos(-1.0);
const int MOD = 1073741824;
using namespace std;

int a, b, c, res;
int p[110];

void calc(int a)
{
 int A = a;

 for (int i = 2; i * i <= A; i++)
  if  (a  % i == 0)
  {
   while (a % i == 0) a /= i, p[i]++;
  }
 p[a]++;
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  cin >> a >> b >> c;
  res = 0;
  for (int i = 1; i <= a; i++)
   for (int j = 1; j <= b; j++)
    for (int k = 1; k <= c; k++)
    {
     memset(p, 0, sizeof p);
     calc(i);
     calc(j);
     calc(k);
     int cur = 1;
     for (int z = 2; z <= 100; z++)
      cur *= p[z] + 1;
     res = (res + cur) % MOD;
    }

  cout << res << '\n';
  return 0;
}