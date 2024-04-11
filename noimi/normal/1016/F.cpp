#pragma region Macros
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define vecpll vector<pll>
#define vec2(a,b) vector<vec>(a,vec(b))
#define vec2ll(a,b) vector<vecll>(a,vecll(b))
#define vec3(a,b,c) vector<vector<vec>>(a,vec2(b,c))
#define vec3ll(a,b,c) vector<vector<vecll>>(a,vec2ll(b,c))
#define fi first
#define se second
#define all(c) begin(c),end(c)
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance((c).begin(),lower_bound(all(c),(x)))
#define ub(c,x) distance((c).begin(),upper_bound(all(c),(x)))
using namespace std;
int in() {int x;cin>>x;return x;}
ll lin() {unsigned long long x;cin>>x;return x;}
string stin() {string s;cin>>s;return s;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
vec iota(int n){vec a(n);iota(all(a),0);return a;}
void print(){putchar(' ');}
void print(bool a){cout<<a;}
void print(int a){cout<<a;}
void print(long long a){cout<<a;}
void print(char a){cout<<a;}
void print(string &a){cout<<a;}
void print(double a){cout<<a;}
template<class T> void print(const vector<T>&);
template<class T, size_t size> void print(const array<T, size>&);
template<class T, class L> void print(const pair<T, L>& p);
template<class T, size_t size> void print(const T (&)[size]);
template<class T> void print(const vector<T>& a){ if(a.empty()) return; print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ cout<<" "; print(*i); } cout<<endl;}
template<class T> void print(const deque<T>& a){ if(a.empty()) return; print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ cout<<" "; print(*i); } }
template<class T, size_t size> void print(const array<T, size>& a){ print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ cout<<" "; print(*i); } }
template<class T, class L> void print(const pair<T, L>& p){ cout<<'(';print(p.first); cout<<","; print(p.second);cout<<')'; }
template<class T, size_t size> void print(const T (&a)[size]){ print(a[0]); for(auto i = a; ++i != end(a); ){ cout<<" "; print(*i); } }
template<class T> void print(const T& a){ cout << a; }
int out(){ putchar('\n'); return 0; }
template<class T> int out(const T& t){ print(t); putchar('\n'); return 0; }
template<class Head, class... Tail> int out(const Head& head, const Tail&... tail){ print(head); putchar(' '); out(tail...); return 0; }
ll gcd(ll a, ll b){ while(b){ ll c = b; b = a % b; a = c; } return a; }
ll lcm(ll a, ll b){ if(!a || !b) return 0; return a * b / gcd(a, b); }
vector<pll> factor(ll x){ vector<pll> ans; for(ll i = 2; i * i <= x; i++) if(x % i == 0){ ans.push_back({i, 1}); while((x /= i) % i == 0) ans.back().second++; } if(x != 1) ans.push_back({x, 1}); return ans; }
vector<int> divisor(int x){ vector<int> ans; for(int i=1;i*i<=x;i++)if(x%i==0){ans.pb(i);if(i*i!=x)ans.pb(x/i);} return ans;}
int popcount(ll x){return __builtin_popcountll(x);}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int n){return uniform_int_distribution<int>(0, n)(rng);}
// #define _GLIBCXX_DEBU
#define endl '\n'
#ifdef _MY_DEBUG
    #undef endl
    #define debug(x) cout<<#x<<": "<<x<<endl
    void err(){}
    template<class T> void err(const T& t){ print(t);  cout<<" ";}
    template<class Head, class... Tail> void err(const Head& head, const Tail&... tail){ print(head); putchar(' '); out(tail...); }
#else
    #define debug(x)
    template<class... T> void err(const T&...){}
#endif
#pragma endregion
template< typename T >
struct edge {
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}

  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);cout<<fixed<<setprecision(15);
    int n=in(),m=in();
    WeightedGraph<ll> g(n);
    rep(i,n-1){
        int a=in()-1,b=in()-1;
        ll c=in();
        g[a].eb(b,c);
        g[b].eb(a,c);
    }
    bool flag = false;
    if(g[0].size()>2 or g[n-1].size()>2)flag = true;
    rep(i,n)if(g[i].size()>3)flag = true;
    vector<int> path(n);
    vector<ll> d(n);
    vec P{n-1};
    {
        auto dfs=[&](auto &f,int x,int p)->bool{
            if(x == n-1)return path[x]=true;
            bool res = false;
            for(auto e:g[x]){
                if(e!=p){
                    if(f(f,e,x)){
                        d[x] = d[e]+e.cost;
                        res = true;
                    }
                }
            }
            if(res)P.pb(x);
            return path[x]=res;
        };
        dfs(dfs,0,-1);
    }
    rep(i,n){
        if(!path[i] and g[i].size()>1) flag = true;
    }
    if(flag){
        rep(_,m){
            in();
            cout<<d[0]<<endl;
        }
    }
    else{
        ll mi = LONG_LONG_MAX;
        rep(i,n){
            if(!path[i]){
                int p = g[i].back();
                for(auto e:g[p]){
                    if(e==i)continue;
                    chmin(mi,e.cost-g[i].back().cost);
                }
            }
        }
        rep(i,P.size()-2){
            chmin(mi,d[P[i+2]]-d[P[i]]);
        }
        ll ma = -1e16;
        rep2(i,0,P.size()-1){
            int now = P[i];
            if(now!=0 and now!= n-1 and g[now].size()==2)continue;
            if((now==0 or now==n-1) and g[now].size()==1)continue;
            ll a ;
            for(auto e:g[now])if(!path[e])a=e.cost;
            chmin(mi,d[now]-a-ma);
            chmax(ma,d[now]+a);
        }
        // cout<<d[0]<<" "<<mi<<endl;
        while(m--){
            ll x = in();
            if(x>mi)cout<<d[0]<<endl;
            else{
                cout<<d[0] -mi + x << endl;
            }
        }
    }




}