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
#include<cstdio>
#include<cstring>
#include<sstream>
#define X first
#define Y second
#define pb push_back
#define pqPair priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >
#define all(X) (X).begin(),(X).end()

using namespace std;
typedef __int64 ll;

int main(){
  ll n,m,b,x[112],k[112],prob[112],M,i,j,tmp,hoge;
  vector<pair<ll,ll> > fri;
  scanf("%I64d %I64d %I64d",&n,&m,&b);
  for(i=0;i<n;i++){
   // cout<<i;
    scanf("%I64d %I64d %I64d",&x[i],&k[i],&M);
    prob[i]=0;
    for(j=0;j<M;j++){
      scanf("%I64d",&hoge);
      hoge--;
      prob[i]|=(1<<hoge);
    }//cout<<x[i]<<","<<k[i]<<endl;
    fri.pb(pair<ll,ll>(k[i],i));
  }
  sort(fri.begin(),fri.end());

  ll dp[2][1<<20],re=1ll<<60;
  for(i=0;i<(1<<20);i++)
    dp[0][i]=dp[1][i]=(1ll<<60);
  dp[0][0]=0;
 // cout<<dp[0][(1<<m)-1]<<"!"<<m<<endl;
  for(i=0;i<fri.size();i++){
  //  cout<<fri[i].X<<endl;
    for(j=0;j<(1<<m);j++)
      dp[1][j]=min(dp[1][j],dp[0][j]);
    for(j=0;j<(1<<m);j++){
      dp[0][j|prob[fri[i].Y]]=min(dp[1][j]+x[fri[i].Y]
                                  ,dp[0][j|prob[fri[i].Y]]);
    }
    re=min(re,dp[0][(1<<m)-1]+b*fri[i].X);
  //  cout<<re<<endl;
  }
  printf("%I64d\n",((re!=(1ll<<60))?re:-1ll));
  return 0;
}