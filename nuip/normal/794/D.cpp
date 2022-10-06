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

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n,m;
  cin>>n>>m;
  vv<int> neig(n);
  rep(i,n) neig[i].pb(i);
  vector<pii> es; es.reserve(m);
  rep(i,m){
    int x,y;
    cin>>x>>y; --x; --y;
    es.eb(x,y);
    neig[x].pb(y);
    neig[y].pb(x);
  }
  rep(i,n) sort(all(neig[i]));
  vv<int> id=neig; sort(all(id)); UNIQUE(id);
  vector<int> re(n);
  rep(i,n) re[i]=lower_bound(all(id),neig[i])-id.begin();
  vector<int> cc(id.size());
  rep(i,n) cc[re[i]]++;
  map<pii,int> cnt;
  for(pii p:es){
    int x=re[p.X],y=re[p.Y];
    if(x>y) swap(x,y);
    ++cnt[pii(x,y)];
  }
  int f=0;
  rep(i,id.size())if(!(cc[i]==1 || cnt.count(pii(i,i)))) f=1;
  vv<int> g(id.size());
  for(auto pp:cnt){
    pii p=pp.X;
    if(p.X==p.Y){
      if(pp.Y != cc[p.X]*(cc[p.Y]-1ll)/2) f=2;
    }else{
      if(pp.Y != 1ll*cc[p.X]*cc[p.Y]) f=3;
      g[p.X].pb(p.Y);
      g[p.Y].pb(p.X);
    }
  }
  vector<int> xs(id.size());
  int num=1;
  rep(i,id.size())if(xs[i]==0 && g[i].size()<=1){
    xs[i]=num++;
    if(g[i].size()==1){
      for(int v=g[i][0],pre=i;;){
	if(g[v].size()>2 || xs[v]){
	  f=1;
	  break;
	}
	xs[v]=num++;
	if(g[v].size()==1) break;
	int tmp=v;
	v=g[v][0]+g[v][1]-pre;
	pre=tmp;
      }
    }
    if(f) break;
    ++num;
  }
  rep(i,id.size()) if(xs[i]==0) f=1;
  //out(neig,re,cc,g,f,xs,1);
  if(f){
    cout<<"NO"<<endl;
  }else{
    cout<<"YES"<<endl;
    rep(i,n) cout<<xs[re[i]]<<" ";cout<<endl;
  }
  return 0;
}