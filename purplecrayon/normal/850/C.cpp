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
const int MAXN = 3e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 17, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e18+10;

int a[MAXN];
map<ll, int> memo;

vector<pair<ll, int>> get_pf_big(ll n){
    vector<pair<ll, int>> r;
    for (ll i = 2; i*i <= n; i++) if (n%i == 0){
        r.emplace_back(i, 0);
        while (n%i == 0) r.back().second++, n /= i;
    }
    if (n>1) r.emplace_back(n, 1);
    return r;
}
int mex(set<int> s) {
    int c=0;
    while (s.count(c)) c++;
    return c;
}
int grundy(ll mask) {
    if (memo.count(mask)) return memo[mask];
    //cerr << mask << endl;
    // (mask & ((1<<(sub-1)))) | (mask >> sub);
    auto trans = [&](int sub) {
        ll n_sub = mask >> sub;
        return n_sub | (mask & ((1ll << (sub - 1)) - 1));
    };
    set<int> s;
    for (int i = 1; trans(i) < mask; i++) {
        //cerr << i << ' ' << mask << ' ' << trans(i) << endl;
        ll nxt = trans(i);
        assert(nxt <= mask);
        s.insert(grundy(nxt));
    }
    //cerr << "ANS: " << mask << ' ' << mex(s) << endl;
    return memo[mask] = mex(s);
} 
void solve(){
    int n; cin >> n;

    map<int, ll> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        auto pf = get_pf_big(a[i]);
        for (auto& it : pf) mp[it.first] |= 1ll << (it.second - 1);
    }
    int ans=0;
    for (auto& it : mp) {
        ans ^= grundy(it.second);
        cerr << it.first << ' ' << it.second << ' ' << grundy(it.second) << endl;
    }
    cout << (ans?"Mojtaba":"Arpa") << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}