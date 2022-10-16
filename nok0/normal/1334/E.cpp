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

ll u, v;

ll lcm(ll x,ll y) {return x/__gcd(x,y)*y;};

//Modulo Calculation
const int MOD = 998244353;

//ModInt
template <int mod>
struct ModInt {
    int x;
    ModInt() : x(0) {}
    ModInt(ll x_) {
        if ((x = x_ % mod + mod) >= mod) x -= mod;
    }
    ModInt& operator+=(ModInt rhs) {
        if ((x += rhs.x) >= mod) x -= mod;
        return *this;
    }
    ModInt& operator-=(ModInt rhs) {
        if ((x -= rhs.x) < 0) x += mod;
        return *this;
    }
    ModInt& operator*=(ModInt rhs) {
        x = (unsigned long long)x * rhs.x % mod;
        return *this;
    }
    ModInt& operator/=(ModInt rhs) {
        x = (unsigned long long)x * rhs.inv().x % mod;
        return *this;
    }
  
    ModInt operator-() const { return -x < 0 ? mod - x : -x; }
    ModInt operator+(ModInt rhs) const { return ModInt(*this) += rhs; }
    ModInt operator-(ModInt rhs) const { return ModInt(*this) -= rhs; }
    ModInt operator*(ModInt rhs) const { return ModInt(*this) *= rhs; }
    ModInt operator/(ModInt rhs) const { return ModInt(*this) /= rhs; }
    bool operator==(ModInt rhs) const { return x == rhs.x; }
    bool operator!=(ModInt rhs) const { return x != rhs.x; }
    ModInt inv() const { return pow(*this, mod - 2); }
  
    friend ostream& operator<<(ostream& s, ModInt<mod> a) {
        s << a.x;
        return s;
    }
    friend istream& operator>>(istream& s, ModInt<mod>& a) {
        s >> a.x;
        return s;
    }
};
using mint = ModInt<MOD>;

//

const int MAX = 100010;
mint fac[MAX],finv[MAX],inv[MAX];
//
void COMinit(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<MAX;i++){
        fac[i]=fac[i-1]*(mint)i;
        inv[i]=(mint)MOD-inv[MOD%i]*(mint)(MOD/i);
        finv[i]=finv[i-1]*inv[i];
    }
}

//nCk
mint COM(int n,int k){
    if(n < k or n < 0 or k < 0)return 0;
    return fac[n]*finv[k]*finv[n-k];
}

//nPk
mint PER(int n, int k){
    if(n < k or n < 0 or k < 0) return 0;
    return fac[n] / fac[n-k];
}

//nHk
mint HOM(int n, int k) {return COM(n+k-1, k);};

map<ll,mint> ans;

V<pair<ll, int>> divisor;

void dfs(ll nownum, int pl, mint res, int sum){
    if(pl == SZ(divisor)){
        ans[nownum] = res * fac[sum];
        return;
    }
    REP(i, divisor[pl].second + 1){
        ll newnum = nownum * pow(divisor[pl].first, i);
        mint newres = res * finv[i];
        int newsum = sum + i;
        dfs(newnum, pl + 1, newres, newsum);
    }
}

void PF_solve(ll n){ 
    mint res = 1;
    ll c = n;
    ll num = 0;
    for(ll i = 2; i <= sqrt(n); i++){
        if(c%i) continue;
        ll cnt = 0;
        while(c%i == 0){
            cnt++;
            c /= i;
        }
        divisor.pb({i,cnt});
    }
    if(c != 1) divisor.pb({c,1});
	dfs(1,0,1,0);
    return;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    COMinit();
    ll d, q; cin >> d >> q;
    PF_solve(d);
    while(cin >> u >> v){ 
        if(v > u) swap(v, u);
        if((lcm(u,v) == 1 and (v != 1)) or u == v){
            cout << 1 << endl;
            continue;
        }
        ll z = __gcd(u, v);
        v /= z; u /= z;
        cout << ans[v] * ans[u] << '\n';
    }
}