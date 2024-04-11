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

int fun(vv<int> g,vector<int> cs,int c){
  int re=0;
  int n=g.size();
  vector<int> deg(n);
  rep(i,n) deg[i]=g[i].size();
  queue<int> q[2];
  rep(i,n) if(deg[i]<=1){
    q[cs[i]].push(i);
    deg[i]=-1;
  }
  while(q[0].size() + q[1].size()){
    ++re;
    while(q[c].size()){
      int v=q[c].front(); q[c].pop();
      for(int w:g[v]) if(--deg[w]<=1 && deg[w]>=0){
	  q[cs[w]].push(w);
	  deg[w]=-1;
	}
    }
    //cout<<re<<deg;
    c=1-c;
  }
  return re-1;
}    

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n;
  cin>>n;
  vector<int> cs(n);
  rep(i,n) cin>>cs[i];
  vv<int> g(n);
  rep(i,n-1){
    int x,y;
    cin>>x>>y; --x; --y;
    g[x].pb(y);
    g[y].pb(x);
  }
  cout<<min(fun(g,cs,0),fun(g,cs,1))<<endl;
  return 0;
}