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

double expo(double pw, int num) {
  if (num == 0) return 1;
  double res = expo(pw, num / 2);
  res = (res * res);
  if (num%2) res *= pw;
  return res;
}
int main() {
  int m, n;
  readInt(m); readInt(n);
  
  double sol = 0;
  for (int mx=1; mx <= m; mx++) {
    double actual1 = expo((mx - 1.0)/m, n);
    double actual2 = expo(mx * 1. / m, n);
    // cout << mx << " " << actual2 << " - " << actual1 << endl;
    sol += mx * (actual2 - actual1);
  }
  printf("%.10lf\n", sol);
}