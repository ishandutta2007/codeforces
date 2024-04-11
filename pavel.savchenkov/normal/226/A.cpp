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

i64 MOD;

i64 pow( int n )
{
    if  (n == 0) return 1LL % MOD;
    if  (n == 1) return 3LL % MOD;
    i64 res = pow(n / 2);
    res = (res * res) % MOD;

    if  (n & 1) return (res * 3LL) % MOD; else
     return res % MOD;
}

int n;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n >> MOD;

  i64 res = pow(n);
  cout << ((res - 1LL + MOD) % MOD) << '\n';
  return 0;
}