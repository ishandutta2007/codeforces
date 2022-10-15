// ./h-xor-and-distance.yml
#include <bits/stdc++.h>
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

const int MNODE = 12000000;
int NS[MNODE][2];

int _ptr = 0;
int mk() {
    NS[++_ptr][0] = 0;
    NS[_ptr][1] = 0;
    return _ptr;
}

void ins(int &rt, int bit, int v) {
    if (!rt) rt = mk();
    if (bit < 0) return;
    int &nxt = NS[rt][(v >> bit) & 1];
    ins(nxt, bit-1, v);
}
int query(int rt, int bit, int v, bool ismx) {
    if (bit < 0) return 0;
    int cbit = (v >> bit) & 1, ch = cbit ^ ismx, addBit = ismx;
    if (!NS[rt][ch]) {
        ch ^= 1;
        addBit ^= 1;
    }
    return (addBit * (1 << bit)) | query(NS[rt][ch], bit-1, v, ismx);
}
void clear() { _ptr = 0; }

const int MK = 19, MN = (1 << MK) + 1;
int K, N,
    A[MN];

int ans[MK][MN];

void solve(int bit, vector<int> v) {
    clear();
    int rl = 0, rr = 0;
    vector<int> l, r;
    for (auto x : v) {
        // group by bits
        if ((x >> bit) & 1) {
            r.pb(x);

            ins(rr, bit-1, x);
        }
        else {
            l.pb(x);

            ins(rl, bit-1, x);
        }
    }

    if (!l.empty() && !r.empty()) {
        for (auto i = 0; i < (2 << bit); i++) {
            if ((i >> bit) & 1) { // gotta flip
                int cur = (1 << bit) + query(rl, bit-1, i, 0) - query(rr, bit-1, i, 1);
                mina(ans[bit][i], cur);
            }
            else {
                int cur = (1 << bit) + query(rr, bit-1, i, 0) - query(rl, bit-1, i, 1);
                mina(ans[bit][i], cur);
            }
        }
    }

    if (bit > 0) {
        solve(bit-1, l);
        solve(bit-1, r);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    vector<int> v(N);
    for (auto &x : v) cin >> x;

    memset(ans, 0x3f, sizeof ans);
    solve(K-1, v);

    for (auto i = 0; i < (1<<K); i++) {
        int best = INF;
        for (auto j = 0; j < K; j++) {
            int msk = (2 << j) - 1;
            // cout<<"i="<<(i)<<", "; cout<<"j="<<(j)<<", "; cout<<"msk="<<(msk)<<", "; cout<<"ans[j][i&msk]="<<(ans[j][i&msk])<<", "; cout << endl; // db i,j,msk,ans[j][i&msk]
            mina(best, ans[j][i & msk]);
        }

        cout << best << ' ';
    }
    cout << '\n';

    return 0;
}