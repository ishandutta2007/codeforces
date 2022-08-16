#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<bitset>
#include<complex>
 
#include<sstream>
#include<fstream>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<climits>
 
#define oo            (int)13e7
#define s(n)          scanf("%d",&n)
#define sl(n)         scanf("%lld",&n)
#define sf(n)         scanf("%lf",&n)
#define fill(a,v)     memset(a, v, sizeof a)
#define ull           unsigned long long
#define ll            long long
#define bitcount      __builtin_popcount
#define all(x)        x.begin(), x.end()
#define pb( z )       push_back( z )
#define gcd           __gcd
using namespace std;
int n, m, h;
const int mxm = 1024;
int a[mxm];
const int mxn = 100007;
bool sv[mxn];

int f(int n, int p) {
  int ret = 0;
  for (ll x=p; x <= n; x *= p) {
    ret += n/x;
  }
  return ret;
}

int main(int argc, char** argv) {
  vector<int> primes;
  for (int i=2; i < mxn; i++) 
  if (!sv[i]) {
    for (int j=2*i; j < mxn; j += i)
      sv[j] = 1;
    primes.pb( i );
  }
  
	cin>>n>>m>>h;
  int sum = 0;
  for (int i=1; i <= m; i++) {
    cin>>a[i];
    sum += a[i];
  }
  sum--; a[h]--; n--;
  if (sum < n) {
    printf("-1.0\n"); exit(0);
  } else {
    //cout << a[h] << " " << sum << " can pick " << n << endl;
    //Numerator = C[sum-a[h]][n]
    //Total ways = C[sum][n]
    //Prob = NUm / Total ways
    double prob = 0;
    if (a[h] == 0) {
      prob = 1;
    } else if (sum-a[h] >= n) {
      prob = 1.0;
      for (int i=0; i < primes.size(); i++) {
        int p = primes[i];
        int power = f( sum - a[h], p ) - f( sum - a[h] - n, p ); // - f(n, p)
        power -= f(sum, p) -  f(sum - n, p); // - f(n, p)
        prob *= pow( p, power );
      }
    }
    printf("%.10lf\n", 1 - prob);
  }
	return 0;
}