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
struct RMQ{
  const int INF=MOD;
  vv<int> mn;
  int D;
  void upd(const vector<int> &v){
    mn.clear();
    D=0;
    for(int i=v.size();i;i/=2) ++D;
    mn.resize(D+1,vector<int>(1<<D+1,INF));
    rep(i,v.size()) mn[D][i]=v[i];
    rrep(i,D)rep(j,1<<D){
      int b=(j>>(D-i)|1)<<(D-i);
      //assert(b!=(1<<D) || !(j>>(D-i)&1));
      if(b>(1<<D+1)) cout<<"["<<b<<"]"<<pii(i,j)<<endl;
      mn[i][j]=j>>(D-i)&1?get(b,j+1):get(j,b);
    }
  }
  RMQ(){}
  RMQ(const vector<int> &v){upd(v);}
  int get(int l,int r){ //[l,r)
    --r;
    if(l==r)return mn[D][l];
    if(l>r) return INF;
    int d=__builtin_clz(l^r)+D-31;
    if(!(d<=D && max(l,r)<=(1<<D+1))) cout<<pii(l,r)<<"!!"<<endl;
    assert((d<=D));
    assert(l<=(1<<D+1));
    assert((r<=(1<<D+1)));
    return min(mn[d][l],mn[d][r]);
  }
};

// Larsson-Sadakane's Suffix array Construction: O(n (log n)^2)
struct SA:public vector<int>{
  struct SAComp {
    const int h;
    const vector<int> &g;
    SAComp(int h, const vector<int> &g) : h(h), g(g) {}
    bool operator() (int a, int b) {
      return a == b ? false : g[a] != g[b] ? g[a] < g[b] : g[a+h] < g[b+h];
    }
  };
  vector<int> inv,lcp;
  string str;
  RMQ rmq;
  SA(){}
  SA(const string &str):str(str){build(str);}
  void build(const string &s){
    str=s;
    buildSA();
    buildLCP();
    inv.resize(size());
    rep(i,size()) inv[at(i)]=i;
  }
  void buildSA(){
    int n=str.size();
    vector<int> g(n+1),b(n+1);
    resize(n+1);
    rep(i,n+1) at(i)=i, g[i]=str[i];
    
    sort(all(*this), SAComp(0,g));
    for(int h=1; b[n]!=n; h*=2) {
      SAComp comp(h,g);
      sort(all(*this),comp);
      rep(i,n) b[i+1]=b[i]+comp(at(i),at(i+1));
      rep(i,n+1) g[at(i)]=b[i];
    }
  }
  void buildLCP(){
    int n=str.size();
    int h=0;
    vector<int> b(n+1);
    lcp.resize(n+1);
    rep(i,n+1) b[at(i)]=i;
    rep(i,n+1) {
      if(b[i]){
	for (int j=at(b[i]-1); j+h<n && i+h<n && str[j+h]==str[i+h]; ++h);
	lcp[b[i]]=h;
      } else lcp[b[i]]=-1;
      if (h>0) --h;
    }
  }
  
  int getMn(int l,int r){return rmq.get(l+1,r+1);}
};
ostream& operator<<(ostream &os,const SA &sa){
  rep(i,sa.size()) os<<sa.lcp[i]<<"\t"<<sa.str.substr(sa[i])<<endl;
  return os;
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int T;
  cin>>T;
  while(T--){
    string s;
    cin>>s;
    int n=s.size();
    SA sa(s);
    //cout<<sa;
    vector<pii> stk;
    ll re=0;
    int sum=0;
    reps(i,1,n+1){
      while(sum>sa.lcp[i]){
	if(stk.back().Y<=sum-sa.lcp[i]){
	  re+=1ll*(i-stk.back().X)*(i-stk.back().X)*stk.back().Y;
	  sum-=stk.back().Y;
	  stk.pop_back();
	}else{
	  re+=1ll*(i-stk.back().X)*(i-stk.back().X)*(sum-sa.lcp[i]);
	  stk.back().Y-=sum-sa.lcp[i]; sum-=sum-sa.lcp[i];
	}
      }
      stk.eb(i,n-sa[i]-sa.lcp[i]); sum+=n-sa[i]-sa.lcp[i];
      //out(stk,1);
    }
    for(pii p:stk) re+=(n+1ll-p.X)*(n+1ll-p.X)*p.Y;
    cout<<re<<endl;
  }
  return 0;
}