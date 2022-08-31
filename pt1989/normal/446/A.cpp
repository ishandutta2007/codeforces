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
T read() {
  T res = 0; char c, neg = 0;
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

const int MXN = 200 + (int)1e5;
int a[MXN], n;
int incr[MXN];
int decr[MXN];

int main() {
  n = readInt();
  for (int i=0; i < n; i++) a[i] = readInt();
  int sol = n == 1 ? 1 : 2;
  for (int i=n-1; i >= 0; i--) {
    incr[i] = 1;
    if (i+1 < n && a[i] < a[i+1])
      incr[i] = 1 + incr[i+1];
    else
      sol = max(sol, 1 + incr[i+1]);
    // cout << incr[i] << " " ;
    sol = max(sol, incr[i]);
  } // cout << endl;
  
  for (int i=0; i < n; i++) {
    decr[i] = 1;
    if (i-1 >= 0 && a[i-1] < a[i])
      decr[i] = 1 + decr[i-1];
    else 
      sol = max(sol, 1 + decr[i-1]);
    // cout << decr[i] << " ";
  } // cout << endl;
  
  for (int i=1; i+1 < n; i++) {
    if (a[i-1] + 1 < a[i+1])
      sol = max(sol, decr[i-1] + incr[i+1] + 1);
    
    if (a[i-1] < a[i+1] - 1) {
      sol = max(sol, decr[i-1] + incr[i+1] + 1);
    }
  }
  cout << sol << endl;
}