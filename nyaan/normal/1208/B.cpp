#include <bits/stdc++.h>
#define whlie while
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define rep(i,N) for(int i = 0; i < (N); i++)
#define repr(i,N) for(auto i = (N) - 1; i >= 0; i -= 1)
#define each(x,v) for(auto& x : v)
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define vrep(v,it) for(auto it = v.begin(); it != v.end(); it++)
#define vrepr(v,it) for(auto it = v.rbegin(); it != v.rend(); it++)
#define ini(...) int __VA_ARGS__; in(__VA_ARGS__)
#define inl(...) ll __VA_ARGS__; in(__VA_ARGS__)
#define ins(...) string __VA_ARGS__; in(__VA_ARGS__)
#define rand mtrand
using namespace std; void solve();
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector< vector<int> >;
constexpr int inf = 1001001001;
constexpr ll infLL = (1LL << 61) - 1;
struct IoSetupNya {IoSetupNya() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); cerr << fixed << setprecision(15);} } iosetupnya;
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
  #define trc(...) do { cout << #__VA_ARGS__ << " = "; dbg_out(__VA_ARGS__);} while(0)
  #define trca(v,N) do { cout << #v << " = "; array_out(v , N);cout << endl;} while(0)
  int main(){solve_dbg();}
#else
  #define trc(...)
  #define trca(...)
  int main(){solve();}
#endif

using P = pair<int,int>;
constexpr int MOD = 1000000007;
random_device seed_gen; mt19937_64 mtrand(seed_gen());

//////////////////////////////////////////

template<class T>
struct compress{
  vector<T> xs;
  compress(const vector<T>& v){
    xs.reserve(v.size());
    for(T x : v) xs.push_back(x);
    sort(xs.begin(),xs.end());
    xs.erase(unique(xs.begin(),xs.end()) , xs.end());
  }

  int get(const T& x){
    return lower_bound(xs.begin(),xs.end(),x) - xs.begin();
  }
  int size(){
    return xs.size();
  }
  T& operator[](int i){
    return xs[i];
  }
};

void solve(){
  ini(N);
  vi v(N); in(v);
  compress<int> zip(v);
  rep(i,N) v[i] = zip.get(v[i]);
  vi cnt(2048 , 0);

  auto ok2 = [](vi &v){
    each(x , v) {if(x >= 2) return false;}
    return true;
  };
  auto ok = [&](int n){
    fill(all(cnt) , 0);
    //trc(n);
    for(int i = N - n ; i < N; i++) cnt[v[i]]++;
    //rep(i,10) trc(cnt[i]);
    if(ok2(cnt)) return true;
    for(int i = 0; i + N - n < N; i++){
      cnt[v[i]]++; cnt[v[i + N - n]]--;
      //rep(i,10) trc(i,cnt[i]);
      if(ok2(cnt)) return true;
    }
    return false;
  };

  int l = 1 , r = N + 1;
  while(l + 1 < r){
    int med = (l + r) / 2;
    if(ok(med)) l = med;
    else r = med;
  }
  out(N - l);

}