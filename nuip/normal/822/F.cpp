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

vv<int> g;
vector<pii> es;
vector<double> ans; //[0,2)
const double EPS=1e-8;

void dfs(int v,int pe){
  int d=g[v].size();
  double ad=2./d;
  double cur=(pe<0?0:(es[pe].X==v?ans[pe]+1:ans[pe]));
  if(cur>=2-EPS) cur-=2;
  for(int e:g[v])if(e!=pe){
      cur+=ad;
      if(cur>=2-EPS) cur-=2;
      double tmp=cur;
      ans[e]=(es[e].X==v?tmp+1:tmp);
      if(ans[e]>=2-EPS) ans[e]-=2;
      dfs(es[e].X+es[e].Y-v,e);
    }
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(10);
  int n;
  cin>>n;
  g.resize(n);
  es.resize(n-1);
  ans.resize(n-1);
  rep(i,n-1){
    int x,y;
    cin>>x>>y; --x; --y;
    g[x].pb(i); g[y].pb(i);
    es[i]=pii(x,y);
  }
  dfs(0,-1);
  cout<<n-1<<endl;
  rep(i,n-1){
    cout<<"1 "<<i+1<<" ";
    if(ans[i]>1){
      swap(es[i].X,es[i].Y);
      ans[i]-=1;
    }
    cout<<es[i].X+1<<" "<<es[i].Y+1<<" "<<ans[i]<<endl;
  }
  return 0;
}