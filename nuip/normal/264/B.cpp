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

int dp[112345];

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int i,j,k;
  int n,re=0;
  cin>>n;
  vector<int> a(n);
  rep(i,n)
    cin>>a[i];
  sort(all(a));
  rep(i,n){
    int mx=0;
    for(j=1;j*j<=a[i];j++){
      if(a[i]%j==0 && j!=1)
	mx=max(mx,max(dp[j],dp[a[i]/j]));
    }
    dp[a[i]]=mx+1;
    re=max(dp[a[i]],re);
    for(j=1;j*j<=a[i];j++){
      if(a[i]%j==0 && j!=1){
	dp[a[i]/j]=dp[a[i]];
	dp[j]=dp[a[i]];
      }
    }
    //  rep(ii,10)cout<<dp[ii]<<",";cout<<endl;
  }
  //  rep(i,10)cout<<dp[i]<<",";cout<<endl;
  cout<<re<<endl;
  return 0;
}