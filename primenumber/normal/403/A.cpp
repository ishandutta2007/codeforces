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
  int t;cin>>t;
  REP(i,t){
    int n,p;cin>>n>>p;
    int sum=0;
    FOR(j,1,n){
      int k=j+1;
      while(sum < 2*n+p && k <= n) {
        cout<<j<<' '<<k<<endl;
        sum++;
        k++;
      }
    }
  }
  return 0;
}