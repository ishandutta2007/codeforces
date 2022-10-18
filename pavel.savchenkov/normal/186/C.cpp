#include <cstdio>
#include <iostream>
#include <cstring>
#include <memory.h>

#define forn(i, n) for (int i=0; i<(int)n; i++)

using namespace std;
const long long mod = 1000000007;

long long pow(long long a, long long p)
{
 if (p == 0) return 1;
 long long r = pow(a, p >> 1ll);
 r = (r * r) % mod;
 if (p & 1) return ( a * r ) % mod;
 return r;
}
long long n;

int main() {
// freopen("in.txt","r",stdin);
// freopen("out.txt","w",stdout);
 cin >> n;
 
 if (n == 0) cout << 1 << endl;
  else
      cout << ( pow(2ll, n - 1) + pow(2ll, n + n - 1) ) % mod << endl;
 return 0;
}