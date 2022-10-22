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
  int n,k;
  cin>>n>>k;
  vecint a(n);
  REP(i,n)cin>>a[i];
  int ms = -1000000;
  REP(i,n)FOR(j,i,n){
    vecint others;
    REP(l,i)others.push_back(a[l]);
    FOR(l,j+1,n)others.push_back(a[l]);
    sort(ALL(others),greater<int>());
    vecint range(begin(a)+i,begin(a)+j+1);
    sort(ALL(range));
    int mk = min((size_t)k,min(range.size(), others.size()));
    REP(l,mk){
      if(others[l] > range[l])
        swap(others[l],range[l]);
    }
    int sum=0;
    REP(l,j-i+1){
      sum+=range[l];
    }
    ms = max(ms,sum);
  }
  cout << ms << endl;
  return 0;
}