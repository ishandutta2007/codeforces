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

int vals[512345];
int deps[512345];
vector<pii> lst[512345];
int mxd[1<<22];
int re[512345];
unordered_map<int,int> mp[512345];

void dfs(const vv<pii> &g,int v){
  reps(i,1,g[v].size()){
    dfs(g,g[v][i].X);
    for(pii p:lst[g[v][i].X]) mxd[p.X]=-MOD;
  }
  if(g[v].size()){
    dfs(g,g[v][0].X);
    swap(lst[v], lst[g[v][0].X]);
  }
  for(pii w:g[v]) MX(re[v],re[w.X]);
  // rep(i,3) cout<<mxd[i]<<",";cout<<endl;
  MX(re[v], mxd[vals[v]]-deps[v]);
  rep(i,22) MX(re[v], mxd[vals[v]^(1<<i)]-deps[v]);
  MX(mxd[vals[v]],deps[v]);
  lst[v].eb(vals[v],deps[v]);
  reps(i,1,g[v].size()){
    for(pii p:lst[g[v][i].X]){
      MX(re[v], p.Y+mxd[p.X]-2*deps[v]);
      rep(j,22) MX(re[v], p.Y+mxd[p.X^(1<<j)]-2*deps[v]);
    }
    for(pii p:lst[g[v][i].X]) if(MX(mxd[p.X], p.Y)) lst[v].pb(p);
  }
  //cout<<v<<endl;
  //rep(i,17) cout<<(mxd[i]==-MOD?-1:mxd[i])<<",";cout<<endl;
}
void dfs(const vv<pii> &g,int v,int b,int d=0){
  vals[v]=b; deps[v]=d;
  for(pii w:g[v]) dfs(g,w.X,b^w.Y,d+1);
}

template<class T,class S> int hldec(vv<pair<S,T>> &g,int v=0,int p=-1){
  for(auto w:g[v]) if(w.X==p){ g[v].erase(find(all(g[v]),w)); break;}
  int sz=1;
  pii mx;
  rep(i,g[v].size()){
    const int tmp=hldec(g,g[v][i].X,v);
    sz+=tmp;
    MX(mx,pii(tmp,i));
  }
  if(mx.X) swap(g[v][0], g[v][mx.Y]);
  return sz;
}
int hldec(vv<int> &g,int v=0,int p=-1){
  if(p>=0) g[v].erase(find(all(g[v]),p));
  int sz=1;
  pii mx;
  rep(i,g[v].size()){
    const int tmp=hldec(g,g[v][i],v);
    sz+=tmp;
    MX(mx,pii(tmp,i)); 
 }
  if(mx.X) swap(g[v][0], g[v][mx.Y]);
  return sz;
}

int main(){
  //ios_base::sync_with_stdio(false);
  //cout<<fixed<<setprecision(0);
  fill(mxd,mxd+(1<<22),-MOD);
  int n;
  scanf("%d",&n);
  vv<pii> g(n);
  rep(i,n-1){
    int x;
    char c;
    scanf("%d %c",&x,&c); --x;
    //cout<<x<<","<<c<<endl;
    g[i+1].eb(x,1<<(c-'a'));
    g[x].eb(i+1,1<<(c-'a'));
  }
  //cout<<g;
  hldec(g);
  //cout<<g;
  dfs(g,0,0);
  //rep(i,n) printf("%o ",vals[i]); printf("\n");
  //rep(i,n) printf("%d ",deps[i]); printf("\n");
  dfs(g,0);
  rep(i,n) printf("%d ",re[i]);
  printf("\n");
  return 0;
}