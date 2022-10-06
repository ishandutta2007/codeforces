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
#include<unordered_map>
#include<cstring>
#include<sstream>
#include<complex>
#include<iomanip>
#include<numeric>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define eb emplace_back
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> using vv=vector<vector<T>>;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
const ll MOD=1e9+7;

ll dp[4010][4010],comb[4010][4010];

int count6(int n, int m){
    
    // count4_1u1vu2vccumv
    long long res = 0;
    for(int i = 1; i <= m; i++) res = (res + dp[n][i]) % MOD;
    return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  
  memset(dp, 0, (int)sizeof(dp));
  dp[0][0] = 1;
  for(int i = 1; i <= 4003; i++){
    for(int j = 1; j <= 4003; j++){
      dp[i][j] += dp[i-1][j] * j % MOD;
      dp[i][j] += dp[i-1][j-1];            
      dp[i][j] %= MOD;
    }
  }
  rep(i,4003)rep(j,4003)
    (dp[i][j+1]+=dp[i][j])%=MOD;
  comb[0][0]=1;
  rep(i,4003)rep(j,4003){
    (comb[i+1][j]+=comb[i][j])%=MOD;
    (comb[i+1][j+1]+=comb[i][j])%=MOD;
  }
  //rep(i,10){rep(j,10)cout<<comb[i][j]<<",";cout<<endl;}
  int n;
  cin>>n;
  ll re=0;
  rep(i,n)
    (re+=dp[i][i]*comb[n][i]%MOD)%=MOD;
  cout<<re<<endl;
  return 0;
}