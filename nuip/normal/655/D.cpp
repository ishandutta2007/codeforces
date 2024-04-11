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
#include<unordered_set>
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

int ok(const vv<pii> &g,int ub){
  int n=g.size();
  vector<int> in(n);
  rep(i,n) for(const pii &p:g[i]) if(p.Y<ub) ++in[p.X];
  int v=-1;
  //cout<<in;
  rep(i,n) if(in[i]==0){
    if(v<0) v=i;
    else return 0;
  }
  if(v<0) return 0;
  rep(i,n-1){
    int w=-1;
    for(const pii &p:g[v]){
      if(p.Y>=ub) continue;
      --in[p.X];
      if(in[p.X]==0){
	if(w<0) w=p.X;
	else return 0;
      }
    }
    if(w<0) return 0;
    v=w;
  }
  return 1;
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n,m;
  cin>>n>>m;
  vv<pii> g(n);
  int x,y;
  rep(i,m){
    cin>>x>>y;
    --x; --y;
    g[x].eb(y,i);
  }
  //cout<<g;
  if(!ok(g,m)){
    cout<<-1<<endl;
    return 0;
  }
  int l=0,r=m,med;
  while(r-l>1){
    med=(l+r)/2;
    if(ok(g,med)){
      r=med;
    }else{
      l=med;
    }
  }
  cout<<r<<endl;
  return 0;
}