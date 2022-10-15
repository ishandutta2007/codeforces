// ./e-fetch-the-treasure.yml
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

// struct tres {
//     ll v; int i; ll pos;
//     bool operator<(const tres &o) const {
//         return v == o.v ? i < o.i : v > o.v;
//     }
// };
// bool posCmp(const tres a, const tres b) {
//     return a.pos > b.pos;
// }

ostream& operator<<(ostream& out, const pair<ll, int> o) {
    out << "(fs=" << o.fs << ", sn=" << o.sn << ")";
    return out;
}

const int MN = 1e5 + 1, MK = 1e4 + 1;
int N, Q, K;
ll H,
   dp[MK], val[MN];

int ptr[MK];
vector<pair<ll, int>> stk[MK];
set<pair<ll, int>> glob;

struct ed {
    int v; ll w;
    bool operator<(const ed &o) const {
        return w > o.w;
    }
};
vector<ll> cost;
void calcdis() {
    priority_queue<ed> pq;
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    pq.push({0, 0});
    while (!pq.empty()) {
        auto c = pq.top(); pq.pop();
        if (c.w > dp[c.v]) continue;
        for (auto x : cost) {
            ll nxt = (c.v + x) % K, alt = c.w + x;
            if (dp[nxt] > alt) {
                dp[nxt] = alt;
                pq.push({(int)nxt, alt});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (H) >> (N) >> (Q) >> (K);
    vector<pair<ll, int>> posorder;
    posorder.eb(-LLINF, 0);
    for (auto i = 1; i <= N; i++) {
        ll p, v;
        cin >> p >> v; p--;

        stk[p % K].eb(p, i);
        val[i] = v;
        posorder.eb(p, i);
    }
    sort(all(posorder));
    for (auto i = 0; i < K; i++) {
        sort(all(stk[i]));
        ptr[i] = SZ(stk[i]) - 1;

        if (i == 0) {
            for (auto &x : stk[0])
                glob.emplace(-val[x.sn], x.sn);
            ptr[0] = -1;
        }
    }

    // init k
    calcdis();

    while (Q--) {
        int T;
        cin >> T;
        // cout<<"T="<<(T)<<", "; cout << "glob=["; for (auto __x:glob)cout<<__x<<", "; cout<<"], "; cout << endl; // db T,I:glob

        if (T == 1) {
            ll x;
            cin >> x;
            cost.pb(x);
            calcdis();

            // vector<ll> tmp(K, LLINF);
            // for (auto i = 0; i < K; i++) {
            //     mina(tmp[i], dp[i]);
            //     mina(tmp[(i + x) % K], dp[i] + x);
            // }
            // copy(all(tmp), dp);

            for (auto i = 0; i < K; i++) {
                while (ptr[i] >= 0 && stk[i][ptr[i]].fs >= dp[i]) {
                    auto &p = stk[i][ptr[i]];
                    glob.emplace(-val[p.sn], p.sn);
                    ptr[i]--;
                }
            }
        }
        else if (T == 2) {
            int a, d;
            cin >> a >> d;
            // a = posorder[a].sn;

            pair<ll, int> item{-val[a], a};
            auto ptr = glob.find(item);
            if (ptr != glob.end()) {
                glob.erase(ptr);
                item.fs += d;
                glob.insert(item);
            }
            val[a] -= d;
        }
        else {
            if (!glob.empty()) {
                cout << (-glob.begin()->fs) << '\n';
                glob.erase(glob.begin());
            }
            else
                cout << (0) << '\n';
        }
    }

    return 0;
}