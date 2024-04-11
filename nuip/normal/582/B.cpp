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
const int INF=1e5;

ll g[312][312];
ll d[312][312],db[321][321];

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n,t;
  cin>>n>>t;
  vector<int> a(n);
  rep(i,n)
    cin>>a[i];
  
  int m=*max_element(all(a)); ++m;
  rep(i,m){
    vector<int> dp(m,-INF);
    dp[i]=0;
    rep(j,n)
      dp[a[j]]=(*max_element(dp.begin(),dp.begin()+a[j]+1))+1;
    rep(j,m)
      g[i][j]=max(0,dp[j]);
  }
  //rep(i,m){rep(j,m)cout<<g[i][j]<<",";cout<<endl;}cout<<endl;

  rep(i,m) rep(j,i+1) rep(k,m)
    d[k+1][i]=max(d[k+1][i],d[k][j]+g[j][i]);
  rrep(i,m) rrep(j,m){
    if(j<i) break;
    rep(k,m)
      db[k+1][i]=max(db[k+1][i],db[k][j]+g[i][j]);
  }
  //rep(i,m){rep(j,m)cout<<d[i][j]<<",";cout<<endl;}cout<<endl;
  //rep(i,m){rep(j,m)cout<<db[i][j]<<",";cout<<endl;}
  
  ll re=0;
  rep(i,m) rep(j,min(t+1,m))rep(k,min(t+1-j,m)){
    re=max(re,d[j][i]+db[k][i]+(t-k-j)*g[i][i]);
    //if(i==1)cout<<d[j][i]<<","<<db[k][i]<<","<<(t-k-j)<<","<<g[i][i]<<endl;
  }
  cout<<re<<endl;
  return 0;
}