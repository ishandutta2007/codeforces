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
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y-1);(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<vector<int>> vii;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(10);
  int i,j,k;
  int n,t;
  cin>>n>>t;
  vector<int> v(n),a,b;
  rep(i,n)
    cin>>v[i];
  if(n==1){
    cout<<0<<endl;
    return 0;
  }
  map<vector<int>,double> dp[2];
  dp[0][v]=1;
  rep(i,t){
    dp[1-i%2].clear();
    for(auto p:dp[i%2]){
      rep(j,n)rep(k,n-j){
	a=p.X;
	rep(l,k+1){
	  a[j+l]=p.X[j+k-l];
	}
	//	cout<<a<<endl;
	dp[1-i%2][a]+=p.Y*2/n/(n+1);
      }
      //     cout<<p<<",";
    }//cout<<endl;
  }
  double re=0;
  int inv=0;
  for(auto p:dp[t%2]){
    inv=0;
    rep(i,n)rep(j,n-i)
      inv+=(p.X[i]>p.X[i+j]);
    re+=inv*p.Y;
  }
  cout<<re<<endl;
  return 0;
}