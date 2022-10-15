// ./d-love-hate.yml
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

#define popcount __builtin_popcountll

const int MN = 2e5+1, MP = 60, TRIALS = 30, MSUB = 1<<15;
int N, M, P;
ll like[MN];
mt19937 mt(26022021);

bool cmp(const ll a, const ll b) {
    return popcount(a) < popcount(b);
}

int dp[MSUB];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> P;
    for (auto i = 0; i < N; i++) {
        string s; cin >> s;
        reverse(all(s));
        like[i] = bitset<MP>(s).to_ullong();
    }

    uniform_int_distribution<int> dis(0, N-1);
    ll ans = 0;
    for (auto TR = 0; TR < TRIALS; TR++) {
        int idx = dis(mt), n = popcount(like[idx]), msub = 1<<n;

        vector<int> ind;
        for (auto i = 0; i < M; i++)
            if ((like[idx] >> i) & 1)
                ind.pb(i);

        fill(dp, dp+msub, 0);
        // cout<<"TR="<<(TR)<<", "; cout<<"idx="<<(idx)<<", "; cout<<"n="<<(n)<<", "; cout<<"msub="<<(msub)<<", "; cout << endl; // db TR,idx,n,msub
        for (auto i = 0; i < N; i++) {
            ll fmsk = like[idx] & like[i];
            int msk = 0;
            for (auto j = 0; j < n; j++)
                if ((fmsk >> ind[j]) & 1)
                    msk |= 1 << j;
            dp[msk]++;
            // cout<<"i="<<(i)<<", "; cout<<"like[idx]="<<(bitset<5>(like[idx]))<<", "; cout<<"like[i]="<<(bitset<5>(like[i]))<<", "; cout << endl; // db i,b:5:like[idx],b:5:like[i]
        }

        for (auto i = msub-1; i >= 0; i--) {
            if (dp[i] >= (N+1) / 2) {
                ll cur = 0;
                for (auto j = 0; j < n; j++)
                    if ((i >> j) & 1)
                        cur |= 1LL << ind[j];
                ans = max(ans, cur, cmp);
            }

            for (auto j = (i - 1) & i; j; j = (j - 1) & i) {
                if ((popcount(i) - popcount(j)) & 1)
                    dp[j] += dp[i];
                else
                    dp[j] -= dp[i];
            }
        }
    }

    string aans = bitset<MP>(ans).to_string();
    reverse(all(aans));
    cout << aans.substr(0, M) << '\n';

    return 0;
}