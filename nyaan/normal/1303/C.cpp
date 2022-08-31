#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define rep(i,N) for(long long i = 0; i < (long long)(N); i++)
#define repr(i,N) for(long long i = (long long)(N) - 1; i >= 0; i--)
#define rep1(i,N) for(long long i = 1; i <= (long long)(N) ; i++)
#define repr1(i,N) for(long long i = (N) ; (long long)(i) > 0 ; i--)
#define each(x,v) for(auto& x : v)
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define ini(...) int __VA_ARGS__; in(__VA_ARGS__)
#define inl(...) long long __VA_ARGS__; in(__VA_ARGS__)
#define ins(...) string __VA_ARGS__; in(__VA_ARGS__)
using namespace std; void solve();
using ll = long long; template<class T = ll> using V = vector<T>;
using vi = V<int>; using vl = V<>; using vvi = V< V<int> >;
constexpr int inf = 1001001001; constexpr ll infLL = (1LL << 61) - 1;
struct IoSetupNya {IoSetupNya() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); cerr << fixed << setprecision(7);} } iosetupnya;
template<typename T, typename U> inline bool amin(T &x, U y) { return (y < x) ? (x = y, true) : false; }
template<typename T, typename U> inline bool amax(T &x, U y) { return (x < y) ? (x = y, true) : false; }
template<typename T, typename U> ostream& operator <<(ostream& os, const pair<T, U> &p) { os << p.first << " " << p.second; return os; }
template<typename T, typename U> istream& operator >>(istream& is, pair<T, U> &p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator <<(ostream& os, const vector<T> &v) { int s = (int)v.size(); rep(i,s) os << (i ? " " : "") << v[i]; return os; }
template<typename T> istream& operator >>(istream& is, vector<T> &v) { for(auto &x : v) is >> x; return is; }
void in(){} template <typename T,class... U> void in(T &t,U &...u){ cin >> t; in(u...);}
void out(){cout << "\n";} template <typename T,class... U> void out(const T &t,const U &...u){ cout << t; if(sizeof...(u)) cout << " "; out(u...);}
template<typename T>void die(T x){out(x); exit(0);}
#ifdef NyaanDebug
  #include "NyaanDebug.h"
  #define trc(...) do { cerr << #__VA_ARGS__ << " = "; dbg_out(__VA_ARGS__);} while(0)
  #define trca(v,N) do { cerr << #v << " = "; array_out(v , N);cout << endl;} while(0)
#else
  #define trc(...)
  #define trca(...)
  int main(){solve();}
#endif

#define inc(...) char __VA_ARGS__; in(__VA_ARGS__)
#define in2(N,s,t) rep(i,N){in(s[i] , t[i]);}
#define in3(N,s,t,u) rep(i,N){in(s[i] , t[i] , u[i]);}
using vd = V<double>; using vs = V<string>; using vvl = V< V<> >;
template<typename T>using heap = priority_queue< T , V<T> , greater<T> >;

using P = pair<ll,ll>; using vp = V<P>;
constexpr int MOD = /**/ 1000000007; //*/ 998244353;
//////////////////

void q(){
  ins(S);
  int c[26][26] = {};
  rep(i , sz(S) - 1){
    if(S[i] == S[i + 1]){out("NO"); return;}
    c[S[i] - 'a'][S[i + 1] - 'a'] = 1;
    c[S[i + 1] - 'a'][S[i] - 'a'] = 1;
  }
  int s[26]= {};
  rep(i , 26){
    rep(j , 26) s[i] += c[i][j];
    if(s[i] > 2){out("NO"); return;}
  }
  rep(i , 5) trca(c[i] , 5);
  int used[26] = {};
  string ans;
  rep(i , 26){
    if(used[i] == 0 && s[i] == 1){
      int cur = i , par = -1;
      used[i] = 1;
      ans.push_back(cur + 'a');
      while(1){
        trc(cur , par);
        int change = 0;
        rep(j , 26){
          if(j != par && c[cur][j] == 1){
            par = cur; cur = j; change = 1;
            break;
          }
        }
        if(change == 0) break;
        used[cur] = 1;
        ans.push_back(cur + 'a');
      }
    }
  }
  rep(i , 26){
    if(used[i] == 0 && s[i] != 0){
      out("NO"); return;
    }
    if(used[i] == 0)
      ans.push_back(i + 'a');
  }
  out("YES");
  out(ans);
}

void solve(){
  ini(N);
  rep(i , N) q();
}