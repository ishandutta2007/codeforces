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

int dp[2123][2123];

int main(){
  std::ios_base::sync_with_stdio(false);
  int i,j,k;
  string s,p;
  cin>>s>>p;
  int n=s.size(),m=p.size(),pos,cost;
  vector<pii> g;
  rep(i,n){
    pos=0;
    for(j=i;j<n;j++){
      if(s[j]==p[pos])
        pos++;
      if(pos==m)
        break;
    }
    if(pos==m)
      g.pb(pii(j,1));
    else
      g.pb(pii(n,0));
  }
  //rep(i,n)cout<<g[i].X<<","<<g[i].Y<<endl;
  fill(dp[0],dp[0]+2123*2123,-1);
  dp[0][0]=0;
  rep(i,n){
    rep(j,n+1){
      dp[j][i+1]=max(dp[j][i],dp[j][i+1]);
      dp[j+1][i+1]=max(dp[j][i],dp[j+1][i+1]);
      if(g[i].Y==0 || dp[j][i]<0)continue;
      cost=g[i].X-i+1-m;
 //     cout<<j<<","<<i<<":"<<cost<<"("<<g[i].X<<","<<g[i].Y<<")"<<endl;
      if(j+cost<=n){
        int &tmp=dp[j+cost][g[i].X+1];
        tmp=max(tmp,dp[j][i]+1);
      }
 /* rep(jj,n+1){
    rep(ii,n)cout<<dp[jj][ii]<<" ";cout<<endl;
  }cout<<endl;*/
    }
  }
 /* rep(j,n+1){
    rep(i,n)cout<<dp[j][i]<<" ";cout<<endl;
  }*/
  rep(i,n+1)
    cout<<dp[i][n]<<" ";
  cout<<endl;
  return 0;
}