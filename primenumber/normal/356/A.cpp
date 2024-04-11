#include <iostream>
#include <iomanip>
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
#include <cmath>

#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define EACH(i,x)   for(auto & i : x)
#define ALL(x)      begin(x),end(x)

using namespace std;

typedef vector<int> vecint;

int main()
{
  int n,m;
  cin>>n>>m;
  set<int> a;
  REP(i,n)
    a.insert(i+1);
  map<int,int> mp;
  REP(i,m) {
    int l,r,x;
    cin>>l>>r>>x;
    auto ibeg = a.lower_bound(l);
    auto iend = a.upper_bound(r);
    for(auto itr = ibeg;itr != iend;++itr) {
      if(*itr != x)
        mp.insert(make_pair(*itr,x));
    }
    a.erase(ibeg,iend);
    a.insert(x);
  }
  REP(i,n-1) {
    cout<<mp[i+1]<<' ';
  }
  cout<<mp[n]<<endl;
  return 0;
}