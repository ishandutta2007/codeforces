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
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int i,j,k;
  map<int,int> dp,dp2;
  dp[0]=0;
  int n;
  cin>>n;
  vector<int> l(n),c(n);
  rep(i,n)
    cin>>l[i];
  rep(i,n)
    cin>>c[i];
  int gcd;
  rep(i,n){
    dp2=dp;
    for(auto &p:dp2){
      gcd=__gcd(p.X,l[i]);
      if(dp.count(gcd)){
	dp[gcd]=min(dp[gcd],p.Y+c[i]);
      }else{
	dp[gcd]=p.Y+c[i];
      }
    }
  }
  cout<<(dp.count(1)?dp[1]:-1)<<endl;
  return 0;
}