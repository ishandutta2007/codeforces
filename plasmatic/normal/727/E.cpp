// ./e-games-on-a-cd.yml
#include "bits/stdc++.h"
using namespace std;

// Defines
#define fs first
#define sn second
#define pb push_back
#define eb emplace_back
#define mpr make_pair
#define mtp make_tuple
#define all(x) (x).begin(), (x).end()
// Basic type definitions
using ll = long long; using ull = unsigned long long; using ld = long double;
using pii = pair<int, int>; using pll = pair<long long, long long>;
// PBDS order statistic tree
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 
template <typename T, class comp = less<T>> using os_tree = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V, class comp = less<K>> using treemap = tree<K, V, comp, rb_tree_tag, tree_order_statistics_node_update>;
// HashSet
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };
template <typename T, class Hash> using hashset = gp_hash_table<T, null_type, Hash>;
template <typename K, typename V, class Hash> using hashmap = gp_hash_table<K, V, Hash>;
// More utilities
int SZ(string &v) { return v.length(); }
template <typename C> int SZ(C &v) { return v.size(); }
template <typename C> void UNIQUE(vector<C> &v) { sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin()); }
template <typename T, typename U> void maxa(T &a, U b) { a = max(a, b); }
template <typename T, typename U> void mina(T &a, U b) { a = min(a, b); }
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

// Hashing stuff
const ll MODS[2] = {1000000007, 1000000009}, BASE[2] = {131, 191};
ll madd(ll a, ll b, ll mod) { return (a + b) % mod; }
ll msub(ll a, ll b, ll mod) { return (a - b + mod) % mod; }
ll mmul(ll a, ll b, ll mod) { return (a * b) % mod; }
ll fpow(ll x, ll y, ll mod) {
    if (!y) return 1LL;
    return mmul(fpow(mmul(x, x, mod), y >> 1, mod), (y & 1) ? x : 1LL, mod);
}
ll mdiv(ll x, ll y, ll mod) { return mmul(x, fpow(y, mod - 2, mod), mod); }

ll comb(ll lo, ll hi) { return (hi << 32) | lo; }
ll glo(ll x) { return x & ((1LL << 32) - 1); }
ll ghi(ll x) { return x >> 32; }
ll append1(ll hsh, int val, int i) { return madd(mmul(hsh, BASE[i], MODS[i]), val, MODS[i]); }
ll append(ll hsh, int val) { return comb(append1(glo(hsh), val, 0), append1(ghi(hsh), val, 1)); } 
vector<ll> pows[2];
void init_pow(int N) {
    for (auto i = 0; i < 2; i++) {
        pows[i].resize(N + 1);
        pows[i][0] = 1LL;
        for (auto j = 1; j <= N; j++)
            pows[i][j] = mmul(pows[i][j - 1], BASE[i], MODS[i]);
    }
}
ll ghsh1(ll hr, ll hl, int sz, int i) {
    return msub(hr, mmul(pows[i][sz], hl, MODS[i]), MODS[i]);
}
ll ghsh(ll *hs, int l, int r) {
    int sz = r - l + 1;
    return comb(ghsh1(glo(hs[r]), glo(hs[l - 1]), sz, 0), ghsh1(ghi(hs[r]), ghi(hs[l - 1]), sz, 1));
}
ll concat1(ll hsh, ll hsh2, int sz, int i) { return madd(mmul(hsh, pows[i][sz], MODS[i]), hsh2, MODS[i]); }
ll concat(ll hsh, ll hsh2, int sz) { return comb(concat1(glo(hsh), glo(hsh2), sz, 0), concat1(ghi(hsh), ghi(hsh2), sz, 1)); }

const int MN = 2e6 + 1;
int N, K, G;
string s;
ll hsh[MN];
unordered_map<ll, int> ids;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N) >> (K) >> (s) >> (G);
    init_pow(2*N*K);
    s += s;
    for (auto i = 1; i <= 2*N*K; i++)
        hsh[i] = append(hsh[i-1], s[i-1]);
    for (auto i = 0; i < G; i++) {
        string tmp;
        cin >> tmp;
        ll chsh = 0;
        for (auto c : tmp)
            chsh = append(chsh, c);
        ids[chsh] = i+1;
        // cout<<"i="<<(i)<<", "; cout<<"chsh="<<(chsh)<<", "; cout << endl; // db i,chsh
    }

    for (auto i = 0; i < K; i++) {
        unordered_map<ll, int> cnt;
        bool skip = false;
        for (auto j = 0, idx = i+1; j < N; j++, idx += K) {
            ll chsh = ghsh(hsh, idx, idx+K-1);
            // cout<<"i="<<(i)<<", "; cout<<"j="<<(j)<<", "; cout<<"chsh="<<(chsh)<<", "; cout << endl; // db i,j,chsh
            if (cnt.count(chsh)) {
                skip = true;
                break;
            }
            cnt[chsh] = j;
        }
        if (skip) continue;
        bool good = true;
        for (auto &p : cnt) {
            if (!ids.count(p.fs)) {
                good = false;
                break;
            }
        }
        if (good) {
            cout << ("YES") << '\n';
            int ans[N];
            for (auto &p : cnt)
                ans[p.sn] = ids[p.fs];
            for (auto i = 0; i < N; i++)
                cout << ans[i] << ' ';
            cout << '\n';
            return 0;
        }
    }

    cout << ("NO") << '\n';

    return 0;
}