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

ll dp[2][5123];
const ll INF=1e16;

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n,t;
  cin>>n>>t;
  vector<int> a(n);
  rep(i,n)
    cin>>a[i];
  sort(all(a));
  a.pb(a.back());
  //cout<<a;
  int d=n/t,m=n%t;
  fill(dp[0],dp[0]+2*5123,-INF);
  dp[0][0]=0;
  rep(i,t){
    fill(dp[1-i%2],dp[1-i%2]+5123,-INF);
    rep(j,m+1){
      dp[1-i%2][j]=max(dp[1-i%2][j],
		       dp[i%2][j]+a[i*d+j+d]-a[i*d+j+d-1]);
      if(j<m)
	dp[1-i%2][j+1]=max(dp[1-i%2][j+1],
			   dp[i%2][j]+a[i*d+j+d+1]-a[i*d+j+d]);
    }
    //rep(j,m+1)cout<<dp[1-i%2][j]<<",";cout<<endl;
  }
  //cout<<dp[t%2][m]<<endl;
  ll re=-dp[t%2][m];
  rep(i,n-1) re+=a[i+1]-a[i];
  cout<<re<<endl;
  return 0;
}