#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true; }return false; }
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true; }return false; }
inline void Yes(bool b = true) {cout << (b ? "Yes" : "No") << '\n';}
inline void YES(bool b = true) {cout << (b ? "YES" : "NO") << '\n';}
inline void err(bool b = true) {if(b) {cout << -1 << '\n'; exit(0);}}
template<class T> inline void fin(bool b = true, T e = 0) {if(b) {cout << e << '\n'; exit(0);}}
template<class T> T Roundup_div(T x, T y) {return (x+(y-1))/y;}
const ll INF = 1e18;
template <typename T>
T pow(T a, long long n, T e = 1) {
    T ret = e;
    while (n) {
        if (n & 1) ret *= a;
        a *= a;
        n >>= 1;
    }
    return ret;
}

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

int a;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    BIT<int> BT(n);
    REP(i, n){
        cin >> a; a--; BT.add(a, 1);
    }
    while(q--){
        cin >> a; 
        if(a > 0) BT.add(a - 1, 1);
        else{
            a *= -1; 
            BT.add(BT.lower_bound(a), -1);
        }
    }
    REP(i, n)if(BT.sum(i, i+1)){
        cout << i + 1 << endl;
        return 0;
    }
    cout << 0 << endl;
}