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
ll modpow(ll r,ll n,ll m=MOD){
  ll re=1,d=r%m;
  for(n=(n%(m-1)+m-1)%(m-1);n;n/=2){
    if(n&1)(re*=d)%=m;
    (d*=d)%=m;
  }
  return re;
}
struct UF{
  vector<int> data;
  UF(int size):data(size,-1){}
  bool unite(int x,int y){
    x=root(x); y=root(y);
    if(x!=y){
      if(data[y]<data[x]) swap(x,y);
      data[x]+=data[y]; data[y]=x;
    }
    return x!=y;
  }
  bool findSet(int x,int y){return root(x)==root(y);}
  int root(int x){return data[x]<0?x:data[x]=root(data[x]);}
  int size(int x) {return -data[root(x)];}
};

int dfs(vv<int> &g,vector<int> &c,int v,int p,int t){
  if(c[v]>=0) return c[v]!=t;
  c[v]=t;
  for(int w:g[v])
    if(w!=p){
      if(dfs(g,c,w,v,1-t))return 1;
    }
  return 0;
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n,m;
  scanf("%d%d",&n,&m);
  vector<pii> es;
  UF uf(n);
  int a,b,c;
  rep(i,m){
    scanf("%d%d%d",&a,&b,&c);
    --a; --b;
    if(c){
      uf.unite(a,b);
    }else{
      es.eb(a,b);
    }
  }
  vector<int> conv(n),roots;
  rep(i,n)
    if(uf.data[i]<0)
      roots.pb(i);
  rep(i,roots.size())
    conv[roots[i]]=i;
  rep(i,n)
    conv[i]=conv[uf.root(i)];
  //cout<<roots<<conv;
  int N=roots.size();
  vv<int> g(N);
  for(const pii &p:es){
    g[conv[p.X]].pb(conv[p.Y]);
    g[conv[p.Y]].pb(conv[p.X]);
  }
  rep(i,N){
    sort(all(g[i]));
    UNIQUE(g[i]);
  }
  //cout<<g;
  vector<int> color(N,-1);
  rep(i,N)if(color[i]<0)
    if(dfs(g,color,i,-1,0)){
      printf("0\n");
      return 0;
    }
  ll re=0;
  UF cc(N);
  for(const pii &p:es){
    cc.unite(conv[p.X],conv[p.Y]);
  }
  rep(i,N)
    if(cc.data[i]<0)
      ++re;
  printf("%I64d\n",modpow(2,re-1));
  return 0;
}