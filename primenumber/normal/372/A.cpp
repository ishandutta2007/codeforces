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

bool isok(const vecint& s, int m, int n) {
  if(m*2>n) return false;
  REP(i,m) {
    if(s[n-i-1] < 2*s[m-i-1]) return false;
  }
  return true;
}

int main()
{
  int n;
  cin>>n;
  vecint s(n);
  REP(i,n)cin>>s[i];
  sort(ALL(s));
  int m = 1048576;
  int k = 0;
  while(m) {
    if(isok(s,m+k,n))
      k+=m;
    m/=2;
  }
  cout<<(n-k)<<endl;
  return 0;
}