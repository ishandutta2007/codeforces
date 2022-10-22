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
  int x,k;cin>>x>>k;
  int maxp=0,minp=0;
  int oldn = 0;
  vecint d(x+1);
  d[0]=d[x]=1;
  REP(i,k){
    int t;
    cin>>t;
    if(t==1){
      int n1,n2;
      cin>>n2>>n1;
      d[n1]=d[n2]=1;
    }
    else{
      int n2;
      cin>>n2;
      d[n2]=1;
    }
  }
  oldn = -1;
  REP(i,x+1){
    if(d[i]){
      maxp += i - oldn - 1;
      minp += (i - oldn) / 2;
      oldn = i;
    }
  }
  cout<<minp<<' '<<maxp<<endl;
  return 0;
}