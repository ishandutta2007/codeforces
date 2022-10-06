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
#define Endl endl

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
#define out(args...){vector<string> a_r_g_s=s_p_l_i_t(#args, ','); e_r_r(a_r_g_s.begin(), args); }
vector<string> s_p_l_i_t(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while(getline(ss,x,c)) v.emplace_back(x); return move(v);}
void e_r_r(vector<string>::iterator it) {}
template<typename T, typename... Args> void e_r_r(vector<string>::iterator it, T a, Args... args){ if(*it==" 1"||*it=="1") cerr<<endl; else cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << ", "; e_r_r(++it, args...);}
const ll MOD=1e9+7;
//weekly014D

const ll INF=2e18;

struct Seg{
  ll v;
  Seg(ll val=1){
    v=val;
  }
  static Seg e;
};
Seg Seg::e=Seg();
ostream& operator<<(ostream &os, const Seg &t) { return os<<"["<<t.v<<"]";}

Seg operator+(Seg l,Seg r){
  if(!l.v) return l;
  if(INF/l.v<=r.v) return Seg(INF);
  return Seg(min(INF,l.v*r.v));
}

template<class T> void upd(vector<T> &dat,int k,ll a){
  k+=dat.size()/2-1;
  dat[k].v=a;
  while(k>0){
    k=(k-1)/2;
    dat[k]=dat[k*2+1]+dat[k*2+2];
  }
}

//(l,r,0,0,nn)
template<class T> T query(vector<T> &dat,int a,int b,int k=0,int l=0,int r=-1){
  if(r<0) r=dat.size()/2;
  T re=T::e;
  if(r<=a || b<=l){
    re=T::e;
  }
  else if(a<=l && r<=b)re= dat[k];
  else{
    re= query(dat,a,b,k*2+1,l,(l+r)/2) ;
      T tmp=query(dat,a,b,k*2+2,(l+r)/2,r);
      //cout<<re<<tmp<<re+tmp<<endl;;
    re=re+tmp;
  }
  //cout<<"ans"<<k<<pii(l,r)<<re<<endl;
  return re;
}
template<class T> class RMQ{
  vv<T> vals;
public:
  inline T get(int l,int r){//[l,r]
    if(l==r)return vals[0][l];
    const int d=31-__builtin_clz(l^r); //left-most distinct bit
    return min(vals[d][l],vals[d][r]);
  }
  RMQ(){};
  RMQ(vector<T> &v,T e=-MOD){ init(v,e); }
  void init(vector<T> &v,T e){
    int n=v.size();
    int d=1,N=2;
    while(N<n) N*=2, ++d;
    vals.resize(d,vector<T>(N,e));
    rep(i,n) vals[0][i]=v[i];
    reps(i,1,d)rep(j,N){
      const int b=(j>>i|1)<<i;
      vals[i][j]=j>>i&1?get(b,j):get(j,b-1);
    }
  }
};

typedef vv<int> Graph;
class Lca{
public:
  vector<int> dep,cld;
  vector<pii> et;
  vector<int> l,r;
  vector<ll> wdep;
  vector<int> par;
  const int LOGN=20;
  int weighted;
  vv<int> wei;
  RMQ<pii> rmq;
  void dfs(const Graph &g,int root){
    int n=g.size();
    vector<int> vst(n);
    stack<int> st; st.push(root);
    while(!st.empty()){
      int v=st.top(); st.pop();
      if(vst[v]==1){
	vst[v]=2;
	r[v]=et.size()-1;
	rep(i,g[v].size())if(g[v][i]!=par[v])
	  cld[v]+=cld[g[v][i]]+1;
	if(par[v]>=0) et.eb(dep[par[v]],par[v]);
      }else if(vst[v]==0){
	st.push(v);
	vst[v]=1;
	l[v]=et.size(); et.eb(dep[v],v);
	rep(i,g[v].size())if(!vst[g[v][i]]){
	  dep[g[v][i]]=dep[v]+1;
	  wdep[g[v][i]]=wdep[v]+(weighted?wei[v][i]:1);
	  par[g[v][i]]=v;
	  st.push(g[v][i]);
	}
      }
    }
  }
  
  Lca(const Graph &g):weighted(0){
    int n=g.size();
    par.resize(n);
    dep.resize(n); wdep.resize(n); cld.resize(n); l.resize(n); r.resize(n); dfs(g,0);
    rmq.init(et,pii(MOD,0));
    // rep(i,LOGN-1)rep(v,n)
    //   par[v][i+1]=par[v][i]<0?-1:par[par[v][i]][i];
  }
  Lca(const vv<pii> &h):weighted(1){
    int n=h.size();
    vv<int> g(n);
    wei.resize(n);
    rep(i,n) for(pii x:h[i]){
      g[i].pb(x.X);
      wei[i].pb(x.Y);
    }
    par.resize(n);
    dep.resize(n); wdep.resize(n); cld.resize(n); l.resize(n); r.resize(n); dfs(g,0);
    rmq.init(et,pii(MOD,0));
    // rep(i,LOGN-1)rep(v,n)
    //   par[v][i+1]=par[v][i]<0?-1:par[par[v][i]][i];
  }
  
  int LCA(int v,int w){
    v=l[v]; w=l[w];
    if(v>w) swap(v,w);
    return rmq.get(v,w).Y;
  }
  ll dist(int v,int w){return wdep[v]+wdep[w]-2*wdep[LCA(v,w)];}
};

