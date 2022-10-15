// ./d-cats-transport.yml
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

ostream& operator<<(ostream& out, const pll o) {
    out << "(fs=" << o.fs << ", sn=" << o.sn << ")";
    return out;
}

/*
 * dp[j] + (i-j)*wtime[i] - (psum[i] - psum[j])
 *
 * b=dp[j]+psum[j]
 * m=
 */

const int MN = 1e5 + 1, MP = 101;
int N, M, P;
ll pos[MN], wtime[MN], psum[MN], dp[MP][MN];

ll cost(int k, int j, int i) {
    return dp[k - 1][j] + ll(i - j) * wtime[i] - (psum[i] - psum[j]);
}

void solve(int k, int l, int r, int dl, int dr) {
    if (l > r) return;
    int besti = -1, mid = (l + r) / 2;
    for (int i = dl; i <= min(dr, r); i++) {
        ll alt = cost(k, i, mid);
        if (alt < dp[k][mid]) {
            dp[k][mid] = alt;
            besti = i;
        }
    }
    // cout<<"k="<<(k)<<", "; cout<<"l="<<(l)<<", "; cout<<"r="<<(r)<<", "; cout<<"mid="<<(mid)<<", "; cout<<"dl="<<(dl)<<", "; cout<<"dr="<<(dr)<<", "; cout<<"besti="<<(besti)<<", "; cout<<"dp[k][mid]="<<(dp[k][mid])<<", "; cout << endl; // db k,l,r,mid,dl,dr,besti,dp[k][mid]
    solve(k, l, mid - 1, dl, besti);
    solve(k, mid + 1, r, besti, dr);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N) >> (M) >> (P);
    for (auto i = 2; i <= N; i++) {
        ll d;
        cin >> d;
        pos[i] = pos[i - 1] + d;
    }
    for (auto i = 1; i <= M; i++) {
        ll h, t;
        cin >> h >> t;
        wtime[i] = t - pos[h];
    }
    sort(wtime + 1, wtime + M + 1);
    for (auto i = 1; i <= M; i++)
        psum[i] = psum[i - 1] + wtime[i];

    // cout<<"wtime=["; for(int __i=0; __i<((M+1)); __i++)cout<<wtime[__i]<<", "; cout<<"], ";cout << endl; // db A:(M+1):wtime
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for (auto i = 1; i <= P; i++) {
        solve(i, 1, M, 0, M);
        // cout<<"i="<<(i)<<", "; cout<<"dp[i]=["; for(int __i=0; __i<((M+1)); __i++)cout<<dp[i][__i]<<", "; cout<<"], ";cout << endl; // db i,A:(M+1):dp[i]
    }

    ll ans = LLINF;
    for (auto i = 1; i <= P; i++)
        mina(ans, dp[i][M]);
    cout << (ans) << '\n';

    return 0;
}