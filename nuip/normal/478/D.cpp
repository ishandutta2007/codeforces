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
ll dp[2][212345],MOD=1e9+7;
int main(){
  std::ios_base::sync_with_stdio(false);
  int i,j,k;
  ll r,g,h;
  cin>>r>>g;
  h=max(0,int(sqrt(2*(r+g))-10));
  while((h+1)*(h+2)<=2*(r+g))
    h++;
//  cout<<h<<endl;
  dp[0][0]=1;
  for(i=1;i<=h;i++){
    rep(j,max(r,g)+1){
      dp[i%2][j]=dp[1-i%2][j];
      if(j-i>=0)
        dp[i%2][j]=(dp[i%2][j]+dp[1-i%2][j-i])%MOD;
      //if(j<10)cout<<dp[i%2][j]<<",";
    }
  }
  ll re=0;
  for(ll v=r;h*(h+1)/2-v<=g&&v>=0;v--)
    re=(re+dp[h%2][v])%MOD;
  cout<<re<<endl;
  return 0;
}