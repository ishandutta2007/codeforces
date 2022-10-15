// ./g-a-serious-referee.yml
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

const int MN = 41, MQ = 11;
int N, Q;
vector<int> ind[MQ];

bool ok = true;
int cur[MN];

void sortInd(vector<int> &ind) {
    int cnt[3]{0};
    for (auto x : ind) cnt[cur[x]+1]++;
    int ptr = 0;
    for (auto i = 0; i < 3; i++)
        while (cnt[i]--)
            cur[ind[ptr++]] = i-1;
}

void bad() {
    cout << ("REJECTED") << '\n';
    exit(0);
}

void rec(int c) {
    if (c == Q) {
        bool seenh = false;
        for (auto i = 0; i < N; i++) {
            if (seenh && cur[i] < 1) bad();
            seenh |= cur[i] > -1;
        }

        return;
    }

    int tmp[MN]; copy(cur, cur+N, tmp);

    sortInd(ind[c]);
    int l = -1, r = 0, idx = 0;
    bool fnd = false;
    for (auto x : ind[c]) {
        if (cur[x] == 0) {
            fnd = true;
            if (l == -1) l = idx;
            r = idx;
            cur[x] = -1;
        }
        idx++;
    }

    rec(c+1);

    if (fnd) {
        for (auto i = r; i >= l; i--) {
            cur[ind[c][i]] = 1;
            rec(c+1);
        }
    }

    copy(tmp, tmp+N, cur);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> Q;
    for (auto i = 0; i < Q; i++) {
        int n; cin >> n;
        ind[i].resize(n);
        for (auto &x : ind[i]) {
            cin >> x;
            x--;
        }
        
        sort(all(ind[i]));
    }

    rec(0);
    cout << ("ACCEPTED") << '\n';

    return 0;
}