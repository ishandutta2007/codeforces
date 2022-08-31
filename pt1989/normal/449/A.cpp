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

typedef pair<int, int> pii;

ll solve(int n, int m, int k, int parts) {
  int cuts = parts - 1;
  int extraCuts = k - cuts;
  
  if (extraCuts < 0 || extraCuts >= m) 
    return 0;
  ll minSize = n / parts;
  ll minSize2 = m / (extraCuts + 1);
  return minSize * minSize2;
}


int main() {
  int n, m, k;
  readInt(n); readInt(m); readInt(k);
  
  int maxCuts = n - 1 + m - 1;
  ll ans = 0;
  if (k > maxCuts) {
    puts("-1");
  } else {
    for (int p=1; p*p <= n; p++) {
      ans = max(ans, solve(n, m, k, p));
      ans = max(ans, solve(n, m, k, n/p));
    }
    for (int p=1; p*p <= m; p++) {
      ans = max(ans, solve(m, n, k, p));
      ans = max(ans, solve(m, n, k, m/p));
    }
    cout << ans << endl;
  }
}