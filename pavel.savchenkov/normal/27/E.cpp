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

const double eps = 1e-9;
const int int_inf = 2000000000;
const i64 i64_inf = 1000000000000000000LL;
const double pi = acos(-1.0);
const int mod = 1000000007;

using namespace std;
int n;
i64 res = 1000000000000000000ll;
bool prime[10000];
vi pr;

i64 binpow(i64 a, int p)
{
 i64 res = 1;
 while (p)
 {
  if (p & 1) res *= a;
  a *= a; p = p >> 1;
 }
 return res;
}

void go(int a, i64 mul, int len)
{
// cout << a << " " << mul << " " << len << endl;
 if (mul >= res || mul <= 0) return;
 if (a == 1) { res = min(res, mul); return; }
 for (int i=1; i*i<=a; i++)
 if (a % i == 0)  
 {
   if (i != 1) go(a / i, mul * binpow(pr[len],i - 1), len + 1);
   if (a / i != i) go(i, mul * binpow(pr[len],a / i - 1), len + 1);
 }
}

int main() {
  cin >> n;
  memset(prime,1,sizeof(prime));
  for (int i = 2; i < 1e4; i++)
   if (prime[i]) 
   {
    for (int j=2; i*j < 1e4; j++)
     prime[i*j] = 0;
    pr.pb(i);
    if ((int)pr.size() > 1000) break;
   }

  go(n,1ll,0);
  
  cout << res << endl;
  return 0;
}