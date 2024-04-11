#pragma region Macros
#pragma GCC optimize("O3")

#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;++i)
#define rep3(i,a,b) for(ll i=a;i>=b;--i)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define vec vector<int>
#define vll vector<ll>
#define vpi vector<pii>
#define vpll vector<pll>
#define overload2(_1,_2,name,...) name
#define vv(a,b) vector<vector<int>>(a,vector<int>(b))
#define vv2(a,b,c) vector<vector<int>>(a,vector<int>(b,c))
#define vvl(a,b) vector<vector<ll>>(a,vector<ll>(b))
#define vvl2(a,b,c) vector<vector<ll>>(a,vector<ll>(b,c))
#define vvv(a,b,c) vector<vv(b,c)>(a)
#define vvv2(a,b,c,d) vector<vv(b,c,d)>(a)
#define vvvl(a,b,c) vector<vvl(b,c)>(a)
#define vvvl2(a,b,c,d) vector<vvl(b,c,d)>(a)
#define fi first
#define se second
#define all(c) begin(c),end(c)
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance((c).begin(),lower_bound(all(c),(x)))
#define ub(c,x) distance((c).begin(),upper_bound(all(c),(x)))
using namespace std;
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;
#define Size(c) (int)(c).size()
#define INT(...) int __VA_ARGS__;IN(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;IN(__VA_ARGS__)
#define ULL(...) ull __VA_ARGS__;IN(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;IN(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;IN(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;IN(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__;IN(__VA_ARGS__)
#define VEC(type,name,size) vector<type> name(size);IN(name)
#define VV(type,name,h,w) vector<vector<type>>name(h,vector<type>(w));IN(name)
int scan(){ return getchar(); }
void scan(int& a){ cin>>a; }
void scan(long long& a){ cin>>a; }
void scan(char &a){cin>>a;}
void scan(double &a){ cin>>a; }
void scan(long double& a){ cin>>a; }
void scan(char a[]){ scanf("%s", a); }
void scan(string& a){ cin >> a; }
template<class T> void scan(vector<T>&);
template<class T, size_t size> void scan(array<T, size>&);
template<class T, class L> void scan(pair<T, L>&);
template<class T, size_t size> void scan(T(&)[size]);
template<class T> void scan(vector<T>& a){ for(auto& i : a) scan(i); }
template<class T> void scan(deque<T>& a){ for(auto& i : a) scan(i); }
template<class T, size_t size> void scan(array<T, size>& a){ for(auto& i : a) scan(i); }
template<class T, class L> void scan(pair<T, L>& p){ scan(p.first); scan(p.second); }
template<class T, size_t size> void scan(T (&a)[size]){ for(auto& i : a) scan(i); }
template<class T> void scan(T& a){ cin >> a; }
void IN(){}
template <class Head, class... Tail> void IN(Head& head, Tail&... tail){ scan(head); IN(tail...); }
string stin() {string s;cin>>s;return s;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
vi iota(int n){vi a(n);iota(all(a),0);return a;}
template<class T> void UNIQUE(vector<T> &x){sort(all(x));x.erase(unique(all(x)),x.end());}
int in() {int x;cin>>x;return x;}
ll lin() {unsigned long long x;cin>>x;return x;}
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
template<class T> void print(set<T> &x){for(auto e:x)print(e),cout<<" ";cout<<endl;}
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
int rnd(int n){return uniform_int_distribution<int>(0, n-1)(rng);}
#define endl '\n'

#ifdef _LOCAL
    #undef endl
    #define debug(x) cout<<#x<<": ";print(x);cout<<endl;
    void err(){}
    template<class T> void err(const T& t){ print(t);  cout<<" ";}
    template<class Head, class... Tail> void err(const Head& head, const Tail&... tail){ print(head); putchar(' '); out(tail...); }
#else
    #define debug(x)
    template<class... T> void err(const T&...){}
#endif
#pragma endregion



template<class Monoid = int, class OperatorMonoid = Monoid >
struct Treap{
    using F = function<Monoid(Monoid,OperatorMonoid)>; // 
    using G = function<OperatorMonoid(OperatorMonoid,OperatorMonoid)>; // 
    const Monoid M1;
    const OperatorMonoid OM0;
    const F f;
    const G g;
    struct node{
        int pri;
        Monoid key;
        OperatorMonoid lazy; // 
        node *l,*r;
        int size;
        node() = default;
        node(Monoid key,OperatorMonoid OM):key(key),pri(rnd(INT_MAX)),size(1),l(nullptr),r(nullptr),lazy(OM){}
    };

    vector<node> nodes;
    int ptr;

    inline node* allocate(Monoid key){return &(nodes[ptr++] = node(key,OM0));}

    Treap(int n,const F &f,const G &g,const Monoid M1,const OperatorMonoid OM0):
        f(f),g(g),M1(M1),OM0(OM0),ptr(0),nodes(n){}
    
    node* root = nullptr;
    int size(node* t){return t!=nullptr ? t->size : 0;}

    void propagate(node* t){
        if(t == nullptr) return;
        t->key = f(t->key,t->lazy);
        if(t->l){
            t->l->lazy = g(t->l->lazy,t->lazy);
        }
        if(t->r){
            t->r->lazy = g(t->r->lazy,t->lazy);
        }
        t->lazy = OM0;
    }

    node* refresh(node* t){
        propagate(t);
        if(t == nullptr) return t;
        t->size = 1 + size(t->l) + size(t->r);
        return t;
    }

    pair<node* ,node* > split(node* &t, Monoid k){
        propagate(t);
        if(!t) return {t,t};
        else if(t->key < k){
            auto p = split(t->r,k);
            t->r = p.fi;
            return {refresh(t),p.se};
        }
        else{
            auto p = split(t->l,k);
            t->l = p.se;
            return {p.fi,refresh(t)};
        }
    }

    node* merge(node* a,node* b){
        propagate(a);
        propagate(b);
        if(!a or !b) return a ? a : b;
        if(a->pri < b->pri){
            a->r = merge(a->r,b);
            return refresh(a);
        }
        else{
            b->l = merge(a,b->l);
            return refresh(b);
        }
    }

    node* count(node* t,Monoid k){
        propagate(t);
        if(!t) return nullptr;
        if(k < t->key) return count(t->l,k);
        if(k == t->key) return t;
        return count(t->r,k);
    }

    node* nth(node* t, int n){
        propagate(t);
        if(!t) return nullptr;
        if(n <= size(t->l)) return nth(t->l,n);
        if(n == size(t->l) + 1) return t;
        return nth(t->r,n - size(t->l) - 1);
    }

    void del(node* &t){
        propagate(t);
        if(!t) return;
        if(t->l) del(t->l);
        if(t->r) del(t->r);
        t = nullptr;
    }

    // merge
    void send(node* &from,node* &to,Monoid k){
        propagate(from);
        if(!from) return;
        if(from -> l) send(from->l,to,k);
        if(from -> r) send(from->r,to,k);
        Monoid M = from->key;
        get<0>(M)-=get<0>(k);
        auto [a,b] = split(to,M);
        get<1>(M)++;
        to = merge(merge(a,allocate(M)),b);
        from = nullptr;
    }

    bool count(Monoid k){ return count(root,k) != nullptr;}

    node* insert(Monoid k){
        auto [l,r] = split(root,k);
        auto c = allocate(k);
        return root = merge(merge(l,c),r);
    }

    // [k,k2) 
    bool erase(Monoid k,Monoid k2){
        node *f = count(root,k);
        if(!f) return false;
        node *a,*b,*c,*d;
        split(root,k,a,b);
        split(b,k2,c,d);
        root = merge(a,d);
        return true;
    }
    Monoid nth(int n){
        n++;
        node* ans = nth(root,n);
        return ans ? ans->key : M1;
    }
    void solve(int k){
        Monoid K(k,0,0);
        auto [a,b] = split(root,K);
        auto [c,d] = split(b,Monoid(k*2,0,0));
        send(c,a,K);
        if(d){
            d->lazy = OperatorMonoid(k,1);
        }
        root = merge(a,d);
    }

};
        



        
        


signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);cout<<fixed<<setprecision(15);
    INT(n);
    vector<pll> v;
    rep(i,n){
        INT(c,q);v.eb(c,q);
    }
    sort(all(v),[](pll x,pll y){if(x.se!=y.se) return x.se>y.se;return x.fi<y.fi;});
    vector<ll> a;
    for(auto [aa,b]:v)a.pb(aa);
    INT(k);
    VEC(int,b,k);
    using triple = tuple<int,int,int> ;
    auto f = [](triple x,pii y){triple xx = x; get<0>(xx)-=y.fi; get<1>(xx)+=y.se; return xx;};
    auto g = [](pii x,pii y){return pii(x.fi+y.fi,x.se+y.se);};
    Treap<triple,pii> tree(5000000,f,g,triple(0,0,0),pii(0,0));
    rep(i,k){
        tree.insert(triple(b[i],0,i));
    }
    auto pr=[](triple x){
        cout<<get<0>(x)<<" "<<get<1>(x)<<" "<<get<2>(x)<<endl;
    };
    for(auto c:a){
        // cout<<c<<endl;
        tree.solve(c);
        // rep(i,k)pr(tree.nth(i));
    }
    vec ans(k);
    rep(i,k){
        auto t = tree.nth(i);
        ans[get<2>(t)] = get<1>(t);
    }
    print(ans);

}