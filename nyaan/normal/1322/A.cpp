  #include <bits/stdc++.h>  // clang-format off
  #define pb push_back
  #define eb emplace_back
  #define fi first
  #define se second
  #define each(x,v) for(auto& x : v)
  #define all(v) (v).begin(),(v).end()
  #define sz(v) ((int)(v).size())
  #define ini(...) int __VA_ARGS__; in(__VA_ARGS__)
  #define inl(...) long long __VA_ARGS__; in(__VA_ARGS__)
  #define ins(...) string __VA_ARGS__; in(__VA_ARGS__)

  #ifdef ONLINE_JUDGE
    #define rep(i,N) for(int i = 0; i < (int)(N); i++)
    #define repr(i,N) for(int i = (int)(N) - 1; i >= 0; i--)
    #define rep1(i,N) for(int i = 1; i <= (int)(N) ; i++)
    #define repr1(i,N) for(int i = (N) ; (int)(i) > 0 ; i--)
  #else
    #define rep(i,N) for(long long i = 0; i < (long long)(N); i++)
    #define repr(i,N) for(long long i = (long long)(N) - 1; i >= 0; i--)
    #define rep1(i,N) for(long long i = 1; i <= (long long)(N) ; i++)
    #define repr1(i,N) for(long long i = (N) ; (long long)(i) > 0 ; i--)
  #endif

  using namespace std; void solve();
  using ll = long long; template<class T = ll> using V = vector<T>;
  using vi = V<int>; using vl = V<>; using vvi = V< V<int> >;
  constexpr int inf = 1001001001; constexpr ll infLL = (1LL << 61) - 1;
  //struct IoSetupNya {IoSetupNya() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); cerr << fixed << setprecision(7);} } iosetupnya;
  template<typename T, typename U> inline bool amin(T &x, U y) { return (y < x) ? (x = y, true) : false; }
  template<typename T, typename U> inline bool amax(T &x, U y) { return (x < y) ? (x = y, true) : false; }
  template<typename T, typename U> ostream& operator <<(ostream& os, const pair<T, U> &p) { os << p.first << " " << p.second; return os; }
  template<typename T, typename U> istream& operator >>(istream& is, pair<T, U> &p) { is >> p.first >> p.second; return is; }
  template<typename T> ostream& operator <<(ostream& os, const vector<T> &v) { int s = (int)v.size(); for(int i=0;i<s;i++) os << (i ? " " : "") << v[i]; return os; }
  template<typename T> istream& operator >>(istream& is, vector<T> &v) { for(auto &x : v) is >> x; return is; }
  void in(){} template <typename T,class... U> void in(T &t,U &...u){ cin >> t; in(u...);}
  void out(){cout << "\n";} template <typename T,class... U> void out(const T &t,const U &...u){ cout << t; if(sizeof...(u)) cout << " "; out(u...);}
  template<typename T>void die(T x){out(x); exit(0);}

  #ifdef NyaanDebug
    #include "NyaanDebug.h"
    #define trc(...) do { cerr << #__VA_ARGS__ << " = "; dbg_out(__VA_ARGS__);} while(0)
    #define trca(v,N) do { cerr << #v << " = "; array_out(v , N);} while(0)
    #define trcc(v) do { cerr << "name : " << #v << "\n"; int cnt = 0; each(x , v){cerr << (cnt++) << " : "; trc(x); } } while(0)
  #else
    #define trc(...)
    #define trca(...)
    #define trcc(...)
    int main(){solve();}
  #endif

  #define inc(...) char __VA_ARGS__; in(__VA_ARGS__)
  #define in2(s,t)     rep(i,sz(s)){in(s[i] , t[i]);}
  #define in3(s,t,u)   rep(i,sz(s)){in(s[i] , t[i] , u[i]);}
  #define in4(s,t,u,v) rep(i,sz(s)){in(s[i] , t[i] , u[i] , v[i]);}
  using vd = V<double>; using vs = V<string>; using vvl = V< V<> >;
  template<typename T,typename U>ll ceil(T a,U b){return (a + b - 1) / b;}

//  using P = pair<ll,ll>; using vp = V<P>;
constexpr int MOD = /**/ 1000000007; //*/ 998244353;
// clang-format on
/////////////////////////


void solve(){
  ini(N);
  ins(S);

  int l = 0 , r = 0;
  rep(i , N){
    (S[i] == '(' ? l : r) += 1;
  }
  if(l != r) die(-1);

  int ans = 0;
  int cnt = 0;
  rep(i , N){
    if(S[i] == '('){
      if(cnt > 0) ans += 2;
      cnt--;
    }
    else{
      cnt++;
    }
  }
  out(ans);
}