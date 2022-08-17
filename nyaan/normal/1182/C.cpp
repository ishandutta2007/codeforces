#pragma GCC optimize("O2")
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define whlie while
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define inf 1001001001
#define infLL ( (1LL << 61))
#define MOD 1000000007
#define FOR(i,a,b) for(int (i)=((int)a); (i)<((int)b); (i)++) // [a,b)
#define rep(i,N) FOR((i), 0, ((int)N)) // [0,N)
#define FORR(i,a,b) for(int (i)=((int)b) - 1; (i)>=((int)a); (i)--)
#define repr(i,N) FORR((i), 0, ((int)N))
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(v) ((int)(v).size())
#define vrep(v,it) for(auto it=v.begin();it!=v.end();it++)
#define vrepr(v,it) for(auto it=v.rbegin();it!=v.rend();it++)
#define inx(t,...) t __VA_ARGS__; in(__VA_ARGS__)
#define ini(...) int __VA_ARGS__; in(__VA_ARGS__)
#define inl(...) ll __VA_ARGS__; in(__VA_ARGS__)
#define inc(...) char __VA_ARGS__; in(__VA_ARGS__)
#define ins(...) string __VA_ARGS__; in(__VA_ARGS__)
#define ind(...) double __VA_ARGS__; in(__VA_ARGS__)
#define inpii(...) pii __VA_ARGS__; in(__VA_ARGS__)
#define invi(v,...) vi v; in(v,##__VA_ARGS__)
#define invl(v,...) vl v; in(v,##__VA_ARGS__)
#define mem(ar,val) memset((ar), (val), sizeof(ar) )
#define mem0(ar) memset((ar),  0, sizeof(ar) )
#define mem1(ar) memset((ar), -1, sizeof(ar) )

#ifdef LOCAL
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
    #define trc(...) do { cout << #__VA_ARGS__ << " = "; dbg_out(__VA_ARGS__);} while(0)
    #define stopif(val) assert( !(val) )
    #define vdbg(v,...) do { cout << #v << " = "; vector_debug(v , ##__VA_ARGS__);} while(0)
#else
    #define dbg(...) 1
    #define trc(...) 1
    #define stopif(...) 1
    #define vdbg(...) 1
#endif

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector< vector<int> > vvi;

struct IoSetup {
  IoSetup() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    cerr << fixed << setprecision(15);
  }
} iosetup;

int gcd(int a, int b){if(a>b) swap(a,b); return a==0 ? b : gcd(b%a,a);} ll gcd(ll a, ll b){if(a>b) swap(a,b); return a==0 ? b : gcd(b%a,a);}
int lcm(int a, int b){return (a / gcd(a,b)) * b;} ll lcm(ll a, ll b){return (a / gcd(a,b)) * b;}
inline ll pow(int a, int b){ll ans = 1; rep(i,b) ans *= a; return ans;} inline ll pow(ll a, ll b){ll ans = 1; rep(i,b) ans*= a; return ans;}
inline ll pow(int a, ll b){ll ans = 1; rep(i,b) ans *= a; return ans;} inline ll pow(ll a, int b){ll ans = 1; rep(i,b) ans*= a; return ans;}
template<typename T, typename U> inline bool amin(T &x, U y) { return (y < x) ? (x = y, true) : false; }
template<typename T, typename U> inline bool amax(T &x, U y) { return (x < y) ? (x = y, true) : false; }
template<typename C> inline void _cin(C &c){cin >> c;}
template<typename T,typename U> inline void _cin(pair<T,U> &p){cin >> p.fi; cin >> p.se;}
template<typename C> inline void _cout(const C &c){cout << c;}
template<typename T,typename U> inline void _cout(const pair<T,U> &p){cout << p.fi << ' ' << p.se;}
void in(){} template <typename T,class... U> void in(T &t,U &...u){ _cin(t); in(u...);}
void out(){cout << "\n";} template <typename T,class... U> void out(const T &t,U ...u){ _cout(t); if(sizeof...(u)) cout << ' '; out(u...);}
template<typename C> inline void in(vector<C> &v,int N=-1){if(sz(v) != 0){int M=(N == -1) ? sz(v) : N; rep(i,M) _cin(v[i]);}else{C c;rep(i,N) v.pb((_cin(c),c));}}
template<typename C> inline void in(C v[],int N){rep(i,N) _cin(v[i]);}
template<typename C> inline void out(const vector<C> &v,int N=-1){int M=(N == -1) ? sz(v) : N; rep(i,M) {cout<<( (i)?" ":"" ); _cout(v[i]);} cout<<"\n";}
template<typename C> inline void out(C v[],int N){rep(i,N) {cout<<( (i)?" ":"" ); _cout(v[i]);} cout<<"\n";}
template<typename C> inline void vector_debug(const vector<C> &v,int N=-1){cout << "{"; int M=(N == -1) ? sz(v) : N; rep(i,M) {cout<<( (i)?", ":"" ); _cout(v[i]);} cout<<"}"<<endl;}
template<typename C> inline void vector_debug(C v[], int N){cout << "{"; rep(i,N) {cout<<((i)?", ":""); _cout(*(v+i));} cout<<"}"<<endl;}
void dbg_out(){cout << endl;} template <typename T,class... U> void dbg_out(const T &t,U ...u){ _cout(t); if(sizeof...(u)) cout << ", "; dbg_out(u...);}
template<typename C,class... U> void dbg_out(const vector<C> &v,U ...u){vector_debug(v); if(sizeof...(u)) cout << ", "; dbg_out(u...);}
template<typename C,class... U> void dbg_out(const vector<vector<C>> &v,U ...u){cout << "{ "; rep(i,sz(v)) {if(i)cout<<", "; vector_debug(v[i]);} cout << " }"; if(sizeof...(u)) cout << ", "; dbg_out(u...);}
template<typename C> inline C vmax(const vector<C> &v){C n=v[0]; rep(i,sz(v)) amax(n,v[i]); return n;} template<typename C> inline C vmax(C v[], int N){C n=v[0]; rep( i , N ) amax(n,v[i]); return n;}
template<typename C> inline C vmin(const vector<C> &v){C n=v[0]; rep(i,sz(v)) amin(n,v[i]); return n;} template<typename C> inline C vmin(C v[], int N){C n=v[0]; rep( i , N ) amin(n,v[i]); return n;}
template<typename C> inline C vsum(const vector<C> &v){C n=0; rep(i,sz(v)) n+=v[i]; return n;} template<typename C> inline C vsum(C v[], int N){C n=0; rep( i , N ) n+=v[i]; return n;}

