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
  int n,l,r,ql,qr;
  cin>>n>>l>>r>>ql>>qr;
  vecint w(n);
  REP(i,n)cin>>w[i];
  vecint sum(n+1,0);
  REP(i,n)sum[i+1]=sum[i]+w[i];
  int mene = 1000000000;
  REP(i,n+1) {
    int ene = sum[i]*l+(sum[n]-sum[i])*r;
    if(i > n-i) {
      ene += (i*2-n-1)*ql;
    }else if(i < n-i){
      ene += (n-i*2-1)*qr;
    }
    mene = min(ene,mene);
  }
  cout<<mene<<endl;
  return 0;
}