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

int64_t gcd(int64_t x,int64_t y) {
  if(x < y) return gcd(y,x);
  else if(y == 0) return x;
  else return gcd(y,x%y);
}

int main()
{
  int64_t n,m;
  cin>>n>>m;
  string x,y;
  cin>>x>>y;
  int64_t xl = x.size();
  int64_t yl = y.size();
  int64_t g = gcd(xl,yl);
  int64_t ham = 0;
  REP(i,g) {
    vector<int64_t> sx(26,0);
    REP(j,xl/g)
      ++sx[x[j*g+i]-'a'];
    vector<int64_t> sy(26,0);
    REP(j,yl/g)
      ++sy[y[j*g+i]-'a'];
    int64_t sumy = 0;
    REP(j,26) {
      sumy += sy[j];
    }
    REP(j,26) {
      ham += sx[j]*(sumy-sy[j]);
    }
  }
  int64_t t = n/(yl/g);
  cout<< t*ham << endl;
  return 0;
}