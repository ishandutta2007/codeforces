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
const ll INF=2e18;

ll fun(const array<int,10> &cnt,int d){
  ll re=0,t=-1;
  reps(i,d+1,10)if(cnt[i]){
    t=i;
    re=i;
    break;
  }
  if(t<0) return INF;
  rep(i,10)rep(j,cnt[i]-(i==t)) (re*=10)+=i;
  return re;
}

ll l,r;
array<int,10> cnt;
int sum=0;
vector<ll> pws(20);
vector<int> lb;
ll dfs(int dig){
  if(dig==10){
    if(sum==1 && cnt[1]){
      for(ll i=1;i<=2e18;i*=10)if(l<=i && i<r) return 1;
      return 0;
    }
    //out(sum,1);
    //if(sum==1){rep(i,10) cout<<cnt[i]<<",";cout<<endl;}
    {
      int x=max(0,(int)lb.size()-sum+1);
      ll t=0,f=0;
      rep(i,10)rep(j,cnt[i]){
	(t*=10)+=i;
	if(!f){
	  rep(i,x) t*=10;
	  f=1;
	}
      }
      if(l<=t &&  t<r) return 1;
    }
    if(sum>lb.size()) return 0;
    auto rem=cnt; rem[0]=lb.size()-sum;
    ll t=0;
    rep(i,lb.size()){
      //if(sum==2&& cnt[5] && cnt[6]) out(i,t,fun(rem, lb[i]),1);
      if(t+fun(rem, lb[i])<r) return 1;
      if(!rem[lb[i]]) return 0;
      t+=pws[lb.size()-1-i]*lb[i]; --rem[lb[i]];
      if(t>=r) return 0;
    }
    return t<r;
  }
  ll re=0;
  while(sum<=18){
    //if(dig==9 && dfs(dig+1)){rep(i,10) cout<<cnt[i]<<",";cout<<endl;}
    re+=dfs(dig+1);
    ++cnt[dig]; ++sum;
  }
  sum-=cnt[dig];
  cnt[dig]=0;
  return re;
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  pws[0]=1;
  rep(i,19) pws[i+1]=pws[i]*10;
  cin>>l>>r; ++r;
  if(l+1==r){
    cout<<1<<endl;
    return 0;
  }
  for(ll x=l;x;x/=10) lb.pb(x%10);
  reverse(all(lb));
  //out(lb,1);
  cout<<dfs(1)<<endl;
  return 0;
}