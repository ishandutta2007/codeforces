#include <iostream>
#include <bitset>
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
  int64_t n,m;cin>>n>>m;
  stringstream ss;
  ss<<n;
  string ns = ss.str();
  if(ns.size()==1){
    if(m>1){
    cout<<0<<endl;
    }else{
      cout<<1<<endl;
    }
  }else{
    vector<int64_t> m10(19);
    vector<int64_t> fact(19);
    m10[0]=1;
    fact[0]=1;
    FOR(i,1,19){
      m10[i]=m10[i-1]*10;
      m10[i]%=m;
      fact[i]=fact[i-1]*i;
    }
    vector<vector<int64_t>> dp(1<<18,vector<int64_t>(m));
    dp[0][0]=1;
    int64_t s=ns.size();
    REP(i,1<<s){
      bitset<18> bs(i);
      REP(j,s){
        if(bs.count() == s-1 && ns[j] == '0')continue;
        if(i!=(i|(1<<j))){
          int64_t k=i|(1<<j);
          int64_t mod=(m10[bs.count()]*(ns[j]-'0'))%m;
          REP(l,m){
            dp[k][(l+mod)%m] += dp[i][l];
          }
        }
      }
    }
    vecint cnt(10);
    REP(i,s){
      cnt[ns[i]-'0']++;
    }
    int64_t sum=dp[(1<<s)-1][0];
    REP(i,10){
      sum/=fact[cnt[i]];
    }
    cout<<sum<<endl;
  }
  return 0;
}