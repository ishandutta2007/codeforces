#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex> 
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;


#define s(n)          scanf("%d",&n)
#define sf(n)         scanf("%lf",&n)
#define fill(a,v)     memset(a, v, sizeof a)
#define bitcount      __builtin_popcount
#define all(x)        x.begin(), x.end()
#define pb(z)       push_back( z )
#define gcd           __gcd

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

int n;
ld p[111];
ld pre[111], post[111];
int main() {
  cin>>n;
  for (int i=0; i < n; i++) {
    cin >> p[i];
  }
  sort(p, p+n);
  ld best = p[n-1];
  for (int lo=0; lo < n; lo++) {
    for (int hi=lo; hi < n; hi++) {
      pre[lo-1] = 1;
      for (int i=lo; i <= hi; i++) {
        pre[i] = pre[i-1] * (1 - p[i]);
      }
      post[hi+1] = 1;
      for (int i=hi; i >= lo; i--)
        post[i] = post[i+1] * (1 - p[i]);
      ld cur = 0;
      for (int i=lo; i <= hi; i++) {
        cur += p[i] * pre[i-1] * post[i+1];
      }
      best = max(best, cur);
    }
  }
  
  printf("%.14f\n", (double)best);
}