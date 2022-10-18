#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif
using ll = long long;
using ld = long double;
using ull = long long;
#define REP3(i, m, n) for (int i = (m); (i) < int(n); ++ (i))
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define ALL(x) begin(x), end(x)
#define all(s) (s).begin(),(s).end()
//#define rep2(i, m, n) for (int i = (m); i < (n); ++i)
//#define rep(i, n) rep2(i, 0, n)
#define drep2(i, m, n) for (int i = (m)-1; i >= (n); --i)
#define drep(i, n) drep2(i, n, 0)
#define rever(vec) reverse(vec.begin(), vec.end())
#define sor(vec) sort(vec.begin(), vec.end())
#define fi first
#define se second
#define pb push_back
#define P pair<ll,ll>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define in scanner.read_int()
const ll mod = 998244353;
//const ll mod = 1000000007;
const ll inf = 4500000000000000000ll;
static const long double pi = 3.141592653589793;
template<class T>void vcin(vector<T> &n){for(int i=0;i<int(n.size());i++) cin>>n[i];}
template<class T>void vcout(vector<T> &n){for(int i=0;i<int(n.size());i++){cout<<n[i]<<" ";}cout<<endl;}
void YesNo(bool a){if(a){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}}
void YESNO(bool a){if(a){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0;}
template<class T> void ifmin(T t,T u){if(t>u){cout<<-1<<endl;}else{cout<<t<<endl;}}
template<class T> void ifmax(T t,T u){if(t>u){cout<<-1<<endl;}else{cout<<t<<endl;}}
template<typename T,typename ...Args>auto make_vector(T x,int arg,Args ...args){if constexpr(sizeof...(args)==0)return vector<T>(arg,x);else return vector(arg,make_vector<T>(x,args...));}
ll modPow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
const ll t0=1,t1=10,t2=100,t3=1000,t4=10000,t5=100000,t6=1000000,t7=10000000,t8=t7*10,t9=t8*10,t10=t9*10,t11=t10*10,t12=t11*10,t13=t12*10,t14=t13*10,t15=t14*10,t16=t15*10,t17=t16*10,t18=t17*10;
class Scanner {
    vector<char> buffer;
    ssize_t n_written;
    ssize_t n_read;

public:
    Scanner(): buffer(1024*1024) { do_read(); }

    int64_t read_int() {
        int64_t ret = 0, sgn = 1;
        int ch = current_char();
        while (isspace(ch)) { ch = next_char(); }
        if (ch == '-') { sgn = -1; ch = next_char(); }
        for (; isdigit(ch); ch = next_char())
            ret = (ret * 10) + (ch - '0');
        return sgn * ret;
    }

private:
    void do_read() {
        ssize_t r = read(0, &buffer[0], buffer.size());
        if (r < 0) {
            throw runtime_error(strerror(errno));
        }
        n_written = r;
        n_read = 0;
    }

    inline int next_char() {
        ++n_read;
        if (n_read == n_written) { do_read(); }
        return current_char();
    }

    inline int current_char() {
        return (n_read == n_written) ? EOF : buffer[n_read];
    }
};

//Scanner scanner;
//void vin(vector<ll> &n){for(int i=0;i<int(n.size());i++) n[i]=in;}

void cincout(){
  ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  cout<< fixed << setprecision(20);
}
void solve(){
  ll a;
  cin>>a;
  vector<ll> n(a);
  vcin(n);
  cout<<a-1<<endl;
  ll mi=inf,ini=0;
  for(int i=0;i<a;i++){
    if(chmin(mi,n[i])) ini=i;
  }
  for(int i=0;i<a;i++){
    if(i==ini) continue;
    if(i%2==ini%2){
      cout<<i+1<<" "<<ini+1<<" "<<n[ini]<<" "<<n[ini]<<endl;
    }
    else{
      cout<<i+1<<" "<<ini+1<<" "<<n[ini]+1<<" "<<n[ini]<<endl;
    }
  }
}
int main() {
  cincout();
  ll a;
  cin>>a;
  while(a--){
    solve();
  }
}