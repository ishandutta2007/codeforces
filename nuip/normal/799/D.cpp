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

vector<pii> ps;
ll s,t;

int dfs(ll x,ll y,int i){
  if(i>=ps.size()) return MOD;
  int cnt=0;
  //out(i,ps[i],x,y,1);
  for(ll j=x;j<s;j*=ps[i].X) ++cnt;
  for(ll j=y;j<t;j*=ps[i].X) ++cnt;
  if(cnt<=ps[i].Y) return cnt;
  int re=MOD;
  ll pw=1,wp=1;
  rep(j,ps[i].Y) pw*=ps[i].X;
  rep(j,ps[i].Y+1){
    MN(re,dfs(min(x*pw,s),min(y*wp,t),i+1));
    wp*=ps[i].X;
    pw/=ps[i].X;
  }
  return re+ps[i].Y;
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int A,b,x,y,n;
  cin>>A>>b>>x>>y>>n;
  vector<int> a(n);
  rep(i,n) cin>>a[i];
  map<int,int> cnt;
  for(int x:a) ++cnt[x];
  for(auto it=cnt.rbegin();it!=cnt.rend();++it){
    ps.pb(*it);
    MN(ps.back().Y,40);
    if(ps.size()>=15) break;
  }
  int re=MOD;
  rep(_,2){
    s=(A+x-1)/x;
    t=(b+y-1)/y;
    //out(s,t,1);
    MN(re,dfs(1,1,0));
    swap(A,b);
  }
  cout<<(re>n?-1:re)<<endl;
  return 0;
}

/*

    out(s,t,1);
    reps(cnt,0,N+1){
      rep(i,1<<cnt){
	ll S=1,T=1;
	rep(j,cnt){
	  if(i>>j&1) MN<ll>(S*=a[n-1-j],s);
	  else MN<ll>(T*=a[n-1-j],t);
	}
	if(i+1==(1<<10)) out(S,T,1);
	if(S==s && T==t){
	  MN(re,cnt); cnt=N;
	  break;
	}
      }
    }
*/