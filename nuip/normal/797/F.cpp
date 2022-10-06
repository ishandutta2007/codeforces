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
#define rreps(X,S,Y) for (int (X) = (Y)-1;(X) >= (S);--(X))
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
const ll INF=1e18;
ll dp[2][11234];
int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n,m;
  cin>>n>>m;
  vector<int> xs(n);
  rep(i,n) cin>>xs[i];
  vector<pii> hs(m);
  rep(i,m) cin>>hs[i].X>>hs[i].Y;
  vector<pii> ps=hs;
  rep(i,n) ps.eb(xs[i],0);
  sort(all(ps));
  ll *cur=dp[0]+5123,*nxt=dp[1]+5123;
  fill(cur-5111,cur+5111,INF);
  cur[0]=0;
  ll pre=ps[0].X;
  for(pii p:ps){
    fill(nxt-5111,nxt+5111,INF);
    if(p.Y){
      deque<pll> que;
      rreps(d,-5010,5010){
	ll val=cur[d]+(p.X-pre)*abs(d);
	while(que.size() && que.back().X>=val) que.pop_back();
	que.eb(val,d);
	while(que.size() && que.front().Y>d+p.Y) que.pop_front();
	//if(p==pii(2,1) && d==0) out(que.front(),1);
	MN(nxt[d],que.front().X);
      }
    }else{
      reps(x,-5010,5010){
	MN(nxt[x+1],cur[x]+(p.X-pre)*abs(x));
      }
    }
    pre=p.X;
    swap(cur,nxt);
    //out(p,1);
    //reps(x,-4,5)cout<<(cur[x]==INF?-1:cur[x])<<",";cout<<endl;
  }
  ll re=cur[0];
  cout<<(re==INF?-1:re)<<endl;
  return 0;
}