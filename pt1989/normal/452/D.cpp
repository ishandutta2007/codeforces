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

int k,n1,n2,n3,t1,t2,t3;
const int MXN = 1024;

struct mType {
  priority_queue<int, vector<int>, greater<int> > heap;
  int num;
  mType(int _num) {
    num = _num;
    for (int i=0; i < num; i++) heap.push(0);
  }
  int getEarliest() {
    int res = heap.top();
    heap.pop();
    return res;
  }
  void freesAt(int T) {
    heap.push(T);
  }
};

int main() {
  readInt(k); readInt(n1); readInt(n2); readInt(n3); readInt(t1); readInt(t2); readInt(t3);
  
  
  mType washer(n1), drier(n2), folder(n3);
  int ans = 0;
  for (int laundry=0; laundry < k; laundry++) {
    int s1 = washer.getEarliest();
    int s2 = drier.getEarliest();
    int s3 = folder.getEarliest();
    
    if (s3 > s2 + t2) {
      s2 = s3 - t2;
    }
    if (s2 > s1 + t1) {
      s1 = s2 - t1;
    }
    
    washer.freesAt(s1 + t1);
    drier.freesAt(s1 + t1 + t2);
    folder.freesAt(s1 + t1 + t2 + t3);
    // cout << s1 << "+" << t1 <<  "+" << t2 << "+" << t3 << endl;
    ans = max(ans, s1 + t1 + t2 + t3);
  }
  cout << ans << endl;
}