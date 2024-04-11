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
  int n,m,x,y,z,p;cin>>n>>m>>x>>y>>z>>p;
  vecint cy(p);
  vecint cx(p);
  REP(i,p)cin>>cx[i]>>cy[i];
  x%=4;
  y%=2;
  z%=4;
  REP(i,p){
    int kn=n,km=m;
    REP(j,x){
      int tmp = cy[i];
      cy[i]=kn-cx[i]+1;
      cx[i]=tmp;
      swap(kn,km);
    }
    if(y){
      cy[i]=km-cy[i]+1;
    }
    REP(j,z){
      int tmp = cy[i];
      cy[i] = cx[i];
      cx[i] = km-tmp+1;
      swap(kn,km);
    }
    cout<<cx[i]<<' '<<cy[i]<<endl;
  }
  return 0;
}