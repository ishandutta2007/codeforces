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

#define NO {cout<<"No\n";return 0;}

constexpr int T = 200000;
signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);cout<<fixed<<setprecision(15);
    int n=in(),m=in();
    vec pre;
    int k=in();rep(i,k)pre.pb(in());
    vec used(m+1);
    vector<vec> mem(m+1);
    rep(_i,n-1){
        k=in();
        vec now;rep(i,k)now.pb(in());
        int pos=0;
        int sz=min(pre.size(),now.size());
        while(pos<sz and pre[pos]==now[pos]){
            pos++;
        }
        if(pos==pre.size()){
            goto end;
        }
        if(pos==now.size()){
            NO
        }
        if(pre[pos] < now[pos]){
            int a=pre[pos],b=now[pos];
            if(used[b]==1){
                if(used[a]==2)NO
                used[a]=1;
                queue<int> q;q.push(a);
                while(!q.empty()){
                    int w=q.front();
                    q.pop();
                    for(auto e:mem[w]){
                        if(used[e]==2)NO
                        if(!used[e]){
                            used[e]=1;q.push(e);
                        }
                    }
                }
            }
            else if(used[a]!=1){
                mem[b].pb(a);
            }
        }
        else{
            int a=pre[pos],b=now[pos];
            if(used[a]==2)NO
            used[a]=1;
            queue<int> q;q.push(a);
            while(!q.empty()){
                int w=q.front();
                q.pop();
                for(auto e:mem[w]){
                    if(used[e]==2)NO
                    if(!used[e]){
                        used[e]=1;q.push(e);
                    }
                }
            }
            if(used[b]==1)NO
            used[b]=2;
        }
        end:
        pre.swap(now);
    }
    cout<<"Yes\n";
    int cnt=0;
    rep2(i,1,m)if(used[i]==1)cnt++;
    cout<<cnt<<endl;
    rep2(i,1,m)if(used[i]==1)cout<<i<<" ";
    cout<<endl;
}