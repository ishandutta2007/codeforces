// ./e-lexicographically-small-enough.yml
#include <bits/stdc++.h>
#define DEBUG 0
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
#if __cplusplus == 201703L // CPP17 only things
template <typename T> using opt_ref = optional<reference_wrapper<T>>; // for some templates
#endif
using ll = long long; using ull = unsigned long long; using ld = long double;
using pii = pair<int, int>; using pll = pair<long long, long long>;
#ifdef __GNUG__
// PBDS order statistic tree
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T, class comp = less<T>> using os_tree = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V, class comp = less<K>> using treemap = tree<K, V, comp, rb_tree_tag, tree_order_statistics_node_update>;
// HashSet
#include <ext/pb_ds/assoc_container.hpp>
template <typename T, class Hash> using hashset = gp_hash_table<T, null_type, Hash>;
template <typename K, typename V, class Hash> using hashmap = gp_hash_table<K, V, Hash>;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };
#endif
// More utilities
int SZ(string &v) { return v.length(); }
template <typename C> int SZ(C &v) { return v.size(); }
template <typename C> void UNIQUE(vector<C> &v) { sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin()); }
template <typename T, typename U> void maxa(T &a, U b) { a = max(a, b); }
template <typename T, typename U> void mina(T &a, U b) { a = min(a, b); }
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

// Template is 1-indexed (by default).  Can be made 0-indexed by modifying CompZInd
// Example: update = point increment, range sum
// In the function applyUpdate, updates are applied from `v` to `to`
struct CompZInd {
    using Data = int;
    const Data vdef = 0;
    void applyUpdate(Data &to, Data &v) { to += v; }
    int transformInd(int idx, int N) { return idx+1; } //0-=indexed
};
template <typename CompZInd> struct BIT {
    using Data = typename CompZInd::Data; CompZInd C;
    int N; vector<Data> bit;
    void init(int n0) {
        N = n0;
        bit.assign(N + 1, C.vdef);
    }
    void update(int x, Data v) {
        x = C.transformInd(x, N);
        for (; x <= N; x += x & -x)
            C.applyUpdate(bit[x], v);
    }
    Data query(int x) {
        x = C.transformInd(x, N);
        Data res = C.vdef;
        for (; x; x -= x & -x)
            C.applyUpdate(res, bit[x]);
        return res;
    }
};

const int MN = 1e5 + 1;
int N;
string s, t;
vector<int> lets[26];
BIT<CompZInd> bit;

int ulet(char c) { return c - 'a'; }

void solve() {
    cin >> N >> s >> t;

    vector<int> fre(26), tk(26);
    for (auto i = 0; i < N; i++) {
        lets[ulet(s[i])].pb(i);
        fre[ulet(s[i])]++;
    }

    ll ans = LLINF, curcost = 0;
    vector<int> curInd(26);
    bit.init(N);

    auto change = [&] (int let, int curlen, int mul) {
        if (mul == -1) curInd[let]--;

        int pos = lets[let][curInd[let]];
        curcost += mul * (pos - curlen + (bit.query(N-1) - bit.query(pos)));
        bit.update(pos, mul);

        if (mul == 1) curInd[let]++;
    };

    for (auto i = 0; i < N; i++) { // make s[0..i-1] equal, s[i] < t[i]
        if (DEBUG) { cout<<"i="<<(i)<<", "; cout << endl; } //__RAW_DEBUG_LINE__:db i
        int tgt = ulet(t[i]);
        for (auto j = 0; j < tgt; j++) {
            if (DEBUG) { cout<<"tgt="<<(tgt)<<", "; cout<<"j="<<(j)<<", "; cout<<"curInd[j]="<<(curInd[j])<<", "; cout<<"SZ(lets[j])="<<(SZ(lets[j]))<<", "; cout << endl; } //__RAW_DEBUG_LINE__:db tgt,j,curInd[j],SZ(lets[j])
            if (curInd[j] < SZ(lets[j])) {
                change(j, i, 1);
                if (DEBUG) { cout<<"i="<<(i)<<", "; cout<<"j="<<(j)<<", "; cout<<"curcost="<<(curcost)<<", "; cout << endl; } //__RAW_DEBUG_LINE__:db i,j,curcost
                if (DEBUG) { cout<<"(char)(j+'a')="<<((char)(j+'a'))<<", "; cout << endl; } //__RAW_DEBUG_LINE__:db (char)(j+'a')
                mina(ans, curcost);
                change(j, i, -1);
            }
        }

        // add new
        tk[tgt]++;
        if (tk[tgt] > fre[tgt]) { // we cannot make s[0..i-1] equal
            break;
        }

        change(tgt, i, 1);
        // curcost += lets[tgt][curInd[tgt]];
        // curInd[tgt]++;
    }

    if (ans == LLINF)
        cout << (-1) << '\n';
    else
        cout << (ans) << '\n';

    // clear
    for (auto i = 0; i < 26; i++) {
        lets[i].clear();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        // Input
        
        solve();

        // Reset
    }
}