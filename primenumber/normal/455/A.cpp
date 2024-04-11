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

#define FOR(i,k,n)  for(int64_t i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define EACH(i,x)   for(auto & i : x)
#define ALL(x)      begin(x),end(x)

using namespace std;

typedef vector<int> vecint;

int main()
{
  int64_t n;
  cin>>n;
  vector<int64_t> a(100006);
  REP(i,n){
    int64_t c;
    cin>>c;
    ++a[c];
  }
  vector<vector<int64_t>> dp(100006,vector<int64_t>(2));
  REP(i,100005){
    dp[i+1][0]=max(dp[i][1],dp[i][0]);
    dp[i+1][1]=dp[i][0]+a[i+1]*(i+1);
  }
  cout<<max(dp[100005][0],dp[100005][1])<<endl;
  return 0;
}