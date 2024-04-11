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
const int INF=MOD;
template<class T,class G>
void dij(vv<pair<G,T>> &g,int s,vector<T> &d){
  typedef pair<T,G> Que;
  priority_queue<Que,vector<Que>,greater<Que> > que;
  int n=g.size();
  d.resize(n);
  fill(all(d),INF);
  d[s]=0;
  que.emplace(0,s);
  while(que.size()){
    Que p=que.top();que.pop();
    if(d[p.Y]<p.X)continue;
    for(auto e:g[p.Y]) if(MN(d[e.X],d[p.Y]+e.Y)) que.emplace(d[e.X],e.X);
  }
}
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
void add(vv<pii> &g,int x,int y,int c){
  g[x].eb(y,c); g[y].eb(x,c);
}
int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n,m,t;
  cin>>n>>m>>t;
  vv<pii> g(t+n+m);
  map<pii,int> id;
  vector<int> neig;
  rep(i,t){
    int x,y;
    cin>>y>>x; --y; --x;
    if(y+1>=n-1 || x+1>=m-1) neig.pb(i);
    rep(d,4){
      int X=x+dx[d], Y=y+dy[d];
      if(id.count(pii(X,Y))){
	int s=id[pii(X,Y)];
	add(g,i,s,0);
      }
    }
    reps(Y,y-1,y+2)if(Y>=0 && Y<n) add(g,i,Y+t,1);
    reps(X,x-1,x+2)if(X>=0 && X<m) add(g,i,X+t+n,1);
    id[pii(x,y)]=i;
  }
  vector<int> ds;
  dij(g,0,ds);
  int re=min({(ds[t+n-1]+1)/2,(ds[t+n+m-1]+1)/2});
  if(id.count(pii(m-1,n-1))) re=min({re,ds[id[pii(m-1,n-1)]]/2});//,(ds[t+n-2]+1)/2,(ds[t+n+m-2]+1)/2});
  for(int x:neig) MN(re,ds[x]/2+1);
  //out(ds,1);
  cout<<(re>=INF/2?-1:re)<<endl;
  return 0;
}