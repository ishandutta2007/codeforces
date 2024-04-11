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
  int n;
  cin>>n;
  vector<vecint> xa(100001);
  vector<vecint> ya(100001);
  REP(i,n){
    int x,y;
    cin>>x>>y;
    xa[x].push_back(y);
    ya[y].push_back(x);
  }
  REP(i,100001){
    sort(ALL(xa[i]));
    sort(ALL(ya[i]));
  }
  int64_t cnt=0;
  REP(x,100001){
    for(int y:xa[x]){
      int x2 = x+1;
      while(1){
        auto upbx = lower_bound(ALL(ya[y]),x2);
        if(upbx == end(ya[y]))break;
        x2 = *upbx;
        int y2 = y + (x2 - x);
        auto upby1 = lower_bound(ALL(xa[x]),y2);
        auto upby2 = lower_bound(ALL(xa[x2]),y2);
        if(upby1 == end(xa[x]))break;
        if(*upby1 == y2) {
          if(upby2 != end(xa[x2]) && *upby2 == y2) {
            cnt++;
          }
          ++x2;
        } else {
          x2 = x + (*upby1 - y);
        }
      }
    }
  }
  cout << cnt << endl;
  return 0;
}