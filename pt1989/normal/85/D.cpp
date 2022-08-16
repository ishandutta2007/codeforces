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

const int mxn = 100007;
int n;
char com[mxn][8];
int val[mxn];
int elems[mxn];
int esz;

//index to seg tree node
int mp[mxn];
int exists[mxn];
int cdp[mxn*4];
ll ddp[mxn*4][5];
void init() {
  fill(cdp, -1);
  fill(ddp, -1);
  fill(exists, 0);
}
void create(int node, int lo, int hi) {
  if (lo == hi) {
    mp[lo] = node;
    return;
  }
  int mid = (lo+hi)>>1;
  create(node*2, lo, mid);
  create(node*2 + 1, mid+1, hi);
}

int treeCount(int node, int lo, int hi) {
  if (lo == hi) {
    return exists[lo];
  }
  int &ret = cdp[node];
  if (ret != -1) {
    return ret;
  }
  int mid = (lo+hi)>>1;
  ret = 
    treeCount(node*2, lo, mid) +
    treeCount(node*2+1, mid+1, hi);
  return ret;
}
ll sum(int node, int lo, int hi, int mod) {
  if (lo == hi) {
    if (mod == 3 && exists[lo]) {
      return elems[lo];
    }
    return 0;
  }
  ll &ret = ddp[node][mod];
  if (ret != -1) {
    return ret;
  }
  int mid = (lo+hi)>>1;
  int lcount = treeCount(node*2, lo, mid);
  
  ll leftSum = sum(node*2, lo, mid, mod);
  ll rightSum = sum(node*2 + 1, mid+1, hi, (mod + lcount)%5);
  ret = leftSum + rightSum;
  return ret;
}

void update(int elementId, int value) {
  int node = mp[elementId];
  exists[elementId] = value;
  while (node > 0) {
    fill(ddp[node], -1);
    cdp[node] = -1;
    node /= 2;
  }
}


int main(int argc, char** argv) {
	s(n);
  for (int i=0; i < n; i++) {
    scanf("%s", com[i]);
    if (com[i][0] != 's') {
      s(val[i]);
      elems[esz++] = val[i];
    }
  }
  sort(elems, elems+esz);
  esz = unique(elems, elems+esz) - elems;
  init();
  if (esz > 0) create(1, 0, esz-1);
  for (int i=0; i < n; i++) {
    char c = com[i][0];
    //cout << com[i] << " " << val[i] << endl;
    if (c == 's') {
      ll ans = (esz > 0)  ? sum(1, 0, esz-1, 1) : 0;
      cout << ans << endl;
    } else {
      update( lower_bound(elems, elems+esz, val[i]) - elems, c == 'a' );
    }
  }
  
	return 0;
}