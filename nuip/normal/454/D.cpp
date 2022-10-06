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

int primes[16]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
int dp[112][1<<16],INF=5000,bit[60];
vector<int> ans[1<<16],pre[1<<16],re;
int main(){
  int i,j,k,a[112],b[112],n;
  rep(i,16){
    for(j=primes[i];j<60;j+=primes[i])
      bit[j]|=(1<<i);
  }
 // rep(i,20)cout<<bit[i]<<" ";cout<<endl;
  cin>>n;
  rep(i,n)cin>>a[i];
  fill(dp[0],dp[0]+112*(1<<16),INF);
  dp[0][0]=0;
  rep(i,n){
    rep(j,1<<16){
      for(k=1;k<=58;k++){
        if(j&bit[k])continue;
        int temp=j|bit[k];
        if(dp[i+1][temp]>dp[i][j]+abs(a[i]-k)){
         // if(dp[i][j]+abs(a[i]-k)==0)
         //   cout<<i<<";"<<a[i]<<","<<j<<","<<k<<endl;
          dp[i+1][temp]=dp[i][j]+abs(a[i]-k);
          ans[temp]=pre[j];
          ans[temp].pb(k);
        }
      }
    }
    rep(j,1<<16)
      pre[j]=ans[j];
  }
/*  rep(i,10){
    rep(j,10)cout<<dp[i][j]<<" ";cout<<endl;
  }*/
  int mind=INF;
  rep(i,1<<16){
    if(dp[n][i]<mind){
      mind=dp[n][i];
      re=ans[i];
    }
  }
 // cout<<mind<<endl;
  rep(i,n)
    cout<<re[i]<<" ";cout<<endl;
  return 0;
}