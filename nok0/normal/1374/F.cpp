#include<bits/stdc++.h>
using namespace std;
#pragma region Macros
#define ll long long
#define ld long double
#define FOR(i,l,r) for(ll i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(ll i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,n-1,0)
#define RREPS(i,n) RFOR(i,n,1)
#define pb push_back
#define eb emplace_back
#define SZ(x) ((ll)(x).size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
template<class T = ll> using V = vector<T>;
template<class T = ll> using VV = V<V<T>>;
using P = pair<ll, ll>;
#define VEC(type, name, size)\
    V<type> name(size);\
    IN(name)
#define VVEC(type, name, h, w)\
    VV<type> name(h, V<type>(w));\
    IN(name)
#define INT(...)\
    int __VA_ARGS__;\
    IN(__VA_ARGS__)
#define LL(...)\
    ll __VA_ARGS__;\
    IN(__VA_ARGS__)
#define STR(...)\
    string __VA_ARGS__;\
    IN(__VA_ARGS__)
#define CHAR(...)\
    char __VA_ARGS__;\
    IN(__VA_ARGS__)
#define DOUBLE(...)\
    DOUBLE __VA_ARGS__;\
    IN(__VA_ARGS__)
#define LD(...)\
    LD __VA_ARGS__;\
    IN(__VA_ARGS__)
template <class T> void scan(T a) { cin >> a; }
void scan(int &a) { cin >> a; }
void scan(long long &a) { cin >> a; }
void scan(char &a) { cin >> a; }
void scan(double &a) { cin >> a; }
void scan(long double &a) { cin >> a; }
void scan(char a[]) { scanf("%s", a); }
void scan(string &a) { cin >> a; }
template <class T> void scan(V<T> &);
template <class T, class L> void scan(pair<T, L> &);
template <class T> void scan(V<T> &a) { for(auto &i : a) scan(i); }
template <class T, class L> void scan(pair<T, L> &p){ scan(p.first); scan(p.second); }
template <class T> void scan(T &a) { cin >> a; }
void IN() {}
template <class Head, class... Tail> void IN(Head &head, Tail &... tail) { scan(head); IN(tail...); }
template <class T> inline void print(T x){ cout << x << '\n';}
struct inputoutputfaster{
    inputoutputfaster(){
        ios::sync_with_stdio(false);\
        cin.tie(nullptr);
        cout << fixed << setprecision(15);
    }
}inputoutputfaster_;
template <class T> V<T> press(V<T> &x){ 
    V<T> res = x;
    sort(all(res));
    res.erase(unique(all(res)), res.end());
    REP(i, SZ(x)){
        x[i] = lower_bound(all(res), x[i]) - res.begin();
    }
    return res;
}
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true; }return false; }
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true; }return false; }
inline void Yes(bool b = true) {cout << (b ? "Yes" : "No") << '\n';}
inline void YES(bool b = true) {cout << (b ? "YES" : "NO") << '\n';}
inline void err(bool b = true) {if(b) {cout << -1 << '\n'; exit(0);}}
template<class T> inline void fin(bool b = true, T e = 0) {if(b) {cout << e << '\n'; exit(0);}}
template<class T> T divup(T x, T y) {return (x+(y-1))/y;}
template <typename T> T pow(T a, long long n, T e = 1) {T ret = e; while (n) {if (n & 1) ret *= a; a *= a; n >>= 1; } return ret; }
const ll INF = 1e18;
#pragma endregion

// Binary Indexed Tree (Fenwick Tree)
template <typename T>
struct BIT {
    int n,p;
    vector<T> d;
    BIT(int n=0) :n(n), d(n+1) {
        p = 1;
        while(p < n)p *= 2;
    }
    //
    void add(int i,T x=1){
        for(i++;i <= n;i += i&-i) d[i] += x;
    }
    //[0,i)
    T sum(int i){
        T res = 0;
        for(;i;i -= i&-i) res += d[i];
        return res;
    }
    //[l,r)
    T sum(int l,int r){ return sum(r) - sum(l);}
    //v0+v1+vx>=mmin(x)
    int lower_bound(T w){
        if(w <= 0) return 0;
        T x = 0;
        for ( int i=p;i;i/=2){
            if(i+x <=n &&d[i+x] < w){
                w -= d[i+x];
                x += i;
            }
        }
        return x;
    }
};

void solve(){
    INT(n);
    VEC(int, a, n);
    auto b = a;
    sort(all(b));
    b.erase(unique(all(b)), b.end());
    if(SZ(b) == n){
        BIT<int> BT(510);
        int inversion = 0;
        REP(i, n){ 
            inversion += i - BT.sum(a[i]);
            BT.add(a[i]);
        }
        if(inversion % 2){
            print(-1);
            return;
        }
    }
    V<P> pa(n);
    REP(i, n) pa[i] = {a[i], i};
    sort(all(pa));
    REP(i, n) a[pa[i].second] = i;
    BIT<int> BT2(510);
    int inversion2 = 0;
    REP(i, n){ 
        inversion2 += i - BT2.sum(a[i]);
        BT2.add(a[i]);
    }
    if(inversion2 % 2){ 
        REP(i, n - 1) if(pa[i].first == pa[i + 1].first){
            a[pa[i].second] = i + 1;
            a[pa[i + 1].second] = i;
            break;
        }
    }
    int bad = -1;
    REP(i, n) if(a[i] != i){
        bad = i;
        break;
    }
    V<> res;
    while(bad != -1){
        int place;
        REP(i, n) if(a[i] == bad){
            place = i;
            break;
        }
        if(place - bad > 2){
            res.pb(place - 2);
            int x = a[place - 2], y = a[place - 1], z = a[place];
            a[place - 2] = z, a[place - 1] = x, a[place] = y;
            continue;
        }
        if(place - bad == 2){
            res.pb(bad);
            int x = a[bad], y = a[bad + 1], z = a[bad + 2];
            a[bad] = z, a[bad + 1] = x, a[bad + 2] = y;
            bad = -1;
            REP(i, n) if(a[i] != i){
                bad = i;
                break;
            }
            continue;
        }
        if(place - bad == 1){
            res.pb(bad);
            int x = a[bad], y = a[bad + 1], z = a[bad + 2];
            a[bad] = z, a[bad + 1] = x, a[bad + 2] = y;
        }
    }
    print(SZ(res));
    for(auto v : res) cout << v + 1 << " ";
    cout << endl;
}

int main(){
    INT(t);
    while(t--) solve();
}