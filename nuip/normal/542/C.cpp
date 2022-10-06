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
#define rrep(X,Y) for (int (X) = (Y-1);(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> using vv=vector<vector<T>>;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
typedef int Weight;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(int src, int dst, Weight weight) :
    src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

void ccdfs(Graph &g,vector<int> &cc,vector<int> &usd,int v){
  //cout<<v<<cc;
  if(usd[v])return;
  usd[v]=1;
  cc.pb(v);
  for(const Edge &e:g[v])if(!usd[e.dst])
    ccdfs(g,cc,usd,e.dst);
}
void CC(Graph &h,vv<int> &cc){
  int n=h.size();
  vector<int> usd(n);
  Graph g=h;
  rep(i,n)for(const Edge &e:h[i])
    g[e.dst].pb(Edge(e.dst,e.src,e.weight));
  /*  rep(i,n){
    cout<<"{";for(auto e:g[i])cout<<pii(e.src,e.dst);
    cout<<"}"<<endl;}*/
  rep(i,n)if(!usd[i]){
    cc.pb(vector<int>());
    ccdfs(g,cc.back(),usd,i);
  }
}
ll dfs(Graph &g,vector<int> &usd,vector<ll> &dst,int v){
  if(usd[v]==1) return -v-1;
  if(usd[v]==2) return dst[v];
  usd[v]=1;
  ll re=dfs(g,usd,dst,g[v][0].dst);
  //cout<<v<<","<<g[v][0].dst<<":"<<re<<","<<v+re<<endl;
  if(re<0){
    dst[v]=0;
    usd[v]=2;
    return (v+re!=-1)?re:0;
  }else{
    ++re;
    dst[v]=re;
    usd[v]=2;
    return re;
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int i,j,k,n;
  cin>>n;
  Graph g(n);
  vector<int> usd(n);
  rep(i,n){
    cin>>k;
    --k;
    g[i].pb(Edge(i,k,0));
  }
  vv<int> cc;
  CC(g,cc);
  //cout<<cc<<endl;
  ll a=0,b=1;
  vector<ll> dst(n);
  for(vector<int> &v:cc){
    ll m=v.size(),tmp;
    rep(i,m)if(!usd[v[i]]){
      dfs(g,usd,dst,v[i]);
    }
    //cout<<v<<usd<<dst<<endl;
    tmp=0;
    rep(i,m) tmp=max(tmp,dst[v[i]]);
    a=max(tmp,a);
    tmp=0;
    rep(i,m)tmp+=(dst[v[i]]==0);
    b*=tmp/__gcd(tmp,b);
  }
  //cout<<a<<","<<b<<endl;
  cout<<max(b,(a+b-1)/b*b)<<endl;
  return 0;
}