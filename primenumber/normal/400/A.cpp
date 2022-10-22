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
    string s;cin>>s;
    vecint l;
    FOR(i,1,13){
      if((12%i)==0){
        REP(j,i){
          bool isok=true;
          REP(k,12/i){
            if(s[k*i+j]=='O'){
              isok=false;
              break;
            }
          }
          if(isok){
            l.push_back(i);
            break;
          }
        }
      }
    }
    cout<<l.size();
    REP(i,l.size()){
      cout<<' '<<(12/l[l.size()-i-1])<<'x'<<l[l.size()-i-1];
    }
    cout<<endl;
  }
  return 0;
}