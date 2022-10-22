#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <cstdint>

#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define EACH(i,x)   for(auto & i : x)
#define ALL(x)      begin(x),end(x)

using namespace std;

typedef vector<int> vecint;

bool is_ok(const vector<int64_t> &p,const vector<int64_t> &h,int64_t x) {
  int l = p.size();
  auto itr_b = h.begin();
  REP(i,l) {
    auto l_itr = lower_bound(itr_b,h.end(),p[i]);
    if(l_itr == itr_b) {
      itr_b = upper_bound(itr_b,h.end(),p[i]+x);
    } else {
      int64_t d = p[i] - *itr_b;
      if(d > x)
        return false;
      else
        itr_b = upper_bound(itr_b,h.end(),p[i]+max((x-d)/2,x-d*2));
    }
  }
  return itr_b == h.end();
}

int main()
{
  int n,m;
  cin>>n>>m;
  vector<int64_t> h(n);
  vector<int64_t> p(m);
  REP(i,n)cin>>h[i];
  REP(i,m)cin>>p[i];
  int64_t num = 0x1000000000LL;
  int64_t j = 0;
  while(num != 0) {
    if(!is_ok(h,p,j+num)) {
      j += num;
    }
    num /= 2LL;
  }
  if(!is_ok(h,p,0))
    cout << (j+1) << endl;
  else
    cout << 0 << endl;
  return 0;
}