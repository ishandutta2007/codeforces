// ./c-poman-numbers.yml
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

/*
Problem is actually setting the coefficients of a bunch of powers of 2 to +1 and -1 and summing them together to make T.
Observation: We must split at every index i (1 <= i < N) once
- Each split at index i flips the signs of a_{1..i}
- Thus, a_N is always +1 and a_{N-1} is always -1 since those are always flipped once and no times respectively.

Observation: Any sequence of coefficients (a) can be made where a_N=1 and a_{N-1}=-1 (everything else can be anything)
Proof: Use a greedy algorithm of assigning signs by looping from N-2..1
- If at any index i, the value of a_i is not what you want, flip the prefix 1..i
- As it's always possible to flip the prefix 1..i to make a_i what you want with this algorithm, we have proven a_{1..N-2} can be whatever you desire

Problem is now:
Given a bunch of powers of 2, check if it's possible to assign positive and negative signs to them so they can be summed to a value K=T-2^pos(S[N-1])+2^pos(S[N-2]).
Also note that we can assume K is positive as if it was negative, we just solve for -K and flip the signs of the numbers afterwards (this removes some cases).

We can reframe the problem to make it simpler further: instead of assigning them + and - signs, we instead assume all signs are negative initially, and instead think of
making a sign of any number 2^k positive as 'selecting' a number 2^(k+1).  This means we don't have to 'select' all numbers.

Now, we can just use a simply greedy algorithm looping from highest power of 2 to lowest as this is simply the coin change problem where all denominations are multiples of each other.
*/

int N;
ll T;
string s;

ll get(char c) { return 1LL << (c - 'a'); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N) >> (T) >> (s);
    T = abs(T - get(s[N-1]) + get(s[N-2]));

    vector<ll> denom;
    for (auto i = 0; i < N-2; i++) {
        T += get(s[i]);
        denom.pb(2*get(s[i]));
    }
    sort(all(denom), greater<ll>());
    for (auto x : denom) if (x <= T) T -= x;
    cout << (T ? "No" : "Yes") << '\n';
}