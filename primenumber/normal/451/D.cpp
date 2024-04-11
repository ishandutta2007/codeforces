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

int64_t osum(int64_t n) {
  int64_t h = (n+1) / 2;
  n -= 1-n%2;
  return (n+1) * h / 2;
}

int64_t esum(int64_t n) {
  n -= n%2;
  int64_t h = n/2;
  return (n+2) * h / 2;
}

int main()
{
  string s;
  cin>>s;
  vector<int> a;
  int old = 0;
  REP(i,s.size()-1) {
    if (s[i] != s[i+1]) {
      a.push_back(i-old+1);
      old = i+1;
    }
  }
  a.push_back(s.size()-old);
  int64_t sum[] = {0,0};
  int sb[2][2] = {{0,0},{0,0}};
  int b = 0;
  int ind = 0;
  for(int64_t v:a) {
    int ve, vo;
    if (ind) {
      ve = v/2;
      vo = (v+1)/2;
    } else {
      ve = (v+1)/2;
      vo = v/2;
    }
    if(v%2) {
      sum[0] += esum(v);
      sum[1] += osum(v);
    } else {
      sum[0] += osum(v);
      sum[1] += esum(v);
    }
    sum[0] += sb[b][0] * vo + sb[b][1] * ve;
    sum[1] += sb[b][1] * vo + sb[b][0] * ve;
    sb[b][0] += ve;
    sb[b][1] += vo;
    b=1-b;
    ind += v;
    ind%=2;
  }
  cout<<sum[0]<<' '<<sum[1]<<endl;
  return 0;
}