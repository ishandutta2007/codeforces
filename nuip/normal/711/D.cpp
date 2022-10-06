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
ll modpow(ll r,ll n,ll m=MOD){
  ll re=1,d=r%m;
  if(n<0)(n%=m-1)+=m-1;
  for(;n;n/=2){
    if(n&1)(re*=d)%=m;
    (d*=d)%=m;
  }
  return re;
}

//arc039D
class Bcc{
  vector<int> num,inS;
  stack<int> roots,st;
  int cnt;
public:
  vv<int> bcc,tree;
  vector<int> brdg,inv;
  void dfs(const vv<int> &g,const vector<pii> &es,int v,int e){
    num[v]=++cnt;
    st.push(v); inS[v]=1; roots.push(v);
    for(const int &i:g[v])if(i!=e){
	int w=es[i].X+es[i].Y-v;
	if(!num[w]){
	  dfs(g,es,w,i);
	}else if(inS[w]){
	  while(num[roots.top()]>num[w]) roots.pop();
	}
      }
    if(v==roots.top()){
      brdg.pb(e);
      bcc.pb(vector<int>());
      while(1){
	int w=st.top(); st.pop(); inS[w]=0;
	bcc.back().pb(w);
	if(v==w) break;
      }
      roots.pop();
    }
  }
  
  Bcc(vv<int> &g,vector<pii> es){
    const int n=g.size();
    num.resize(n); inS.resize(n);
    int cnt=0;
    rep(i,n)if(!num[i]){
      dfs(g,es,i,-1);
      brdg.pop_back();
    }
    const int m=bcc.size();
    inv.resize(n);
    rep(i,m) for(const int &v:bcc[i]) inv[v]=i;
    for(pii &p:es){p.X=inv[p.X]; p.Y=inv[p.Y];}
    sort(all(es)); UNIQUE(es);
    tree.resize(m);
    for(const pii &p:es)if(p.X!=p.Y){
	tree[p.X].pb(p.Y);
	tree[p.Y].pb(p.X);
      }
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n;
  cin>>n;
  UF uf(n);
  vv<int> g(n);
  vector<pii> es(n);
  ll re=1;
  rep(i,n){
    int v;
    cin>>v; --v;
    uf.unite(i,v);
    g[i].pb(i);
    g[v].pb(i);
    es[i]=pii(i,v);
  }
  Bcc h(g,es);
  //cout<<h.bcc;
  for(const auto &v:h.bcc)
    if(v.size()>1){
      const int n=uf.size(v[0]);
      //cout<<pii(n,v.size())<<endl;
      (re*=(modpow(2,n)+MOD-modpow(2,n-v.size()+1))%MOD)%=MOD;
    }
  (re+=MOD)%=MOD;
  cout<<re<<endl;
  return 0;
}