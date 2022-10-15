// ./d-secret-santa.yml
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

const int MN = 2e5 + 1;
int N,
    A[MN], B[MN];

void solve() {
    cin >> N;
    vector<bool> indeg(N+1);
    for (auto i = 1; i <= N; i++) {
        cin >> A[i];
        indeg[A[i]] = true;
    }
    for (auto i = 1; i <= N; i++)
        B[i] = 0;

    vector<int> unass;
    for (auto i = 1; i <= N; i++)
        if (!indeg[i])
            unass.pb(i);
    sort(all(unass), greater<int>());

    vector<bool> sel(N+1);

    for (auto i = 1; i <= N; i++) {
        if (!indeg[i]) {
            if (!sel[A[i]]) {
                sel[A[i]] = true;
                B[i] = A[i];
            }
            else {
                B[i] = unass.back();
                sel[unass.back()] = true;
                unass.pop_back();
            }
        }
    }
    // cout<<"(B+1)=["; for(int __i=0; __i<(N); __i++)cout<<((B+1))[__i]<<", "; cout<<"], ";cout << endl; // db A:N:(B+1)
    // cout<<"[donephase1]: "; cout << endl; // db l:donephase1

    vector<int> nopea, nopeb;
    for (auto i = 1; i <= N; i++) {
        if (indeg[i]) {
            if (!sel[A[i]]) {
                sel[A[i]] = true;
                B[i] = A[i];
            }
            else 
                nopea.pb(i);
        }
    }
    for (auto i = 1; i <= N; i++) {
        if (!sel[i]) {
            B[nopea.back()] = i;
            nopea.pop_back();
        }
    }

    int ans = 0;
    for (auto i = 1; i <= N; i++) ans += A[i] == B[i];
    cout << (ans) << '\n';
    for (auto i = 1; i <= N; i++) cout << B[i] << " \n"[i == N];
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