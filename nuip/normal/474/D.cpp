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

ll dp[112345],MOD=1e9+7;

int main(){
  std::ios_base::sync_with_stdio(false);
  int i,j,k,t,K;
  cin>>t>>K;
  dp[0]=1;
  rep(i,112300){
    dp[i]%=MOD;
    dp[i+1]+=dp[i];
    if(i+K<112300)dp[i+K]+=dp[i];
  }
//  rep(i,10) cout<<dp[i]<<",";cout<<endl;
  rep(i,112300){
    dp[i]%=MOD;
    dp[i+1]+=dp[i];
  }
//  rep(i,10) cout<<dp[i]<<",";cout<<endl;
  int a,b;
  rep(i,t){
    cin>>a>>b;
    a--;
    cout<<(MOD+dp[b]-dp[a])%MOD<<endl;
  }
  return 0;
}