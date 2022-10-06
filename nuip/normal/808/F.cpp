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

vector<int> primes,prime;
class PRPRPR{
public:
  PRPRPR(int PRIME_MAX){
    prime.resize(PRIME_MAX);
    for(int i=2;i<PRIME_MAX;i++)if(!prime[i]){
	primes.pb(i);
	for(int j=i*2;j<PRIME_MAX;j+=i)
	  prime[j]=1;
      }
  }
} prprprpr(312345);

int n,t;
vector<pii> ps[112];
typedef int Cost;
struct Edge{int to,cap,rev;Cost cost;};
typedef vector<Edge> Edges;
typedef vector<vector<Edge> > Graph;

vector<int> nums;
void add_edge(Graph &g,int from,int to,int cap,Cost cost=0){
  from=lower_bound(all(nums),from)-nums.begin();
  to=lower_bound(all(nums),to)-nums.begin();
  g[from].pb((Edge){to,cap,(int)g[to].size(),cost});
  g[to].pb((Edge){from,0,(int)g[from].size()-1,-cost});
}
Cost INF=3e8;

//max_flow

vector<int> used;

int dfs(Graph &g,int v,int t,int f){
  if(v==t) return f;
  used[v]=1;
  int re,i,j,k;
  for(i=0;i<g[v].size();i++){
    Edge &e=g[v][i];
    if(e.cap<=0||used[e.to])continue;
    int d=dfs(g,e.to,t,min(f,e.cap));
    if(d>0){
      e.cap-=d;
      g[e.to][e.rev].cap+=d;
      return d;
    }
  }
  return 0;
}

int max_flow(Graph &g,int s,int t){
  int sum=0,f,V=g.size();
  while(1){
    used.resize(V);
    fill(all(used),0);
    sum+=f=dfs(g,s,t,INF);
    if(!f)return sum;
  }
}

int fun(int m){
  vector<int> p(100001);
  rep(i,m+1)for(pii pp:ps[i]){
    if(pp.Y==1){
      MX(p[1],pp.X);
    }else{
      p[pp.Y]+=pp.X;
    }
  }
  nums={0,1};
  reps(i,2,100001)if(p[i]) nums.pb(i);
  Graph g(nums.size()),h(nums.size());
  int rm=0;
  reps(i,2,100001)if(p[i]){
    if(i%2){
      add_edge(g,i,1,p[i]);
      add_edge(h,i,1,p[i]);
    }else{
      add_edge(g,0,i,p[i]);
      if(prime[i+1]) add_edge(h,0,i,p[i]);
      else rm+=p[i];
    }
  }
  for(int i:nums)if(i%2==0&&i>1)for(int j:nums)if(j%2&&j>1){
      if(!prime[i+j]){
	add_edge(g,i,j,INF);
	add_edge(h,i,j,INF);
      }
    }
  int sum=accumulate(p.begin()+2,p.end(),0);
  return max( sum-max_flow(g,0,1),
	      sum-rm+p[1]-max_flow(h,0,1));
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  cin>>n>>t;
  rep(i,n){
    int a,b,c;
    cin>>a>>b>>c;
    ps[c].eb(a,b);
  }
  int l=0,r=n+1;
  while(r-l>1){
    int m=(l+r)/2;
    (fun(m)>=t?r:l)=m;
  }
  cout<<(r==n+1?-1:r)<<endl;
  return 0;
}