//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define lfs cout<<fixed<<setprecision(10)
#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define UNIQUE(a) (a).erase(unique((a).begin(),(a).end()),(a).end())
#define spa << " " <<
#define fi first
#define se second
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define EB emplace_back
#define rep(i,n,m) for(ll i = (n); i < (ll)(m); i++)
#define rrep(i,n,m) for(ll i = (ll)(m) - 1; i >= (ll)(n); i--)
using ll = long long;
using ld = long double;
const ll MOD1 = 1e9+7;
const ll MOD9 = 998244353;
const ll INF = 1e18;
using P = pair<ll, ll>;
template<typename T> using PQ = priority_queue<T>;
template<typename T> using QP = priority_queue<T,vector<T>,greater<T>>;
template<typename T1, typename T2>bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
template<typename T1, typename T2>bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
ll median(ll a,ll b, ll c){return a+b+c-max({a,b,c})-min({a,b,c});}
void ans1(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}
void ans2(bool x){if(x) cout<<"YES"<<endl;else cout<<"NO"<<endl;}
void ans3(bool x){if(x) cout<<"Yay!"<<endl;else cout<<":("<<endl;}
template<typename T1,typename T2>void ans(bool x,T1 y,T2 z){if(x)cout<<y<<endl;else cout<<z<<endl;}  
template<typename T1,typename T2,typename T3>void anss(T1 x,T2 y,T3 z){ans(x!=y,x,z);};  
template<typename T>void debug(const T &v,ll h,ll w,string sv=" "){for(ll i=0;i<h;i++){cout<<v[i][0];for(ll j=1;j<w;j++)cout<<sv<<v[i][j];cout<<endl;}};
template<typename T>void debug(const T &v,ll n,string sv=" "){if(n!=0)cout<<v[0];for(ll i=1;i<n;i++)cout<<sv<<v[i];cout<<endl;};
template<typename T>void debug(const vector<T>&v){debug(v,v.size());}
template<typename T>void debug(const vector<vector<T>>&v){for(auto &vv:v)debug(vv,vv.size());}
template<typename T>void debug(stack<T> st){while(!st.empty()){cout<<st.top()<<" ";st.pop();}cout<<endl;}
template<typename T>void debug(queue<T> st){while(!st.empty()){cout<<st.front()<<" ";st.pop();}cout<<endl;}
template<typename T>void debug(deque<T> st){while(!st.empty()){cout<<st.front()<<" ";st.pop_front();}cout<<endl;}
template<typename T>void debug(PQ<T> st){while(!st.empty()){cout<<st.top()<<" ";st.pop();}cout<<endl;}
template<typename T>void debug(QP<T> st){while(!st.empty()){cout<<st.top()<<" ";st.pop();}cout<<endl;}
template<typename T>void debug(const set<T>&v){for(auto z:v)cout<<z<<" ";cout<<endl;}
template<typename T>void debug(const multiset<T>&v){for(auto z:v)cout<<z<<" ";cout<<endl;}
template<typename T,size_t size>void debug(const array<T, size> &a){for(auto z:a)cout<<z<<" ";cout<<endl;}
template<typename T,typename V>void debug(const map<T,V>&v){for(auto z:v)cout<<"["<<z.first<<"]="<<z.second<<",";cout<<endl;}
template<typename T>vector<vector<T>>vec(ll x, ll y, T w){vector<vector<T>>v(x,vector<T>(y,w));return v;}
ll gcd(ll x,ll y){ll r;while(y!=0&&(r=x%y)!=0){x=y;y=r;}return y==0?x:y;}
vector<ll>dx={1,-1,0,0,1,1,-1,-1};vector<ll>dy={0,0,1,-1,1,-1,1,-1};
template<typename T>vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v(ts...))>(a,make_v(ts...));}
template<typename T1, typename T2>ostream &operator<<(ostream &os, const pair<T1, T2>&p){return os << p.first << " " << p.second;}
template<typename T>ostream &operator<<(ostream &os, const vector<T> &v){for(auto &z:v)os << z << " ";cout<<"|"; return os;}
template<typename T>void rearrange(vector<int>&ord, vector<T>&v){
  auto tmp = v;
  for(int i=0;i<tmp.size();i++)v[i] = tmp[ord[i]];
}
template<typename Head, typename... Tail>void rearrange(vector<int>&ord,Head&& head, Tail&&... tail){
  rearrange(ord, head);
  rearrange(ord, tail...);
}
template<typename T> vector<int> ascend(const vector<T>&v){
  vector<int>ord(v.size());iota(ord.begin(),ord.end(),0);
  sort(ord.begin(),ord.end(),[&](int i,int j){return v[i]<v[j];});
  return ord;
}
template<typename T> vector<int> descend(const vector<T>&v){
  vector<int>ord(v.size());iota(ord.begin(),ord.end(),0);
  sort(ord.begin(),ord.end(),[&](int i,int j){return v[i]>v[j];});
  return ord;
}
ll FLOOR(ll n,ll div){assert(div>0);return n>=0?n/div:(n-div+1)/div;}
ll CEIL(ll n,ll div){assert(div>0);return n>=0?(n+div-1)/div:n/div;}
ll digitsum(ll n){ll ret=0;while(n){ret+=n%10;n/=10;}return ret;}
template<typename T>T min(const vector<T>&v){return *min_element(v.begin(),v.end());}
template<typename T>T max(const vector<T>&v){return *max_element(v.begin(),v.end());}
template<typename T>T acc(const vector<T>&v){return accumulate(v.begin(),v.end(),T(0));};
template<typename T>T reverse(const T &v){return T(v.rbegin(),v.rend());};
//mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
int popcount(ll x){return __builtin_popcountll(x);};
int poplow(ll x){return __builtin_ctzll(x);};
int pophigh(ll x){return 63 - __builtin_clzll(x);};
template<typename T>T poll(queue<T> &q){auto ret=q.front();q.pop();return ret;};
template<typename T>T poll(priority_queue<T> &q){auto ret=q.top();q.pop();return ret;};
template<typename T>T poll(QP<T> &q){auto ret=q.top();q.pop();return ret;};
template<typename T>T poll(stack<T> &s){auto ret=s.top();s.pop();return ret;};
ll MULT(ll x,ll y){if(LLONG_MAX/x<=y)return LLONG_MAX;return x*y;}
ll POW2(ll x, ll k){ll ret=1,mul=x;while(k){if(mul==LLONG_MAX)return LLONG_MAX;if(k&1)ret=MULT(ret,mul);mul=MULT(mul,mul);k>>=1;}return ret;}
ll POW(ll x, ll k){ll ret=1;for(int i=0;i<k;i++){if(LLONG_MAX/x<=ret)return LLONG_MAX;ret*=x;}return ret;}
template< typename T = int >
struct edge {
  int to;
  T cost;
  int id;
  edge():id(-1){};
  edge(int to, T cost = 1, int id = -1):to(to), cost(cost), id(id){}
  operator int() const { return to; }
};