////////////
/// main ///
////////////

int main(){
  ini(N);
  vector<string> str(N);
  vector<int> c(N);
  vector<char> l(N);
  rep(i,N){
    int cnt = 0; char last = 'n';
    ins(S);
    rep(j , sz(S)){
      if(S[j] == 'a' ||
        S[j] == 'i' ||
        S[j] == 'u' ||
        S[j] == 'e' ||
        S[j] == 'o') {
          cnt++; last = S[j];
      }
    }
    trc(S , cnt , last);
    str[i] = S; c[i] = cnt; l[i] = last;
  }
  vi ord(N);
  iota(all(ord) , 0);
  sort(all(ord) , [&](int a, int b){
    if(c[a] == c[b]) return l[a] < l[b];
    else return c[a] < c[b];
  } );
  trc(ord);
  auto it = ord.begin();
  int sec_cnt = 0;
  while(it < ord.end() - 1){
    if( c[*it] == c[ *(it + 1) ] &&
      l[*it] == l[ *(it + 1) ]
    ){
      sec_cnt++;
      it += 2;
    }
    else it++;
  }
  int fir_cnt = 0;
  it = ord.begin(); 
  while(it < ord.end() - 1){
    if( c[*it] == c[ *(it + 1) ]){
      fir_cnt++;
      it += 2;
    }
    else it++;
  }
  trc(sec_cnt, fir_cnt);
  int ans_cnt = min( sec_cnt , fir_cnt / 2 );
  out(ans_cnt);
  if(ans_cnt == 0){return 0;}
  using P = pair<string,string>;
  vector< pair<P,P> > ans(ans_cnt);
  {
    auto ans_it = ans.begin();
    auto it = ord.begin();
    while(it < ord.end() - 1){
      if(ans_it == ans.end()) break;
      if( c[*it] == c[ *(it + 1) ] &&
        l[*it] == l[ *(it + 1) ]
      ){
        ans_it->fi.se = str[*it];
        ans_it->se.se = str[*(it + 1)];
        *it = -1; *(it + 1) = -1;
        it += 2;
        ans_it++;
      }
      else it++;
    }
  }
  {
    auto ans_it = ans.begin();
    auto it = ord.begin();
    while(it < ord.end() - 1){
      if(ans_it == ans.end()) break;
      if( *it == -1){
        it++;
      }
      else if(*(it + 1) == -1){
        auto it2 = it + 1;
        while(it2 != ord.end() && *it2 == -1) it2++;
        if(it2 == ord.end()) break;
        if(c[*it] == c[*it2]){
          ans_it->fi.fi = str[*it];
          ans_it->se.fi = str[*it2];
          it = it2 + 1;
          ans_it++;
        }
        else {
          it = it2;
        }
      }
      else if( c[*it] == c[ *(it + 1) ] 
      ){
        ans_it->fi.fi = str[*it];
        ans_it->se.fi = str[*(it + 1)];
        it += 2;
        ans_it++;
      }
      else it++;
    }
  }
  rep(i , ans.size()){
    out(ans[i].fi);
    out(ans[i].se);
  }
}