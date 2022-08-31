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
typedef pair<int, int> pii;

#define readInt read<int>
#define readLL read<ll>
int n;
vector<pii> a;
const int LIM = 60; // all bi < 60
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
int PSZ = 17;
int mask[64];
int dp[101][1<<17];
int ptr[101][1<<17];
int solve(int pos, int used) {
  if (pos == (int)a.size())
    return 0;
  int &res = dp[pos][used];
  if (~res) return res;
  int v = a[pos].first;
  res = (int)2e9;
  for (int i=1; i <= 2*v - 1; i++) {
    if ((used & mask[i]) == 0) {
      int cur = abs(i - v) + solve(pos + 1, used | mask[i]);
      if (cur < res) {
        res = cur;
        ptr[pos][used] = i;
      }
    }
  }
  return res;
}
int main() {
  for (int i=2; i <= LIM; i++) {
    for (int p=0; p < PSZ; p++) if (i%primes[p] == 0) {
      mask[i] |= 1<<p;
    }
  }
  
  readInt(n);
  for (int i=0; i < n; i++) {
    int x; readInt(x);
    a.pb(make_pair(x, i));
  }
  fill(dp, -1);
  solve(0, 0);
  int i = 0, stateMask = 0;
  while (i < n) {
    cout << ptr[i][stateMask];
    if (i == n-1) {
      cout << endl;
    } else {
      cout << " ";
    }
    stateMask |= mask[ ptr[i][stateMask] ];
    i ++; 
  }
}