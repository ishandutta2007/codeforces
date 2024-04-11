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

ll erase(multiset<ll> &st,ll x){
  auto it=st.lower_bound((x+1)/2);
  if(it==st.end()) return 0;
  //out(x,*it,1);
  ll re=*it;
  st.erase(it);
  return re;
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n;
  cin>>n;
  vector<ll> a(n);
  rep(i,n) cin>>a[i];
  vector<ll> nums;
  multiset<ll> st;
  for(ll x:a){
    if(__builtin_popcountll(x)==1) st.insert(x);
    else nums.pb(x);
  }
  vector<ll> seqs;
  while(st.size()){
    ll x=*st.rbegin();
    for(ll i=x;i;i/=2){
      auto it=st.find(i);
      if(it==st.end()){
	for(ll j=x;j>i;j/=2) nums.pb(j);
	x=0; break;
      }
      st.erase(it);
    }
    if(x) seqs.pb(x);
  }
  reverse(all(seqs));
  //out(nums,seqs,1);

  int m=seqs.size();
  multiset<ll> rem(all(seqs));
  multiset<pll> ps;
  for(ll x:nums){
    ll tmp=erase(rem,x);
    if(!tmp){
      cout<<-1<<endl;
      return 0;
    }
    ps.emplace(tmp,x);
  }
  //for(ll x:rem) ps.emplace(x,0);
  vector<int> re{m};
    
  for(ll x:seqs){
    auto it=rem.find(x);
    if(it!=rem.end()){
      rem.erase(it);
    }else{
      auto it=ps.lower_bound(pll(x,0));
      if(it==ps.end() || it->X!=x) return 1;
      ll tmp=erase(rem,it->Y);
      if(!tmp) break;
      ps.emplace(tmp,it->Y);
    }
    int f=0;
    for(ll i=1;i<=x;i*=2){
      ll tmp=erase(rem,i);
      if(!tmp){
	f=1; break;
      }
      ps.emplace(tmp,i);
    }
    if(f) break;
    re.pb(--m);
  }
  sort(all(re));
  for(int x:re) cout<<x<<" "; cout<<endl;
  return 0;
}