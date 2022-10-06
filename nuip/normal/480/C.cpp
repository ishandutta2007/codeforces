#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<cstring>
#include<sstream>
#include<complex>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < int(Y);++(X))
#define rrep(X,Y) for (int (X) = int(Y-1);(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < int(Y);++(X))
#define peat(X,Y) for (;(X) < int(Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main(){
  std::ios_base::sync_with_stdio(false);
  int i,j,k;
  int n,a,b,t,MOD=1e9+7;
  cin>>n>>a>>b>>t;
  vector<int> dp(n+1),tmp;
  dp[a]=1;
  rep(i,t){
    tmp=dp;
    rep(i,tmp.size()-1)
      tmp[i+1]=(tmp[i+1]+tmp[i])%MOD;
    rep(i,dp.size()){
      if(i)if(i<b){
        dp[i]=(tmp[(i+b-1)/2]+MOD-dp[i])%MOD;
      }else if(b<i){
        dp[i]=((tmp[n]+MOD-tmp[(i+b)/2])%MOD+MOD-dp[i])%MOD;
      }else{
        dp[i]=0;
      }
    }
//    rep(i,dp.size())cout<<dp[i]<<",";cout<<endl;
  }
  int re=0;
  rep(i,dp.size())
    re=(re+dp[i])%MOD;
  cout<<re<<endl;
  return 0;
}