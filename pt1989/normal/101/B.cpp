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

int n, m;
const int mxn = 100007;
const int mod = 1000000007;

pair<int, int> p[mxn];

int ways[mxn];
pair<int, int> seg[mxn];
#define start second
#define end first

int bit[2*mxn];
int A[2*mxn];
int modAdd(int f, int v) {
  int r = f+v;
  if (r >= mod) r -= mod;
  return r;
}

void add(int x, int v) {
  x++;
  while (x < 2*mxn) {
    //cout << x << " adding" << endl;
    bit[x] = modAdd(bit[x], v);
    x += x&-x;
  }
}
int count(int x) {
  x++;
  int r = 0;
  while (x > 0) {
    //cout << x << " counting" << endl;
    r = modAdd(r, bit[x]);
    x -= x&-x;
  }
  return r;
}

int main(int argc, char** argv) {
	s(n); s(m);
  int sz = 0;
  for (int i=0; i < m; i++) {
    s(seg[i].start); s(seg[i].end);
    A[sz++] = seg[i].start; A[sz++] = seg[i].end;
  }
  sort(seg, seg+m);
  sort(A, A+sz); sz = unique(A, A+sz) - A;
  
  int ans = 0;
  for (int i=m-1; i >= 0; i--) {
    ways[i] = 0;
    if (seg[i].end == n)
      ways[i] = 1;
    
    int p = lower_bound(A, A+sz, seg[i].end) - A;
    ways[i] = modAdd(ways[i], count(p));
    if (i-1 < 0 || seg[i-1].end != seg[i].end) {
      int j = i;
      while (j < m && seg[j].end == seg[i].end) {
        add(lower_bound(A, A+sz, seg[j].start) - A, ways[i]);
        j++;
      }
    }
    if (seg[i].start == 0) {
      ans = modAdd(ans, ways[i]);
    }
  }
  cout << ans << endl;
	return 0;
}