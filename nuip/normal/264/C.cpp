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
#define peat(X,Y) for (;(X) < int(Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define int long long

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}

signed main(){
  ios_base::sync_with_stdio(false);
  //  cout<<fixed<<setprecision(0);
  int i,j,k;
  int  n,q;
  ll INF=1e17;
  cin>>n>>q;
  vector<ll> v(n),c(n);
  rep(i,n)
    cin>>v[i];
  rep(i,n)
    cin>>c[i];
  ll a,b,re=0;
  rep(i,q){
    re=0;
    vector<ll> dp(n+1,-INF);
    pll tp=pll(0,-1),sc=pll(-INF,n);
    dp[0]=0;
    cin>>a>>b;
    rep(i,n){
      ll tmp=-INF;
      tmp=max(tmp,a*v[i]+dp[c[i]]);
      if(tp.Y==c[i])
	tmp=max(tmp,b*v[i]+sc.X);
      else
	tmp=max(tmp,b*v[i]+tp.X);
      if(dp[c[i]]<=tmp)
	dp[c[i]]=tmp;
      pll temp=pll(tmp,c[i]);
      if(tp.X<=temp.X){
	  if(tp.Y!=temp.Y)
	    sc=tp;
	  tp=temp;
      }else if(sc<=temp && temp.Y != tp.Y){
	sc=temp;
      }
      re=max(re,tmp);
    }
    cout<<re<<endl;
  }
  return 0;
}