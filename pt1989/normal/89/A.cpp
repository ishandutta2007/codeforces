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

const int mxn = 10007;
int a[mxn], n, k, m;


int main(int argc, char** argv) {
	s(n); s(m); s(k);
  
  for (int i=0; i < n; i++)
    s(a[i]);
  if (n%2 == 0) {
    cout << 0 << endl;
    exit(0);
  }
  int ops = 1 + n/2;
  ll its = m / ops;
  its *= k;
  for (int i=0; i < n; i+=2)
    its = min(its, (ll)a[i]);
  cout << (its) << endl;
	return 0;
}