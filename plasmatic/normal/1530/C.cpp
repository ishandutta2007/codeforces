// ./c-pursuit.yml
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

const int MN = 1e5 + 1;
int N, 
    A[MN], B[MN];

void solve() {
    cin >> N;

    int ans = 0, asum = 0, bsum = 0, th = N - N/4, bptr = 0;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto i = 0; i < N; i++) {
        cin >> A[i];
        pq.push(A[i]);
        asum += A[i];
    }
    for (auto i = 0; i < N; i++)
        cin >> B[i];
    sort(B, B+N, greater<int>());

    while (SZ(pq) > th) {
        asum -= pq.top();
        pq.pop();
    }
    while (bptr < N && bptr < th) {
        bsum += B[bptr];
        bptr++;
    }

    while (asum < bsum) {
        ans++;
        th = (N+ans) - (N+ans)/4;

        // update sums
        pq.push(100);
        asum += 100;
        while (SZ(pq) > th) {
            asum -= pq.top();
            pq.pop();
        }
        while (bptr < N && bptr < th) {
            bsum += B[bptr];
            bptr++;
        }

        // cout<<"N+ans="<<(N+ans)<<", "; cout<<"th="<<(th)<<", "; cout<<"asum="<<(asum)<<", "; cout<<"bsum="<<(bsum)<<", "; cout << endl; // db N+ans,th,asum,bsum
    }

    cout << (ans) << '\n';
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