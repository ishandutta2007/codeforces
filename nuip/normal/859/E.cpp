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
#define rreps(X,S,Y) for (int (X) = (Y)-1;(X) >= (S);--(X))
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
vector<string> s_p_l_i_t(const string &s, char c){vector<string> v;int d=0,f=0;string t;for(char c:s){if(!d&&c==',')v.pb(t),t="";else t+=c;if(c=='\"'||c=='\'')f^=1;if(!f&&c=='(')++d;if(!f&&c==')')--d;}v.pb(t);return move(v);}
void e_r_r(vector<string>::iterator it) {}
template<typename T, typename... Args> void e_r_r(vector<string>::iterator it, T a, Args... args){ if(*it==" 1"||*it=="1") cerr<<endl; else cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << ", "; e_r_r(++it, args...);}
const ll MOD=1e9+7;
typedef vv<int> Graph;
struct Scc{
  stack<int> S;
  vector<int> inS,low,num;
  int time;
public:
  Graph dag;
  vector<int> inv;
  vv<int> scc;
  void visit(const Graph &g, int v){
    low[v] = num[v] = ++time;
    S.push(v); inS[v]=1;
    for(const int  &w:g[v]) {
      if(!num[w]){
	visit(g,w);
	low[v]=min(low[v],low[w]);
      }else if(inS[w])
	low[v]=min(low[v],num[w]);
    }
    if(low[v]==num[v]){
      scc.push_back(vector<int>());
      while(1){
	int w = S.top(); S.pop(); inS[w]=0;
	scc.back().push_back(w);
	if (v==w) break;
      }
    }
  }
  Scc(const Graph &g) {
    const int n = g.size();
    num.resize(n); low.resize(n); inS.resize(n);
    rep(u,n) if(!num[u])
      visit(g,u);
    reverse(all(scc));
    
    inv.resize(n); dag.resize(n);
    rep(i,scc.size()) rep(j,scc[i].size())
      inv[scc[i][j]]=i;
    rep(i,scc.size()) rep(j,scc[i].size())
      for(auto e:g[scc[i][j]])
	if(inv[e] != i)
	  dag[i].pb(inv[e]);
  }
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
template <int mod=MOD> struct modInt{
  int v;
  modInt(int v=0):v(v){}
  modInt operator+(const modInt &n){return v+n.v<mod ? v+n.v : v+n.v-mod;}
  modInt operator-(const modInt &n){return v-n.v<0 ? v-n.v+mod : v-n.v;}
  modInt operator*(const modInt &n){return ll(v)*n.v%mod;}
  modInt operator/(const modInt &n){return ll(v)*modpow(n.v%mod,-1,mod)%mod;}
  modInt operator+(const ll &n){return v+n<mod ? v+n : v+n-mod;}
  modInt operator-(const ll &n){return v-n<0 ? v-n+mod : v-n;}
  modInt operator*(const ll &n){return ll(v)*(n%mod)%mod;}
  modInt operator/(const ll &n){return ll(v)*modpow(n%mod,-1,mod)%mod;}
  modInt& operator+=(const modInt &n){v+=n.v; if(v>=mod) v-=mod; return *this;}
  modInt& operator-=(const modInt &n){v-=n.v; if(v<0) v+=mod; return *this;}
  modInt& operator*=(const modInt &n){v=ll(v)*n.v%mod; return *this;}
  modInt& operator/=(const modInt &n){v=ll(v)*modpow(n.v,-1,mod)%mod; return *this;}
  modInt& operator+=(const ll &n){v+=n; if(v>=mod) v-=mod; return *this;}
  modInt& operator-=(const ll &n){v-=n; if(v<0) v+=mod; return *this;}
  modInt& operator*=(const ll &n){v=ll(v)*n%mod; return *this;}
  modInt& operator/=(const ll &n){v=ll(v)*modpow(n,-1,mod)%mod; return *this;}
};
template<int mod> ostream& operator<<(ostream &os,const modInt<mod> &n){return os<<n.v;};
template<int mod> modInt<mod> operator+(const ll &n,const modInt<mod> &m){return m.v+n<mod ? m.v+n : m.v+n-mod;}
template<int mod> modInt<mod> operator-(const ll &n,const modInt<mod> &m){return n-m.v<0 ? n-m.v+mod : n-m.v;}
template<int mod> modInt<mod> operator*(const ll &n,const modInt<mod> &m){return ll(m.v)*(n%mod)%mod;}
template<int mod> modInt<mod> operator/(const ll &n,const modInt<mod> &m){return ll(m.v)*modpow(n%mod,-1,mod)%mod;}
typedef modInt<MOD> mint;
template <int mod> modInt<mod> modpow(modInt<mod> r,ll n){ modInt<mod> re(1); if(n<0)(n%=mod-1)+=mod-1; for(;n;n/=2){if(n&1) re*=r; r*=r;} return re;}
vector<mint> fact,finv,inv;
mint comb(ll n,ll r){ if(n<r||r<0)return 0; return fact[n]*finv[n-r]*finv[r];}
class Doralion{
  void Modinvs(vector<mint> &re,int n){ re.resize(n+1); re[1]=1; for(int i=2;i<=n;++i)re[i]=re[MOD%i]*(MOD-MOD/i);}
  void Facts(vector<mint> &re,int n){ re.resize(n+1); re[0]=1; rep(i,n)re[i+1]=re[i]*(i+1);}
  void Factinvs(vector<mint> &re,const vector<mint> &inv,int n){ re.resize(n+1); re[0]=1; rep(i,n)re[i+1]=re[i]*inv[i+1];}
public:
  Doralion(int n){ Modinvs(inv,n); Facts(fact,n); Factinvs(finv,inv,n);}
} doralion(212345);
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

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
	int n;
	cin>>n;
	vv<int> g(2*n);
	UF uf(2*n);
	rep(i,n){
		int x,y;
		cin>>x>>y; --x; --y;
		uf.unite(x,y);
		g[y].pb(x);
	}
	vector<int> es(2*n);
	vector<int> ng(2*n);
	rep(i,2*n){
		es[uf.root(i)]+=g[i].size();
		for(int x:g[i])if(x==i) ng[uf.root(i)]=1;
	}
	mint re=1;
	rep(i,2*n)if(uf.root(i)==i && uf.size(i)>1 && ng[i]==0){
		if(es[i]==uf.size(i)){
			re*=2;
		}else if(es[i]+1==uf.size(i)){
			re*=uf.size(i);
		}
	}
	cout<<re<<endl;
  return 0;
}