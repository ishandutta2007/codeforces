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
#include<cassert>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))
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
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}
const ll MOD=1e9+7;

ll dp[5123][5123];
const ll INF=1e15;

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  fill(dp[0],dp[5123],INF);
  int n,s,t;
  cin>>n>>s>>t; --s; --t;
  vector<ll> x(n),il(n),is(n),os(n),ol(n);
  rep(i,n) cin>>x[i];
  rep(i,n) cin>>il[i];
  rep(i,n) cin>>is[i];
  rep(i,n) cin>>os[i];
  rep(i,n) cin>>ol[i];
  dp[0][0]=0;
  rep(i,n){
    rep(j,5023)if(i==0 || j){
      if(i) dp[j][i]+=j*(x[i]-x[i-1]);
      if(i==s){
	if(j-1>=0) MN(dp[j-1][i+1],dp[j][i]+os[i]);
	MN(dp[j+1][i+1],dp[j][i]+ol[i]);
      }else if(i==t){
	if(j-1>=0) MN(dp[j-1][i+1],dp[j][i]+il[i]);
	MN(dp[j+1][i+1],dp[j][i]+is[i]);
      }else{
	if(j-2>=0) MN(dp[j-2][i+1],dp[j][i]+il[i]+os[i]);
	if(j && (j>1 || s<t)) MN(dp[j][i+1],dp[j][i]+il[i]+ol[i]); // ->
	if(j && (j>1 || t<s)) MN(dp[j][i+1],dp[j][i]+is[i]+os[i]); // <-
	MN(dp[j+2][i+1],dp[j][i]+is[i]+ol[i]);
      }
    }
  }
  //rep(j,10){rep(i,n+1) cout<<(dp[j][i]>=INF?-1:dp[j][i])<<",\t";cout<<endl;}
  cout<<dp[0][n]<<endl;
  return 0;
}