template<typename T>
using Graph = vector<vector<edge<T>>>;
template<typename T>
Graph<T>revgraph(const Graph<T> &g){
  Graph<T>ret(g.size());
  for(int i=0;i<g.size();i++){
    for(auto e:g[i]){
      int to = e.to;
      e.to = i;
      ret[to].push_back(e);
    }
  }
  return ret;
}
template<typename T>
Graph<T> readGraph(int n,int m,int indexed=1,bool directed=false,bool weighted=false){
  Graph<T> ret(n);
  for(int es = 0; es < m; es++){
    int u,v;
    T w=1;
    cin>>u>>v;u-=indexed,v-=indexed;
    if(weighted)cin>>w;
    ret[u].emplace_back(v,w,es);
    if(!directed)ret[v].emplace_back(u,w,es);
  }
  return ret;
}
template<typename T>
Graph<T> readParent(int n,int indexed=1,bool directed=true){
  Graph<T>ret(n);
  for(int i=1;i<n;i++){
    int p;cin>>p;
    p-=indexed;
    ret[p].emplace_back(i);
    if(!directed)ret[i].emplace_back(p);
  }
  return ret;
}
template<typename T, typename F>
struct DisjointSparseTable{
  int n;
  vector<vector<T>>data;
  const F func;
  DisjointSparseTable(vector<T>&v, const F &f):func(f),n(v.size()){
    int num=0;
    while((1<<num)<v.size())num++;
    data.assign(num+5,vector<T>(n+1, T()));
    if(n>=1)data[0][n-1]=v[n-1];
    for(int i=1;i<n;i++){
      int k = __builtin_ctz(i);
      data[k][i-1]=v[i-1];
      if(i!=n)data[k][i]=v[i];
      int l=i-(1<<k),r=min(n,i+(1<<k));
      for(int j=i-2;j>=l;j--)data[k][j]=func(v[j],data[k][j+1]);
      for(int j=i+1;j<r;j++)data[k][j]=func(data[k][j-1],v[j]);
    }
  }
  T query(int l,int r){//[l,r)
    r--;
    if(l==r)return data[0][l];
    ll k=31-__builtin_clz(l^r);
    return func(data[k][l],data[k][r]);
  }
};
template<typename T>
struct HLD{
  using D=long long;
  int n;
  vector<int>sz;//
  vector<D>dep;
  vector<int>par;
  vector<int>head;
  Graph<T> &g;//
  vector<edge<T>>edges;//edge
  vector<int>in,out;//[in,out)[ina,inb]a~b(a)
  vector<int>comp;//
  //inindexedge
  HLD(Graph<T> &g,int r=-1):g(g),n(g.size()){
    hld_build(r);
  }
  void hld_build(int root = -1){
    in.assign(n,-1);out.assign(n,-1);dep.assign(n,0);
    par.assign(n,-1);head.assign(n,-1);sz.assign(n,-1);comp.assign(n,-1);
    edges.assign(n,edge<T>());
    if(root == -1){//()
      for(int i=0;i<n;i++){
        if(sz[i] == -1){
          head[i] = i;
          dfs_sz(i, 0, i);
          dfs_hld(i);
        }
      }
    }
    else{
      head[root] = root;
      dfs_sz(root, 0, root);
      dfs_hld(root);
    }
  }
  void dfs_sz(int k, D d,int r){
    sz[k] = 1;
    comp[k] = r;
	dep[k] = d;
    for(auto &e: g[k]){
      if(e.to == par[k])continue;
      par[e.to] = k;
      dfs_sz(e.to, d+e.cost, r);
      sz[k] += sz[e.to];
      if(sz[e.to] > sz[g[k][0].to])swap(e, g[k][0]);
    }
  }
  int time = 0;
  void dfs_hld(int k){
    in[k] = time++;
    for(auto e:g[k]){
      if(e.to == par[k])continue;
      head[e.to] = (e.to == g[k][0].to ? head[k]: e.to);
      edges[time] = e;
      dfs_hld(e.to);
    }
    out[k] = time;
  }
  int lca(int p,int q){
    while(1){
      if(in[p] < in[q])swap(p,q);
      if(head[p] == head[q])return q;
      p = par[head[p]];
    }
  }
  vector<pair<int,int>>query_path(int p,int q,bool isEdge){
    int r=lca(p,q);
    vector<pair<int,int>>ret;
    for(int i=0;i<2;i++){
      if(i == 1)swap(p,q);
      while(1){
        if(isEdge&&p==r)break;
        if(head[p]==head[r]){
          ret.emplace_back(in[r]+(isEdge?1:i),in[p]+1);
          break;
        }
        ret.emplace_back(in[head[p]],in[p]+1);
        p = par[head[p]];
      }
    }
    return ret;
  }
  vector<vector<pair<int,int>>>query_order_path(int p,int q,bool isEdge){
	//01
    vector<vector<pair<int,int>>>ret(2);
    int r=lca(p,q);
    for(int i=0;i<2;i++){
      if(i == 1)swap(p,q);
      while(1){
        if(isEdge&&p==r)break;
        if(head[p]==head[r]){
          if(i==0) ret[i].emplace_back(n-(in[p]+1),n-(in[r]+(isEdge?1:i)));
          else ret[i].emplace_back(in[r]+(isEdge?1:i),in[p]+1);
          break;
        }
        if(i==0) ret[i].emplace_back(n-(in[p]+1),n-(in[head[p]]));
        else ret[i].emplace_back(in[head[p]],in[p]+1);
        p = par[head[p]];
      }
    }
    reverse(ret[1].begin(), ret[1].end());
    return ret;
  }
  pair<int,int>query_subtree(int p,bool isEdge){
    return make_pair(in[p]+isEdge,out[p]);
  }
  //uv (in,out)
  int child(int u,int v){
    while(1){
      if(head[u]==head[v]){
        v=g[u][0].to;
        break;
      }
      v=head[v];
      if(par[v]==u)break;
      v=par[v];
    }
    return v;
  }
  //uv
  int move(int u,int v){
    assert(u!=v);
    if(in[u]<in[v]&&in[v]<out[u])return child(u,v);
    else return par[u];
  }
  D dist(int u,int v){
    return dep[u]+dep[v]-2*dep[lca(u,v)];
  }
  vector<int>rev_in;
  int climb(int u,int k){
    if(rev_in.empty()){
      rev_in.resize(n);
      for(int i=0;i<n;i++)rev_in[in[i]]=i;
    }
    int nd=max<int>(dep[u]-k, 0);
    while(dep[u]>nd){
      if(dep[head[u]]>nd){
        u=par[head[u]];
      }
      else{
        u=rev_in[in[head[u]]+nd-dep[head[u]]];
      }
    }
    return u;
  }
  template<typename I>
  Graph<T>lca_tree(vector<I>&v){
    auto compare=[&](int x,int y){return in[x]<in[y];};
    sort(v.begin(),v.end(),compare);
    int sz1=v.size();
    for(int i=0;i<sz1-1;i++)v.push_back(lca(v[i],v[i+1]));
    sort(v.begin(),v.end(),compare);
    v.erase(unique(v.begin(),v.end()),v.end());
    int sz2=v.size();
    Graph<T>ret(sz2);
    stack<int>st;
    for(int i=0;i<sz2;i++){
      while(!st.empty()&&out[v[st.top()]]<=in[v[i]])st.pop();
      if(!st.empty())ret[st.top()].emplace_back(i,dep[v[i]]-dep[v[st.top()]]);
      st.push(i);
    }
    return ret;
  }
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n,q;cin>>n>>q;
  vector<ll>a(n);
  rep(i,0,n)cin>>a[i];
  auto g=readGraph<int>(n,n-1);
  vector<int>in(n),rev(2*n+5);
  vector<int>lv;
  {
    ll cnt=0;
    auto dfs=[&](auto &&f,ll k,ll par)->void{
      in[k]=lv.size();
      rev[in[k]]=k;
      lv.PB(in[k]);
      for(auto to:g[k]){
        if(to==par)continue;
        f(f,to,k);
        lv.PB(in[k]);
      }
    };
    dfs(dfs,0,-1);
  }
  auto mif=[&](int x,int y){return min(x,y);};
  DisjointSparseTable dst(lv,mif);
  auto lca=[&](int x,int y){
    if(in[x]>in[y])swap(x,y);
    return rev[dst.query(in[x],in[y]+1)];
  };
  HLD hld(g,0);
  //ll lim=max<ll>(1LL,(ll)sqrt(q));
  ll lim=250;
  //ll lim=3;
  vector<ll>cum(n+1);
  vector<P>upd,restore;
  auto ord=ascend(hld.in);
  auto build=[&](){
    for(auto z:upd)a[z.fi]=z.se;
    upd.clear();
    restore.clear();
    fill(ALL(cum),0);
    rep(i,1,n){
      int x=hld.par[ord[i]],y=ord[i];
      cum[i+1]+=max(abs(a[x]+a[y]),abs(a[x]-a[y]));
    }
    rep(i,0,n)cum[i+1]+=cum[i];
  };
  build();
  while(q--){
    ll type;cin>>type;
    if(type==1){
      ll u,c;cin>>u>>c;u--;
      restore.EB(u,a[u]);
      upd.EB(u,c);
      if(upd.size()>=lim)build();
      continue;
    }
    ll u,v;cin>>u>>v;u--;v--;
    ll ret=0;
    auto tmp=hld.query_path(u,v,true);
    for(auto z:tmp)ret+=cum[z.se]-cum[z.fi];
    for(auto z:upd){
      if(lca(u,z.fi)!=z.fi&&lca(v,z.fi)!=z.fi)continue;
      if(lca(u,v)!=lca(u,z.fi)&&lca(u,v)!=lca(v,z.fi))continue;
      for(auto x:{u,v}){
        if(x==z.fi)continue;
        auto to=hld.move(z.fi,x);
        //cout<<z.fi spa to<<endl;
        ret-=max(abs(a[z.fi]+a[to]),abs(a[z.fi]-a[to]));
      }
      a[z.fi]=z.se;
      for(auto x:{u,v}){
        if(x==z.fi)continue;
        auto to=hld.move(z.fi,x);
        ret+=max(abs(a[z.fi]+a[to]),abs(a[z.fi]-a[to]));
      }
    }
    rrep(x,0,restore.size())a[restore[x].fi]=restore[x].se;
    cout<<ret<<endl;
  }
  //debug(a);build();debug(a);
  /*rep(i,0,n)rep(j,i,n){
    cout<<i+1 spa j+1 spa lca(i,j)+1<<endl;
  }*/
  return 0;
}