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


vector<vec> nxt;
int dp[300][300][300];
int n;
vec a,b,c;
void f(int i,int j,int k){
    int mi=n+1;
    if(i) chmin(mi,nxt[dp[i-1][j][k]][a[i-1]]);
    if(j) chmin(mi,nxt[dp[i][j-1][k]][b[j-1]]);
    if(k) chmin(mi,nxt[dp[i][j][k-1]][c[k-1]]);
    dp[i][j][k]=mi;
}
signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);cout<<fixed<<setprecision(15);
    n=in(); int q=in();
    nxt = vector(n+2,vec(26,n+1));
    string s;cin>>s;
    vector mem(26,n+1);
    rep3(i,n,0){
        rep(j,26){
            nxt[i][j]=mem[j];
        }
        if(i)
        mem[s[i-1]-'a']=i;
    }
    constexpr int MAX = 299;
    rep(i,MAX+1)rep(j,MAX+1)rep(k,MAX+1)dp[i][j][k]=n+1;
    dp[0][0][0]=0;
    int A=0,B=0,C=0;
    rep(_,q){
        char cc;cin>>cc;
        int x=in();
        if(cc=='+'){
            cin>>cc;
            int t = cc-'a';
            if(x==1){
                a.pb(t);
                A++;
                rep(j,B+1)rep(k,C+1)f(A,j,k);
            }
            if(x==2){
                b.pb(t);
                B++;
                rep(i,A+1)rep(k,C+1)f(i,B,k);
            }
            if(x==3){
                c.pb(t);
                C++;
                rep(i,A+1)rep(j,B+1)f(i,j,C);
            }
        }
        else{
            if(x==1){
                A--;
                a.pop_back();
            }
            if(x==2){
                B--;
                b.pop_back();
            }
            if(x==3){
                C--;
                c.pop_back();
            }
        }
        cout << (dp[A][B][C] < n+1 ? "YES":"NO") << endl;
    }

}