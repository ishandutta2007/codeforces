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
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = Y-1;(X) >=0;--(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

ll MOD=1e9+7;

ll dp[2123][2123];
int main(){
  int i,j,k;
  int n,t;
  cin>>n>>t;
  dp[0][1]=1;
  rep(i,t){
    rep(j,n){
      for(k=1;k*k<=j+1;k++){
        if((j+1)%k)continue;
        dp[i+1][j+1]+=dp[i][k];
        if(k*k<j+1)dp[i+1][j+1]+=dp[i][(j+1)/k];
        dp[i+1][j+1]%=MOD;
      }
    }
  }
//  rep(i,n+1){rep(j,n+1)cout<<dp[i][j]<<" ";cout<<endl;}
  ll re=0;
  rep(i,n)
    re=(re+dp[t][i+1])%MOD;
  cout<<re<<endl;
  return 0;
}