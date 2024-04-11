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

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n;
  cin>>n;
  vector<int> a(n);
  rep(i,n) cin>>a[i];
  map<ll,ll> dp[2];
  dp[0][-INF]=0;
  rep(i,n){
    ll mn=INF;
    for(pll p:dp[i%2]){
      MN(mn,p.Y);
      dp[i%2][p.X]=mn;
    }
    dp[1-i%2].clear();
    rep(j,n){
      const ll val=a[j]+i-j;
      auto it=dp[i%2].lower_bound(val);
      if(it==dp[i%2].begin()) continue;
      --it;
      if(dp[1-i%2].count(val)==0){
	dp[1-i%2][val] = it->Y + abs(val - a[i]);
      }else{
	MN(dp[1-i%2][val] , it->Y + abs(val - a[i]));
      }
    }
  }
  //rep(i,n+1){for(auto p:dp[i])cout<<p<<",";cout<<endl;}
  ll re=INF;
  for(pll p:dp[n%2]) MN(re,p.Y);
  cout<<re<<endl;
  return 0;
}