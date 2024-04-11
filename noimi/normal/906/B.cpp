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
#define lb(c,x) distance(c.begin(),lower_bound(all(c),(x)))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),(x)))
using namespace std;
int in() {int x;cin>>x;return x;}
ll lin() {ll x;cin>>x;return x;}
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
#define _GLIBCXX_DEBU
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

vec A = {1,4,2,0,3};
vec f(vec &a){
    int n = a.size();
    deque<int> dq;
    for(auto e:A)dq.pb(e);
    rep2(i,5,n-1){
        if(i&1)dq.pb(i);
        else dq.push_front(i);
    }
    vec b;
    rep(i,n){
        b.pb(a[dq.front()]);
        dq.pop_front();
    }
    return b;
}

void print(int n,int m,vector<vec> ans,bool sw){
    vector<vec> v;
    if(!sw){
        rep(i,n){
            rep(j,m)cout << ans[i][j]<<" ";cout<<endl;
        }
        return ;
    }
    rep(j,m){
        rep(i,n){
            int J = (ans[i][j]-1)%m;
            int I = (ans[i][j]-1)/m;
            cout << 1+J*n + I <<" ";
        }
        cout << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);cout<<fixed<<setprecision(15);
    int n=in(),m=in();
    bool sw = 0;
    if(n>m)swap(n,m),sw=1;
    auto v = vec2(n,m);
    vector<vec> ans;
    if(n==1){
        if(m==1){
            cout <<"YES\n1\n";return 0;
        }
        else if(m<4){
            cout << "NO\n";return 0;
        }
        else if(m==4){
            ans = {{3,1,4,2}};
        }
    }
    else if(n==2){
        if(m<4){
            cout <<"NO\n";return 0;
        }
        else if(m==4){
            ans={{5,4,7,2},{3,6,1,8}};
        }
    }
    else if(n==3){
        if(m==3){
            ans = {{8,3,4},{1,5,9},{6,7,2}};
        }
        else if(m==4){
            ans = {{2,4,1,3}};
            rep(i,n-1){
                vec tmp;
                rep(j,m)tmp.pb(ans.back()[j]+m);
                ans.pb(tmp);
                reverse(all(ans.back()));
            }
        }
    }
    else if(n==4 and m==4){
        ans = {{2,4,1,3}};
        rep(i,n-1){
            vec tmp;
            rep(j,m)tmp.pb(ans.back()[j]+m);
            ans.pb(tmp);
            if(i&1)reverse(all(ans.back()));
        }
    }
    cout << "YES\n";
    if(ans.size()==0){
        rep(i,n){
            vec tmp;
            if(i&1){
                for(int j=0;j<m;j+=2)tmp.pb(1+i*m+j);
                for(int j=1;j<m;j+=2)tmp.pb(1+i*m+j);
            }
            else{
                for(int j=1;j<m;j+=2)tmp.pb(1+i*m+j);
                for(int j=0;j<m;j+=2)tmp.pb(1+i*m+j);
            }
            ans.pb(tmp);
        }
    }
    print(n,m,ans,sw);


}