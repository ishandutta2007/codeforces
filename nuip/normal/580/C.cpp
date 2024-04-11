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

int n,t;

int dfs(vv<int> &g,vector<int> &cat,int v,int p,int c){
  if(cat[v]) ++c;
  else c=0;
  //cout<<v<<","<<c<<endl;
  if(c>t) return 0;
  int re=0,f=1;
  for(int w:g[v])
    if(w!=p){
      re+=dfs(g,cat,w,v,c);
      f=0;
    }
  return re+f;
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  cin>>n>>t;
  vector<int> b(n);
  rep(i,n)
    cin>>b[i];
  vv<int> g(n);
  int x,y;
  rep(i,n-1){
    cin>>x>>y; --x; --y;
    g[x].pb(y);
    g[y].pb(x);
  }
  cout<<dfs(g,b,0,-1,0)<<endl;
  return 0;
}