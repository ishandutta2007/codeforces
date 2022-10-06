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

ll dp[112][212][1123];

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n,t;
  cin>>n>>t;
  vector<int> a(n);
  rep(i,n) cin>>a[i];
  sort(all(a));
  dp[0][0][0]=1;
  const int W=(n+1)/2+1;
  rep(pos,n) rep(i,t+1) rep(w,W){
    ll d=pos?a[pos]-a[pos-1]:0;
    if(i+w*d<=t){
      (dp[w+1][pos+1][i+w*d]+=dp[w][pos][i])%=MOD;
      (dp[w][pos+1][i+w*d]+=dp[w][pos][i]*(w+1)%MOD)%=MOD; //[x,x]
      if(w) (dp[w-1][pos+1][i+w*d]+=dp[w][pos][i]*w%MOD)%=MOD;
    }
  }
  //rep(pos,n+1){rep(i,t+1){rep(j,W)cout<<dp[i][pos][j]<<",";cout<<endl;}cout<<endl;}
  ll re=0;
  rep(i,t+1) (re+=dp[0][n][i])%=MOD;
  cout<<re<<endl;
  return 0;
}