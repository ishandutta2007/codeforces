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
#include<iomanip>
#include<numeric>
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
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}

double dp[5123][5123];

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(8);
  int i,j,k;
  int n,T;
  cin>>n>>T;
  vector<double> p(n),nxt[n];
  vector<int> t(n);
  rep(i,n){
    cin>>p[i]>>t[i];
    p[i]/=100.;
  }
  // cout<<p;
  dp[0][0]=1;
  vector<double> pw;
  rep(i,n)
    pw.pb(pow(1-p[i],t[i]-1));
  for(i=1;i<=n;i++){
    for(j=1;j<=T;j++){
      dp[i][j]=dp[i][j-1]*(1-p[i-1])+dp[i-1][j-1]*p[i-1];
      if(j-t[i-1]>=0){
	dp[i][j]-=dp[i-1][j-t[i-1]]*pw[i-1]*p[i-1];
      }
    }
     for(j=t[i-1];j<=T;j++)
       dp[i][j]+=dp[i-1][j-t[i-1]]*pw[i-1];
  }
  //    rep(i,n+1){rep(j,T+1)cout<<dp[i][j]<<",";cout<<endl;}
  cout<<accumulate(dp[0]+1,dp[n]+T+1,.0)<<endl;
  return 0;
}