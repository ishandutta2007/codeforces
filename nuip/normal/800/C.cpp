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
vector<string> s_p_l_i_t(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while(getline(ss,x,c)) v.emplace_back(x); return move(v);}
void e_r_r(vector<string>::iterator it) {}
template<typename T, typename... Args> void e_r_r(vector<string>::iterator it, T a, Args... args){ if(*it==" 1"||*it=="1") cerr<<endl; else cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << ", "; e_r_r(++it, args...);}
const ll MOD=1e9+7;

vector<ll> nums[212345];
ll dp[212345];
ll pre[212345];
ll extgcd(ll a,ll b,ll &x,ll &y){
  ll g=a; x=1,y=0;
  if(b){
    g=extgcd(b,a%b,y,x);
    y-=(a/b)*x;
  }
  return g;
}

ll extgcd(ll a,ll b,ll c){
  ll g=__gcd(a,b);
  a/=g; b/=g; c/=g;
  ll x,y;
  extgcd(a,b,x,y);
  x%=b;
  if(x<0) x+=b;
  // out(a,b,c,x,y,1);
  // out(a*x+b*y,c,x*c%b,1);
  return x*c%b;
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n,m;
  cin>>n>>m;
  vector<ll> a(n);
  rep(i,n) cin>>a[i];
  vector<ll> facts;
  reps(i,1,m+1)if(m%i==0) facts.pb(i);
  //out(facts,1);
  unordered_set<ll> ban(all(a));
  rep(i,m)if(ban.count(i)==0) nums[__gcd(m,i)].pb(i);
  //for(int x:facts) out(x,nums[x],1);
  for(ll p:facts){
    for(ll q:facts){
      if(q>=p) break;
      if(p%q==0 && MX(dp[p],dp[q])) pre[p]=q;
    }
    dp[p]+=nums[p].size();
  }
  vector<ll> fs;
  for(ll i=m;i>1;i=pre[i]) fs.pb(i);
  fs.pb(1);
  reverse(all(fs));
  //cout<<fs;
  vector<ll> re;
  ll prod=1;
  for(ll p:fs){
    for(ll y:nums[p]){
      ll x=extgcd(prod,m,y);
      re.pb(x);
      (prod*=x)%=m;
    }
  }
  //cout<<re;
  cout<<re.size()<<endl;
  ll p=1;
  for(ll x:re){
    x%=m;
    if(x<0) x+=m;
    (p*=x)%=m;
    assert(ban.count(p)==0);
    ban.insert(p);
    // cout<<p<<",";
    cout<<x<<" ";
  }
  cout<<endl;
  return 0;
}