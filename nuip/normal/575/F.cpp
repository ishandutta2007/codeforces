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
const ll MOD=1e9+7,INF=1e15;

int main(){
  //ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n,x;
  scanf("%d%d",&n,&x);
  vector<pii> in(n);
  vector<int> zip(2*n+1);
  int l,r;
  zip[2*n]=x;
  rep(i,n){
    scanf("%d%d",&l,&r);
    in[i].X=l; in[i].Y=r;
    zip[2*i]=l; zip[2*i+1]=r;
  }
  sort(all(zip));
  x=lower_bound(all(zip),x)-zip.begin();
  for(pii &p:in){
    p.X=lower_bound(all(zip),p.X)-zip.begin();
    p.Y=lower_bound(all(zip),p.Y)-zip.begin();
  }
  //cout<<x<<zip;
  const int m=2*n+1;
  ll dp[2][m];
  fill(dp[0],dp[0]+m,INF);
  dp[0][x]=0;
  rep(i,n){
    const int ii=1-i%2;
    l=in[i].X; r=in[i].Y;
    fill(dp[ii],dp[ii]+m,INF);
    rep(j,m){
      if(j) dp[ii][j]=min(dp[ii][j-1]+zip[j]-zip[j-1],dp[ii][j]);
      dp[ii][j]=min(dp[i%2][j],dp[ii][j]);
    }
    rrep(j,m)
      if(j+1<m) dp[ii][j]=min(dp[ii][j+1]+zip[j+1]-zip[j],dp[ii][j]);
    ll L=0,R=0;
    rep(j,m){
      if(l-j>=0) dp[ii][l-j]+=L;
      if(r+j<m) dp[ii][r+j]+=R;
      if(l-j>0) L+=zip[l-j]-zip[l-j-1];
      if(r+j+1<m) R+=zip[r+j+1]-zip[r+j];
    }
    //rep(j,m)cout<<dp[ii][j]<<",";cout<<endl;
  }
  cout<<(*min_element(dp[n%2],dp[n%2]+m))<<endl;
  return 0;
}