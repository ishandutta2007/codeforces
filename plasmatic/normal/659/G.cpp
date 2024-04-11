// ./g-fence-divercity.yml
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
template <typename T, typename U> void maxa(T &a, U b) { a = max(a, b); }
template <typename T, typename U> void mina(T &a, U b) { a = min(a, b); }
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const ll MOD = 1e9 + 7;
ll madd(ll a, ll b, ll mod = MOD) { return (a + b) % mod; }
ll msub(ll a, ll b, ll mod = MOD) { return (a - b + mod) % mod; }
ll mmul(ll a, ll b, ll mod = MOD) { return (a * b) % mod; }
ll fpow(ll x, ll y, ll mod = MOD) {
    if (!y) return 1LL;
    return mmul(fpow(mmul(x, x, mod), y >> 1, mod), (y & 1) ? x : 1LL, mod);
}
ll mdiv(ll x, ll y, ll mod = MOD) { return mmul(x, fpow(y, mod - 2, mod), mod); }

const int MN = 1e6 + 10;
int N;
ll H[MN], cntAtRes[MN], dp[MN][2]; // 0->At or equal height of next, 1->Above height of next

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N);
    for (auto i = 0; i < N; i++) {
        cin >> (H[i]);
        H[i]--;
    }

    cntAtRes[0] = dp[0][0] = min(H[1], H[0]);
    dp[0][1] = H[0] - dp[0][0];
    // cout<<"dp[0][0]="<<(dp[0][0])<<", "; cout<<"dp[0][1]="<<(dp[0][1])<<", "; cout << endl; // db dp[0][0],dp[0][1]

    for (auto i = 1; i < N; i++) {
        ll cntAt = min(H[i], H[i + 1]), cntAbove = H[i] - cntAt;
        cntAtRes[i] = cntAt;

        dp[i][0] = madd(mmul(dp[i - 1][0], min(cntAt, H[i - 1])), cntAt);
        dp[i][1] = cntAbove;
        if (cntAt < cntAtRes[i - 1])
            dp[i][1] = madd(dp[i][1], mmul(cntAtRes[i - 1] - cntAt, dp[i - 1][0]));

        // cout<<"i="<<(i)<<", "; cout<<"dp[i][0]="<<(dp[i][0])<<", "; cout<<"dp[i][1]="<<(dp[i][1])<<", "; cout<<"cntAt="<<(cntAt)<<", "; cout<<"cntAbove="<<(cntAbove)<<", "; cout << endl; // db i,dp[i][0],dp[i][1],cntAt,cntAbove
    }

    ll ans = 0;
    for (auto i = 0; i < N; i++)
        for (auto j = 0; j < 2; j++)
            ans = madd(ans, dp[i][j]);
    cout << (ans) << '\n';

    return 0;
}