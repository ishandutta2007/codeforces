// d-pave-the-parallelepiped.yml
#include "bits/stdc++.h"
using namespace std;

// Defines
#define pb push_back
#define fs first
#define sn second
#define mpr make_pair
#define mtp make_tuple
#define all(x) (x).begin(), (x).end()
// Basic type definitions
using ll = long long; using ull = unsigned long long;
using pii = pair<int, int>; using pll = pair<long, long>;
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
template <typename C> int sz(C &v) { return v.size(); }
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

ostream& operator<<(ostream& out, const pii o) {
    out << "(first=" << o.first << ", second=" << o.second << ")";
    return out;
}

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int MN = 1e5 + 1;
int A[3];
ll cnt[8], fcnt[MN];
vector<tuple<int, int, int>> goodMasks;

ll S2(ll x) { 
    ll res = x < 1 ? 0 : x * (x - 1) / 2; 
    return res + x;
}
ll S3(ll x) {
    ll res = x < 2 ? 0 : x * (x - 1) * (x - 2) / 6; 
    if (x > 0)
        res += x * (x - 1);
    return res + x;
}

void solve() {
    for (auto i = 7; i > 0; i--) {
        ll tgt = 0;
        for (auto j = 0; j < 3; j++)
            if ((i >> j) & 1)
                tgt = gcd(tgt, A[j]);
        cnt[i] = fcnt[tgt];
        for (auto j = i + 1; j < 8; j++)
            if ((j & i) == i) // j contains i
                cnt[i] -= cnt[j];
        // cout << "i=" << (bitset<3>(i)) << ", "; cout << "tgt=" << (tgt) << ", "; cout << "cnt[i]=" << (cnt[i]) << ", "; cout << endl; // db b:3:i,tgt,cnt[i]
    }

    ll ans = 0;
    for (auto msks : goodMasks) {
        int a, b, c;
        tie(a, b, c) = msks;
        if (a == b && b == c)
            ans += S3(cnt[a]);
        else if (a == b)
            ans += S2(cnt[a]) * cnt[c];
        else if (b == c)
            ans += cnt[a] * S2(cnt[b]);
        else
            ans += cnt[a] * cnt[b] * cnt[c];
        // cout << "a=" << (a) << ", "; cout << "b=" << (b) << ", "; cout << "c=" << (c) << ", "; cout << "ans=" << (ans) << ", "; cout << endl; // db a,b,cans
    }
    cout << (ans) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (auto i = 1; i < MN; i++) {
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0)
                fcnt[i] += 1 + (j * j != i);
        }
    }

    for (auto i = 0; i < 8; i++) {
        for (auto j = i; j < 8; j++) {
            for (auto k = j; k < 8; k++) {
                int p[3] = {i, j, k}; sort(p, p + 3);
                bool good = false;
                do {
                    if ((p[0] & 1) && (p[1] & 2) && (p[2] & 4)) {
                        good = true;
                        break;
                    }
                } while(next_permutation(p, p + 3));
                if (good) {
                    // cout << "[good]: "; cout << "i=" << (bitset<3>(i)) << ", "; cout << "j=" << (bitset<3>(j)) << ", "; cout << "k=" << (bitset<3>(k)) << ", "; cout << endl; // db l:good,b:3:i,b:3:j,b:3:k
                    goodMasks.emplace_back(i, j, k);
                }
            }
        }
    }

    int T;
    cin >> T;
    while (T--) {
        for (auto i = 0; i < 3; i++) 
            cin >> (A[i]);
        for (auto i = 0; i < 8; i++)
            cnt[i] = 0;
        solve();
    }

    return 0;
}