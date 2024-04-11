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
#define endl "\n"
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

int n;
bool solve(vec x){
    vector<vec> a(n,vec(n));
    rep(i,n)rep(j,n)a[i][j]=x[i*n+j];
    int sx,sy;
    rep(i,n)rep(j,n){
        if(a[i][j]==1)sx=i,sy=j;
    }
    int tx=sx,ty=sy;
    int rook=0;
    int vis[3][3]={};
    vis[sx][sy]=1;
    rep(_i,8){
        int mi = INT_MAX;
        int memx,memy;
        rep(i,3)rep(j,3){
            if(!vis[i][j] and (i==sx or j==sy)){
                if(chmin(mi,a[i][j]))memx=i,memy=j;
            }
        }
        if(mi==INT_MAX){
            rep(i,3)rep(j,3){
                if(!vis[i][j] and chmin(mi,a[i][j]))memx=i,memy=j;
            }
            rook++;
        }
        vis[memx][memy]=1;
        sx=memx,sy=memy;
    }
    int queen=0;
    rep(i,3)rep(j,3)vis[i][j]=0;
    vis[tx][ty]=1;
    sx = tx,sy=ty;
    rep(_i,8){
        int mi = INT_MAX;
        int memx,memy;
        rep(i,3)rep(j,3){
            if(!vis[i][j] and (i==sx or j==sy or (i-j) == (sx-sy) or i+j==sx+sy)){
                if(chmin(mi,a[i][j]))memx=i,memy=j;
            }
        }
        if(mi==INT_MAX){
            rep(i,3)rep(j,3){
                if(!vis[i][j] and chmin(mi,a[i][j]))memx=i,memy=j;
            }
            queen++;
        }
        vis[memx][memy]=1;
        sx=memx,sy=memy;
    }
    if(queen>rook){
        rep(i,3)print(a[i]);
        return true;
    }
}
vector<vec> t{{1,2,4},{5,3,8},{9,6,7}};
signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);cout<<fixed<<setprecision(15);
    n=in();
    int a[510][510];
    if(n<=2){
        cout<<-1<<endl;
    }
    else if(n==3){
        rep(i,3)print(t[i]);
    }
    else{
        int now=1;
        rep(T,n-3){
            if(T&1){
                rep3(j,n-1,T){
                    a[T][j]=now++;
                }
                rep2(i,T+1,n-1){
                    a[i][T]=now++;
                }
            }
            else{
                rep3(i,n-1,T){
                    a[i][T]=now++;
                }
                rep2(j,T+1,n-1) a[T][j]=now++;
            }
        }
        if(n&1){
            swap(a[n-3][n-4],a[n-1][n-4]);
        }
        else swap(a[n-4][n-3],a[n-4][n-1]);
        rep2(i,n-3,n-1){
            rep2(j,n-3,n-1){
                a[i][j]=t[i-(n-3)][j-(n-3)]+now-1;
            }
        }
        rep(i,n){
            rep(j,n){
                cout<<a[i][j]<<" ";
            }cout<<endl;
        }
    }

}