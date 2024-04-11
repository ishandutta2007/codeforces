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
#include <cmath>

#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define EACH(i,x)   for(auto & i : x)
#define ALL(x)      begin(x),end(x)

using namespace std;

typedef vector<int> vecint;

int main()
{
  int c[4];
  REP(i,4)cin>>c[i];
  int n,m;
  cin>>n>>m;
  int bcost = 0;
  REP(i,n) {
    int t;
    cin>>t;
    bcost += min(t*c[0],c[1]);
  }
  bcost = min(bcost,c[2]);
  int tcost = 0;
  REP(i,m) {
    int t;
    cin>>t;
    tcost += min(t*c[0],c[1]);
  }
  tcost = min(tcost,c[2]);
  cout<<min(c[3],bcost+tcost)<<endl;
  return 0;
}