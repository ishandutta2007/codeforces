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
//--
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

ll num[112345];
ll dp[2][112345];

int main(){
  ll i,j,k,n,a;
  cin>>n;
  rep(i,n){
    cin>>a;
    num[a]++;
  }
  for(i=1;i<=100000;i++){
    dp[1][i]=max(dp[0][i-1]+i*num[i],dp[1][i]);
    dp[0][i]=max(dp[1][i-1],max(dp[0][i],dp[0][i-1]));
  }
 /* rep(i,2){
    rep(j,10)cout<<dp[i][j]<<" ";cout<<endl;
  }*/
  cout<<max(dp[0][100000],dp[1][100000])<<endl;
  return 0;
}