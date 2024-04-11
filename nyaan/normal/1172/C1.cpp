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
#define mod 998244353
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

// mod
inline ll madd(ll a, ll b){return (a + b) % mod;}
inline ll msub(ll a, ll b){return (a + mod - b) % mod;}
inline ll mmul(ll a, ll b){return ((a % mod) * (b % mod)) % mod;}
ll mpow(ll a, ll b){if(b == 0) return 1; else if(b == 1) return a % mod; else if(b % 2 == 0){ll hlf = mpow(a,b/2);return (hlf * hlf) % mod;} else {ll hlf = mpow(a,b/2);return ( mmul(hlf , hlf) * a ) % mod;}}
inline ll mdiv(ll a, ll b){return mmul(a, mpow(b, mod-2));}

using P = pair<ll,ll>;
P dp[60][60];

inline P psum(P a, P b){
  ll bunsi = madd( mmul(a.fi,b.se), mmul(a.se,b.fi) );
  ll bunbo = mmul(a.se,b.se);
  return P(bunsi,bunbo);
}

int main(){
  ini(N,M);
  vi a(N),w(N); in(a,N); in(w,N);
  ll dis_sum = 0, like_sum = 0;
  rep(i , N){
    if(a[i]) like_sum += w[i];
    else dis_sum += w[i];
  }

  dp[0][0] = P(1,1);
  for(int i=1; i<=M; i++) for(int j=0; j<=i; j++){
    int l_times = j, dis_times = i - j;
    if(dis_times > dis_sum){
      dp[i][j] = P(0,1); continue;
    }
    if(j == 0){
      dp[i][j].fi = mmul( dp[i-1][j].fi, dis_sum - dis_times + 1);
      dp[i][j].se = mmul( dp[i-1][j].se, dis_sum + like_sum + l_times - dis_times + 1 );
    }
    else if(j == i){
      if(dis_times == dis_sum) dp[i][j] = P(1,1);
      else{
        dp[i][j].fi = mmul( dp[i-1][j-1].fi , like_sum + l_times - 1);
        dp[i][j].se = mmul( dp[i-1][j-1].se , dis_sum + like_sum + l_times - dis_times - 1);
      }
    }
    else {
      P a,b;
      
      a.fi = mmul( dp[i-1][j].fi, dis_sum - dis_times + 1);
      a.se = mmul( dp[i-1][j].se, dis_sum + like_sum + l_times - dis_times + 1 );
      if(dis_times == dis_sum){
        b.fi = dp[i-1][j-1].fi; b.se = dp[i-1][j-1].se;
      }
      else{
      b.fi = mmul( dp[i-1][j-1].fi , like_sum + l_times - 1);
      b.se = mmul( dp[i-1][j-1].se , dis_sum + like_sum + l_times - dis_times - 1);
      }
      dp[i][j] = psum(a,b);
    }
    trc(l_times, dis_times);
    trc(i, j, dp[i][j].fi, dp[i][j].se);
  }
  
  rep(i , N){
    P ans = P(0,1);
    rep(nya , M + 1){
      if( a[i] == 0 && dis_sum < M - nya ) continue;
      int l_times = nya, dis_times = M - nya;
      P cur;
      if(a[i] == 0){
        cur.fi = mmul( dp[M][nya].fi , mmul ( (dis_sum - dis_times) , w[i] ) );
        cur.se = mmul( dp[M][nya].se , dis_sum );
      ans = psum( ans, cur );
      }
      else{
        cur.fi = mmul( dp[M][nya].fi , mmul( (like_sum + l_times) , w[i] ) );
        cur.se = mmul( dp[M][nya].se , like_sum );
        ans = psum(ans , cur);
      }
      trc(dp[M][nya].fi, dp[M][nya].se);
      trc(l_times, dis_times);
      trc(cur.fi, cur.se);
      trc(ans.fi , ans.se);
    }
    out( mdiv(ans.fi , ans.se) );
  }
}