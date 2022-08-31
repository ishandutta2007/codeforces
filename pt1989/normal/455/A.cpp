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

#define sf(n)         scanf("%lf",&n)
#define fill(a,v)     memset(a, v, sizeof a)
#define bitcount      __builtin_popcount
#define all(x)        x.begin(), x.end()
#define pb(z)       push_back( z )
#define gcd           __gcd

bool isNum(char c) { return ('0' <= c && c <= '9'); }
template<typename T>
T read(T &res) {
  res = 0; char c, neg = 0;
  do { c=getchar(); } while (!isNum(c) && c != '-');
  if (c == '-') { neg = 1; c = getchar(); }
  while (isNum(c)) { res = res * 10 + c-'0'; c = getchar(); }
  return neg ? -res : res;
}

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

#define readInt read<int>
#define readLL read<ll>


int main() {
  int n; readInt(n);
  vector<int> a(n);
  for (int i=0; i < n; i++) readInt(a[i]);
  sort(all(a));
  vector<int> e, c;
  for (int i=0; i < n; ) {
    int j = i;
    while (j < n && a[j] == a[i]) j++;
    e.pb(a[i]);
    c.pb(j - i);
    i = j;
  }
  int m = e.size();
  vector<ll> dp(m + 1);
  for (int p=m; p >=0; --p) {
    ll &res = dp[p];
    if (p == m) {
      res = 0;
    } else {
      res = dp[p+1];
      ll nextPos = p + 1;
      if (p+1 < m && e[p+1] == e[p] + 1) {
        nextPos = p + 2;
      }
      res = max(res, e[p] * (ll)c[p] + dp[nextPos]);
    }
  }
  cout << dp[0] << endl;
}