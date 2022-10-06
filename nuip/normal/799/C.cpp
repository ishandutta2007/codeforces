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

int one(const vector<pii> &ps,int x){
  int re=0;
  for(pii p:ps)if(p.X<=x) MX(re,p.Y);
  //out("one",ps,x,re,1);
  return re;
}
int two(const vector<pii> &ps,int x){
  int n=ps.size();
  vector<pii> fst(n),snd(n);
  rep(i,n) fst[i]=pii(ps[i].Y,i);
  reps(i,1,n){
    for(pii p:{fst[i-1],snd[i-1]}){
      if(fst[i]<=p){
	snd[i]=fst[i]; fst[i]=p;
      }else MX(snd[i],p);
    }
  }
  //out(ps,fst,snd,1);
  int re=0;
  rep(i,n){
    auto p=ps[i];
    if(p.X>x) continue;
    auto it=upper_bound(all(ps),pii(x-p.X,MOD));
    int t=it-ps.begin();
    if(!t) continue;
    --t;
    pii q=fst[t];
    if(q.Y==i) q=snd[t];
    if(q.X==0) continue;
    MX(re,p.Y+q.X);
  }
  //out(ps,x,re,1);
  return re;
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n,c,d;
  cin>>n>>c>>d;
  vector<pii> cs,ds;
  rep(i,n){
    int b,p;
    char c;
    cin>>b>>p>>c;
    (c=='C'?cs:ds).eb(p,b);
  }
  sort(all(cs));
  sort(all(ds));
  int re=max(two(cs,c), two(ds,d));
  int a=one(cs,c),b=one(ds,d);
  if(a&&b) MX(re,a+b);
  cout<<re<<endl;
  return 0;
}