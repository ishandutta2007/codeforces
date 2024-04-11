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

int a[20][20],b[20];
ll dp[1<<18][20];

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n,m,t;
  cin>>n>>m>>t;
  rep(i,n)
    cin>>b[i];
  int x,y,z;
  rep(i,t){
    cin>>x>>y>>z; --x; --y;
    a[x][y]=z;
  }
  rep(i,n) dp[1<<i][i]=b[i];
  rep(i,1<<n)if(i){
    rep(j,n) if(i>>j&1)
      rep(k,n) if(!(i>>k&1))
	dp[i|(1<<k)][k]=max(dp[i|(1<<k)][k],dp[i][j]+b[k]+a[j][k]);
  }

  //rep(i,1<<n){rep(j,n)cout<<dp[i][j]<<",";cout<<endl;}

  ll re=0;
  rep(i,1<<n) if(__builtin_popcount(i)==m)
    rep(j,n)
      re=max(re,dp[i][j]);
  cout<<re<<endl;
  return 0;
}