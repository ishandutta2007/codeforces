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

inline ll dist(ll x,ll y){return x*x+y*y;}

double solve(ll x,ll y,ll vx,ll vy,double l,double r,ll v,ll t=0){
  double m;
  rep(i,10000){
    m=(l+r)/2;
    if(hypot(x+vx*m,y+vy*m)<=v*(m+t))
      r=m;
    else
      l=m;
  }
  return l;
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(10);
  ll x,y,X,Y,v,t,vx,vy,wx,wy;
  cin>>x>>y>>X>>Y>>v>>t>>vx>>vy>>wx>>wy;
  vx*=-1; vy*=-1; wx*=-1; wy*=-1;
  if(dist(X+vx*t-x,Y+vy*t-y)<=t*v*t*v){
    cout<<solve(X-x,Y-y,vx,vy,0,t,v)<<endl;
  }else{
    cout<<solve(X-x+vx*t ,Y-y+vy*t ,wx,wy,0,1e20,v,t)+t<<endl;
  }
  return 0;
}