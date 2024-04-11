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
template<class T> void UNIQUE(vector<T> &x){sort(all(x));x.erase(unique(all(x)),x.end());}
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
 
ll n,m,seed;
constexpr ll MOD = 1e9+7;
ll RND(){
    ll ret = seed;
    seed = (seed*7+13)%MOD;
    return ret;
}

struct op{
    ll o,l,r,x,y;
    void print(){
        cout<<o<<" "<<l<<" "<<r<<" "<<x;
        if(o==3)cout<<" "<<y;
        cout<<endl;
    }
};

ll modpow(ll x,ll nn,ll mod){
    x%=mod;
    ll res=1;
    while(nn){
        if(nn&1)res=res*x%mod;
        x = x*x%mod;
        nn>>=1;
    }
    return res;
}
struct A{
    int l,r;
    ll a;
    A(int _l,int _r,ll _a=0):l(_l),r(_r),a(_a){}
    bool operator<(const A &rhs)const{
        if(l==rhs.l)return r<rhs.r;
        else return l<rhs.l;
    }
    void print(){
        cout<<"("<<l<<","<<r<<","<<a<<")";
    }
};
signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);cout<<fixed<<setprecision(15);
    n=in(),m=in(),seed=in();
    ll v =lin();
    vecll a;
    rep(i,n)a.pb(RND()%v+1);
    vector<op> b;
    rep(i,m){
        int o = RND()%4;
        ll l = RND()%n,r=RND()%n;
        if(l>r)swap(l,r);
        ll x;
        if(o==2)x = RND()%(r-l+1)+1;
        else x = RND()%v+1;
        ll y;
        if(o==3)y=RND()%v + 1;
        b.pb(op{o,l,r,x,y});
        // b.back().print();
    }
    set<A> s;
    ll tmp = a[0],cnt = 0;
    rep(i,n){
        if(a[i]==tmp)cnt++;
        else{
            s.emplace((int)i-cnt,(int)i-1,tmp);
            tmp = a[i],cnt=1;
        }
    }
    s.emplace(n-cnt,n-1,tmp);
    rep(i,m){
        op &now = b[i];
        int l = b[i].l,r = b[i].r;
        ll x = b[i].x,y=b[i].y;
        auto it = s.lower_bound(A(l,INT_MAX));
        it--;
        vector<A> res;
        // for(auto e:s)e.print();
        // cout<<endl;
        if(now.o<1){
            while(1){
                int L = (*it).l,R=(*it).r;
                ll aa = it->a;
                if(L>=l and R<=r){
                    res.eb(L,R,x+aa);
                }
                else if(L<l and R<= r){
                    res.eb(L,l-1,aa);
                    res.eb(l,R,aa+x);
                }
                else if(L>=l and R>r){
                    res.eb(L,r,aa+x);
                    res.eb(r+1,R,aa);
                }
                else{
                    res.eb(L,l-1,aa);
                    res.eb(l,r,aa+x);
                    res.eb(r+1,R,aa);
                }
                it=s.erase(it);
                if(r<=R)break;
            }
        }
        else if(now.o==1){
            while(1){
                int L =(*it).l,R=(*it).r;
                ll aa = (*it).a;
                if(L>=l and R<=r){
                    ;
                }
                else if(L<l and R<= r){
                    res.eb(L,l-1,aa);
                    ;
                }
                else if(L>=l and R>r){
                    res.eb(r+1,R,aa);
                }
                else{
                    res.eb(L,l-1,aa);
                    res.eb(r+1,R,aa);
                }
                it = s.erase(it);
                if(r<=R)break;
            }
            res.eb(l,r,x);
        }
        else if(now.o==2){
            multiset<pair<ll,int>> se;
            while(1){
                int L =(*it).l,R=(*it).r;
                ll aa = (*it).a;
                if(L>=l and R<=r){
                    se.emplace(aa,R-L+1);
                }
                else if(L<l and R<= r){
                    se.emplace(aa,R-l+1);
                }
                else if(L>=l and R>r){
                    se.emplace(aa,r-L+1);
                }
                else{
                    se.emplace(aa,r-l+1);
                }
                if(r<=R)break;it++;
            }
            int rui=0;
            for(auto e:se){
                
                rui+=e.se;
                if(rui>=x){
                    cout<<e.fi<<endl;
                    break;
                }
            }
        }
        else{
            multiset<pair<ll,int>> se;
            while(1){
                int L =(*it).l,R=(*it).r;
                ll aa = (*it).a;
                if(L>=l and R<=r){
                    se.emplace(aa,R-L+1);
                }
                else if(L<l and R<= r){
                    se.emplace(aa,R-l+1);
                }
                else if(L>=l and R>r){
                    se.emplace(aa,r-L+1);
                }
                else{
                    se.emplace(aa,r-l+1);
                }
                if(r<=R)break;it++;
            }
            ll ans = 0;
            for(auto e:se){
                ans=(ans + modpow(e.fi,x,y)*e.se%y)%y;
            }
            cout<<ans<<endl;
        }
        for(auto e:res)s.emplace(e);
    }




}