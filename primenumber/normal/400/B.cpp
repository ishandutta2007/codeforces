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
  int n,m;cin>>n>>m;
  vector<string> tb(n);
  REP(i,n)cin>>tb[i];
  set<int> a;
  REP(i,n){
    int dwf=-1;
    int cnd=-1;
    REP(j,m){
      if(tb[i][j]=='G')dwf=j;
      if(tb[i][j]=='S')cnd=j;
    }
    int d=cnd-dwf;
    if(d<0){
      cout<<"-1"<<endl;
      return 0;
    }
    a.insert(d);
  }
  cout<<a.size()<<endl;
  return 0;
}