class HL{
  Lca lcaTree;
  vector<pii> parh;
  int isEdge,n;
public:
  vv<int> mems,edgel;
  vector<pii> inv;
  vv<int> h;
  vector<int> hvy,par,etov;
  vv<Seg> dats;
  void dfs2(const Graph &g,int v,int p,vector<int> &usd,vector<int> &mem,vector<int> &edges,vector<int> &edgel){
    while(1){
      if(usd[v])return;
      usd[v]=1; mem.pb(v);
      edgel.pb(edges.size());
      if(g[v].size()==1 && p>=0)
	return;
      rep(i,g[v].size())if(g[v][i]!=p && i!=hvy[v])
	edges.pb(g[v][i]);
      p=v; v=g[v][hvy[v]];
    }
  }
  void HLDec(const Graph &g){
    int n=g.size();
    inv.resize(n);
    vector<int> usd(n);
    rep(i,n)if(!usd[i]){
      mems.pb(vector<int>()); h.pb(vector<int>()); edgel.pb(vector<int>());
      dfs2(g,i,par[i],usd,mems.back(),h.back(),edgel.back());
      rep(j,mems.back().size())
	inv[mems.back()[j]]=pii(h.size()-1,j);
    }
    rep(i,h.size())for(int &v:h[i]) v=inv[v].X;
  }
  void dfs(const Graph &g){
    int n=g.size();
    hvy.resize(n); par.resize(n,-1);
    vector<pii> mx(n);
    vector<int> sum(n,1),vst(n);
    stack<int> st; st.push(0);
    while(!st.empty()){
      int v=st.top(); st.pop();
      if(vst[v]==1){
	vst[v]=2;
	rep(i,g[v].size())if(g[v][i]!=par[v]){
	  sum[v]+=sum[g[v][i]];
	  mx[v]=max(mx[v],pii(sum[g[v][i]],i));
	}
	hvy[v]=mx[v].Y;
      }else if(vst[v]==0){
	st.push(v); vst[v]=1;
	rep(i,g[v].size())if(!vst[g[v][i]]){
	  par[g[v][i]]=v;
	  st.push(g[v][i]);
	}
      }
    }
  }

  void constSegTree(const vector<Seg> &vals){
    int m=h.size();
    dats.resize(m);
    rep(i,m){
      int nn=1;
      while(nn<mems[i].size()) nn<<=1;
      dats[i].resize(2*nn,Seg());
      rep(j,mems[i].size())
	dats[i][nn-1+j]=vals[mems[i][j]];
      rrep(j,nn-1) dats[i][j]=dats[i][2*j+1]+dats[i][2*j+2];
    }
    parh.resize(m,pii(-1,0));
    rep(i,n)if(inv[i].Y==0 && i){
      parh[inv[i].X]=inv[lcaTree.par[i]];
    }
  }
  void HLcommon(const Graph &g,const vector<Seg> &vals){
    n=g.size();
    dfs(g);
    HLDec(g);
    constSegTree(vals);
  }
  HL(const Graph &g,const vector<Seg> &vals):lcaTree(g){
    isEdge=0;
    HLcommon(g,vals);
  }
  HL(const Graph &g,const vector<pii> &es,const vector<Seg> &val):lcaTree(g){
    n=g.size();
    isEdge=1;
    etov.resize(n);
    vector<Seg> vals(n);
    rep(i,n-1){
      if(lcaTree.dep[es[i].X]>lcaTree.dep[es[i].Y])
	etov[i]=es[i].X;
      else
	etov[i]=es[i].Y;
      vals[etov[i]]=val[i];
    }
    HLcommon(g,vals);
  }
  //  HL(Graph &g,
  //mems : v_h -> v_g list
  //edgel: v_g listi~qh[v]o
  //inv  : v_g -> v_h

  //~
  Seg sumV(vv<Seg> &dats,int lca,int cld,int clopen){
    if(lca<0 || cld<0)return Seg::e;
    Seg re=Seg::e;
    for(pii pos=inv[cld];pos.X!=-1;pos=parh[pos.X]){
      if(pos.X==inv[lca].X){
	re=query(dats[pos.X],inv[lca].Y+clopen,pos.Y+1)+re;
	break;
      }else{
	re=query(dats[pos.X],0,pos.Y+1)+re;
      }
      //cout<<pos<<":"<<re<<endl;
    }
    return re;
  }

  Seg sum(int a,int b){
    int lca=lcaTree.LCA(a,b);
    return sumV(dats,lca,a,1)+sumV(dats,lca,b,isEdge);
  }
};
typedef pair<pii,ll> piii;
typedef vv<int> Graph;

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n,q;
  cin>>n>>q;
  vv<int> g(n);
  vector<Seg> vals(n);
  vector<pii> es(n);
  ll x,y,z;
  rep(i,n-1){
    cin>>x>>y>>z; --x; --y;
    g[y].eb(x);
    g[x].eb(y);
    vals[i]=Seg(z);
    es[i]=pii(x,y);
  }
  Lca lca(g);

  //cout<<vals;

  HL hl(g,es,vals);

  while(q--){
    int t;
    cin>>t;
    if(t==1){
      ll a,b,y;
      cin>>a>>b>>y; --a; --b;
      int lc=lca.LCA(a,b);
      Seg re=hl.sum(a,b);
      cout<<y/re.v<<endl;
    }else{
      ll p,c;
      cin>>p>>c; --p;
      int v=hl.etov[p];
      pii t=hl.inv[v];
      //cout<<v<<dats[t.X];
      upd(hl.dats[t.X],t.Y,c);
      vals[v]=c;
      //cout<<dats[t.X];
    }
  }
  return 0;
}