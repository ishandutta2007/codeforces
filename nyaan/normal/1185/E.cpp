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
template<typename C> inline void vector_debug(const vector<C> &v,int N=-1){cout << "{"; int M=(N == -1) ? sz(v) : N; rep(i,M) {cout<<( (i)?", ":"" ); _cout(v[i]);} cout<<"}";}
template<typename C> inline void vector_debug(C v[], int N){cout << "{"; rep(i,N) {cout<<((i)?", ":""); _cout(*(v+i));} cout<<"}";}
void dbg_out(){cout << endl;} template <typename T,class... U> void dbg_out(const T &t,U ...u){ _cout(t); if(sizeof...(u)) cout << ", "; dbg_out(u...);}
template<typename C,class... U> void dbg_out(const vector<C> &v,U ...u){vector_debug(v); if(sizeof...(u)) cout << ", "; dbg_out(u...);}
template<typename C,class... U> void dbg_out(const vector<vector<C>> &v,U ...u){cout << "{ "; rep(i,sz(v)) {if(i)cout<<", "; vector_debug(v[i]);} cout << " }"; if(sizeof...(u)) cout << ", "; dbg_out(u...);}
template<typename C> inline C vmax(const vector<C> &v){C n=v[0]; rep(i,sz(v)) amax(n,v[i]); return n;} template<typename C> inline C vmax(C v[], int N){C n=v[0]; rep( i , N ) amax(n,v[i]); return n;}
template<typename C> inline C vmin(const vector<C> &v){C n=v[0]; rep(i,sz(v)) amin(n,v[i]); return n;} template<typename C> inline C vmin(C v[], int N){C n=v[0]; rep( i , N ) amin(n,v[i]); return n;}
template<typename C> inline C vsum(const vector<C> &v){C n=0; rep(i,sz(v)) n+=v[i]; return n;} template<typename C> inline C vsum(C v[], int N){C n=0; rep( i , N ) n+=v[i]; return n;}

////////////
/// main ///
////////////

#ifdef LOCAL
  #define g_trace() g_trc()
#else 
  #define g_trace() 1
#endif
int H,W,h1,w1,h2,w2;;
char g[3010][3010];
struct vec{int h,w; vec(int x,int y):h(x),w(y){}; vec(){}; };
using P = pair<vec,vec>;
bool ok(int x,int y){return 0<=x && x<H && 0<=y && y<W ;}
const int dx[]={1,0,-1,0}; const int dy[]={0,1,0,-1};
//const int dx[]={1,1,1,0,-1,-1,-1,0}; const int dy[]={1,0,-1,-1,-1,0,1,1};
bool isExist(char cur){
  bool flg = false;
  h1 = w1 = inf; h2 = w2 = -inf;
  rep(i,H) rep(j,W){
    if(g[i][j] == cur){
      amin(h1 , i); amin(w1 , j);
      amax(h2 , i); amax(w2 , j);
      flg = true;
    }
  }
  return flg;
}
void g_trc(){
  rep(i,H){
    rep(j,W) cerr << g[i][j];
    cerr << endl;
  }
  cerr << endl;
}


void solve(){
  in(H,W);
  char last = '.';
  rep(i,H) rep(j,W) {in(g[i][j]);amax(last,g[i][j]);}
  if(last == '.'){out("YES"); out("0"); return;}
  vector<P> ans;

  for(char cur = last; cur >= 'a'; cur--){
    g_trace();
    if(isExist(cur)){
      trc(h1,w1,h2,w2);
      if(h1 == h2){
        for(int i=w1; i<=w2;i++){
          if( g[h1][i] != '#' && g[h1][i] != cur ){
            out("NO"); return;
          }
          g[h1][i] = '#';
        }
      }
      else if(w1 == w2){
        for(int i=h1; i<=h2;i++){
          trc(i);
          if(g[i][w1] != '#' && g[i][w1] != cur){
            out("NO"); return;
          }
          g[i][w1] = '#';
        }
      }
      else {
        {out("NO"); return;}
      }
      ans.eb(P(vec(h1,w1) , vec(h2,w2)));
      trc("hoge");
      if(isExist(cur)){
        trc("huga");
        out("NO"); return;
      }
    }
    else{
      rep(i,H) rep(j,W){
        if(g[i][j] == '#'){
          vec cur = vec(i,j);
          ans.eb(P(cur,cur));
          goto A;

        }
      }
      A:
        trc();
    }
  }

  out("YES");
  out(sz(ans));
  vrepr(ans , it){
    out( it->fi.h + 1, it->fi.w + 1, it->se.h + 1, it->se.w + 1);
  }
}

int main(){
  ini(N);
  rep(i,N) solve();
}