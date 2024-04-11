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

bool winable(const vector<string>& g, const string& s){
  REP(i,26){
    auto cp = s + string(1,'a'+i);
    auto ib = lower_bound(begin(g),end(g),cp);
    if(ib != end(g) && ib->size() >= cp.size() && cp == ib->substr(0,cp.size()))
      if(!winable(g,cp))
        return true;
  }
  return false;
}

bool losable(const vector<string>& g, const string& s){
  bool puttable = false;
  REP(i,26){
    auto cp = s + string(1,'a'+i);
    auto ib = lower_bound(begin(g),end(g),cp);
    if(ib != end(g) && ib->size() >= cp.size() && cp == ib->substr(0,cp.size())){
      puttable = true;
      if(!losable(g,cp))
        return true;
    }
  }
  return !puttable;
}

int main()
{
  int n,k;
  cin>>n>>k;
  vector<string> g(n);
  REP(i,n){
    cin>>g[i];
  }
  sort(begin(g),end(g));
  bool wb = winable(g,"");
  bool lb = losable(g,"");
  if(wb&&lb){
    cout<<"First"<<endl;
  }else if(wb){
    if(k%2){
      cout<<"First"<<endl;
    }else{
      cout<<"Second"<<endl;
    }
  }else{
    cout<<"Second"<<endl;
  }
  return 0;
}