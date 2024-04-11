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
char d[7] = {'a','b','a','c','a','b','a'};

class RollingHash{
    const ll mod = 1e9+7;
    const ll base = 1007;
    V<> hash, power;
public:
    RollingHash(const string &s){
        ll n = SZ(s);
        hash.assign(n+1, 0);
        power.assign(n+1, 1);
        REP(i,n){
            hash[i+1] = (hash[i] * base + s[i]) % mod;
            power[i+1] = (power[i] * base) % mod;
        }
    }
    inline ll get(ll l, ll r) const {
        ll res = hash[r] - hash[l] * power[r-l] % mod;
        if(res < 0) res += mod;
        return res;
    }
    inline ll s_hash(){return get(0, SZ(hash) - 1);}
    inline ll getLCP (int a, int b) const {
        ll len = min(SZ(hash)-a, SZ(hash)-b);
        ll ok = 0, ng = len;
        while(abs(ok-ng) > 1){
            ll mid = (ok+ng) / 2;
            if(get(a, a+mid) != get(b, b+mid)) ng = mid;
            else ok = mid;
        }
        return ok;
    }
};

int n; string s;

void solve(){
    cin >> n >> s;
    RollingHash t("abacaba");
    ll z = t.s_hash();
    for(int i = 3; i < n - 3; i++){
        if(s[i] != 'c' and s[i] != '?') continue;
        bool can = true;
        for(int j = -3; j <= 3; j++){
            if(!j) continue;
            if(s[i + j] != (abs(j)%2 ? 'a': 'b') and s[i + j] != '?') can = false;
        }
        if(can){
            string u = s;
            u.replace(i - 3, 7, "abacaba");
            REP(i, n) if(u[i] == '?') u[i] = 'z';
            RollingHash RH(u);
            ll cnt = 0;
            for(int i = 3; i < n - 3; i++) if(RH.get(i - 3, i + 4) == z) cnt++;
            if(cnt == 1){
                cout << "Yes" << endl << u << endl;
                return;
            }
        }
    }
    cout << "No" << endl;
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
}