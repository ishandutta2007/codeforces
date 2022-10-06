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

ll dp[2123][2123];

int main(){
  std::ios_base::sync_with_stdio(false);
  int i,j,k;
  int n,h,tmp;
  cin>>n>>h;
  vector<int> a;
  a.pb(0);
  rep(i,n){
    cin>>tmp;
    a.pb(h-tmp);
  }
  a.pb(0);
//  rep(i,n+2)cout<<a[i]<<" ";cout<<endl;
  rep(i,n+1){
    if(abs(a[i]-a[i+1])>1){
      cout<<0<<endl;
      return 0;
    }
  }
  dp[0][0]=1;
  rep(i,n+1){
    if(a[i]<a[i+1]){
      rep(j,n)
        dp[j+1][i+1]=dp[j][i];
    }else if(a[i]>a[i+1]){
      rep(j,n)
        dp[j][i+1]=dp[j+1][i]*(j+1);
    }else{
      rep(j,n)
        dp[j][i+1]=dp[j][i]*(j+1);
    }
    rep(j,n+2)
      dp[j][i+1]%=ll(1e9+7);
  }
//  cout<<endl;
//  rep(i,n+2){rep(j,n+2)cout<<dp[i][j]<<" ";cout<<endl;}
  cout<<dp[0][n+1]<<endl;
  return 0;
}