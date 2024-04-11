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
  int n,k;
  cin>>n>>k;
  vector<vecint> divisors(n+1);
  FOR(i,1,n+1){
    FOR(j,1,i+1){
      if((i%j)==0){
        divisors[i].push_back(j);
      }
    }
  }
  vector<vecint> dp(k,vecint(n+1));
  FOR(i,1,n+1){
    dp[0][i]=1;
  }
  REP(i,k){
    if(!i)continue;
    FOR(j,1,n+1){
      for(int m:divisors[j]){
        dp[i][j] += dp[i-1][m];
        dp[i][j] %= 1000000007;
      }
    }
  }
  int sum=0;
  FOR(i,1,n+1){
    sum += dp[k-1][i];
    sum %= 1000000007;
  }
  cout<<sum<<endl;
  return 0;
}