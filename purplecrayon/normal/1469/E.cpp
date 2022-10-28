#include "bits/stdc++.h"
using namespace std;

template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;
 
#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e6+10, MAXM = 40, MAXL = 20, ALP = 20, MOD = 998244353, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

#include<bits/extc++.h>
 
struct splitmix64_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
 
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
 
template <typename K, typename V, typename Hash = splitmix64_hash>
using hash_map = __gnu_pbds::gp_hash_table<K, V, Hash>;
 
template <typename K, typename Hash = splitmix64_hash>
using hash_set = hash_map<K, __gnu_pbds::null_type, Hash>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r){
	return uniform_int_distribution<int>(l, r)(rng);
}
bool isPrime(ll c){
    for (ll i=2; i*i <= c; i++) if (c%i == 0) return false;
    return true;
}
ll genPrime(){
    ll c=rnd(5e8, 1e9); if ((c&1)^1) c++;
    while (!isPrime(c)) c+=2;
    return c;
}

#define SZ 2
ar<ll, SZ> bases, mods, po[MAXN];

ar<ll, SZ> mul(ar<ll, SZ> a, ar<ll, SZ> b){
    ar<ll, SZ> r;
    for (int i = 0; i < SZ; i++) r[i] = a[i]*b[i]%mods[i];
    return r;
}
void initHASH(){
    for (int i = 0; i < SZ; i++) bases[i] = rnd(3, 1e8);
    for (int i = 0; i < SZ; i++) mods[i] = genPrime();
    po[0].fill(1);
    for (int i = 1; i < MAXN; i++) po[i] = mul(po[i-1], bases);
}
struct hsh {
    int n;
    ar<ll, SZ> c;
    queue<int> q;
    void ad(int x){
        x++; q.push(x);
        c = mul(c, bases);
        for (int i = 0; i < SZ; i++){
            c[i] += x;
            if (c[i] > mods[i]) c[i] -= mods[i];
        }
        n++;
    }
    hsh(int _n){
        n = 0;
        c.fill(0);
        for (int i = 0; i < _n; i++) ad(0);
    }
    void pop(){
        int x=q.front();
        for (int i = 0; i < SZ; i++){
            c[i] -= po[n-1][i]*x%mods[i];
            if (c[i] < 0) c[i] += mods[i];
        }
        q.pop(); n--;
    }
    ll get(){
        ll x=0;
        for (int i = 0; i < SZ; i++) x ^= c[i] << (4*i);
        return x;
    }
    void pr(){
        queue<int> _q = q;
        while (sz(_q)){
            cerr << _q.front() << ' ';
            _q.pop();
        }
        cerr << '\n';
    }
};

void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
   
    for (int i = 0; i < n; i++) s[i] = s[i]^'0'^'1';
    hsh h(k); for (int i = 0; i < k; i++) h.pop(), h.ad(s[i]-'0');

    hash_set<ll> st;
    st.insert(h.get());
    for (int i = k; i < n; i++){
        h.pop(); h.ad(s[i]-'0');
        st.insert(h.get());
    }
    for (int i = 0; i <= n-k+1; i++){
        if (k <= 21 && (i>>k)) { cout << no; return; }
        hsh c(k);
        for (int j = 21; j >= 0; j--){
            c.pop(); c.ad((i>>j)&1);
        }
        if (st.find(c.get()) == st.end()){
            cout << yes;
            for (int j = k-1; j >= 25; j--) cout << '0';
            for (int j = min(24, k-1); j >= 0; j--) cout << ((i>>j)&1);
            cout << '\n';
            return;
        }
    }
}
int main(){
    initHASH();
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t;
    while (t--) solve();
}