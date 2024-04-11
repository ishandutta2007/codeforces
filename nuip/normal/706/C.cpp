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
const ll INF=1e15;
ll dp[112345][2];

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  fill(dp[0],dp[112345],INF);
  int n;
  cin>>n;
  vector<ll> c(n);
  rep(i,n) cin>>c[i];
  vector<string> s(n);
  rep(i,n) cin>>s[i];
  vector<string> rs=s;
  for(string &s:rs) reverse(all(s));
  //cout<<s<<rs;
  dp[0][0]=0;
  dp[0][1]=c[0];
  reps(i,1,n){
    if(s[i-1]<=rs[i]) MN(dp[i][1],dp[i-1][0]+c[i]);
    if(rs[i-1]<=rs[i]) MN(dp[i][1],dp[i-1][1]+c[i]);
    if(s[i-1]<=s[i]) MN(dp[i][0],dp[i-1][0]);
    if(rs[i-1]<=s[i]) MN(dp[i][0],dp[i-1][1]);
  }
  ll re=min(dp[n-1][0],dp[n-1][1]);
  cout<<(re>=INF?-1:re)<<endl;
  //  rep(i,2){rep(j,n) cout<<dp[j][i]<<",";cout<<endl;}
  return 0;
}