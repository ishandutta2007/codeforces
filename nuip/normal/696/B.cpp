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

int dfs(vv<int> &g,int v,vector<int> &re){
  ++re[v];
  for(int w:g[v]) re[v]+=dfs(g,w,re);
  return re[v];
}

void dfs(vv<int> &g,int v,double t,vector<int> &sz,vector<double> &re){
  re[v]=++t;
  double sum=0;
  for(int w:g[v]) sum+=sz[w];
  for(int w:g[v]) dfs(g,w,t+(sum-sz[w])/2,sz,re);
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(10);
  int n;
  cin>>n;
  vv<int> g(n);
  rep(i,n-1){
    int x;
    cin>>x; --x;
    g[x].pb(i+1);
  }
  //cout<<g;
  vector<int> sz(n);
  dfs(g,0,sz);
  //cout<<sz;
  vector<double> re(n);
  dfs(g,0,0,sz,re);
  //cout<<re;
  rep(i,n) cout<<re[i]<<" ";
  return 0;
}