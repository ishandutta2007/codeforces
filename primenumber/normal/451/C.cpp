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
  int t;
  cin>>t;
  REP(cnt,t){
    int64_t n,k,d1,d2;
    cin>>n>>k>>d1>>d2;
    int s[] = {1,-1};
    bool ok=false;
    REP(i,2)REP(j,2) {
      int64_t sum = s[i]*d1+s[j]*d2;
      int64_t dgames = k-sum;
      if (dgames%3!=0) continue;
      int64_t w[3];
      w[0] = dgames/3 + s[i]*d1;
      w[1] = dgames/3;
      w[2] = dgames/3 + s[j]*d2;
      sort(begin(w),begin(w)+3);
      if(w[0] < 0) continue;
      int64_t nd = w[2] * 2 - w[0] - w[1];
      if (nd <= n-k && (n-k-nd)%3==0) {
        ok = true;
        break;
      }
    }
    if (ok)
      cout<<"yes"<<endl;
    else
      cout<<"no"<<endl;
  }
  return 0;
}