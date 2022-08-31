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
#define sf(n)         scanf("%lf",&n)
#define fill(a,v)     memset(a, v, sizeof a)
#define ull           unsigned long long
#define ll            long long
#define bitcount      __builtin_popcount
#define all(x)        x.begin(), x.end()
#define pb( z )       push_back( z )
#define gcd           __gcd
using namespace std;

int x[111], y[111];
int n;
int p[111];
int find(int x) {
  if (x == p[x])
    return x;
  return p[x] = find(p[x]);
}
int main(int argc, char** argv) {
  s(n);
  for (int i=0; i < n; i++) {
    s(x[i]); s(y[i]);
    p[i] = i;
  }
  for (int i=0; i < n; i++)
  for (int j=0; j < n; j++)
  if (x[i] == x[j] || y[i] == y[j]) {
    int p1 = find(i);
    int p2 = find(j);
    p[p1] = p2;
  }
  set<int> comps;
  for (int i=0; i < n; i++)
    comps.insert(find(i));
  cout << comps.size() - 1 << endl;
	return 0;
}