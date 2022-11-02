#pragma GCC optimize("O3","unroll-loops")
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define pb push_back
#define pf pop_front
#define popb pop_back
#define popf pop_front
#define mp make_pair
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-8
#define mod 1000000009
#define inf 1000000000000000007ll
#define intinf ((1 << 31) - 1)
#define f first
#define s second

#include <bits/stdc++.h>
using namespace std;

template<typename T1, typename T2>inline void checkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void checkmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1>inline void sort(vector<T1> &arr) { sort(arr.begin(), arr.end()); }
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> graph;

vector<ll> a, k, s;

ll getsum(ll from, ll to) {
    return s[to] - (from > 0 ? s[from - 1] : 0);
}

int main() {
    FAST;
    ll n, q;
    cin >> n >> q;
    a = vector<ll> (n);
    s = vector<ll> (n);
    k = vector<ll> (q);
    for (auto &i : a) cin >> i;
    for (auto &i : k) cin >> i;
    s[0] = a[0];
    for (int i = 1; i < n; ++i) s[i] = s[i - 1] + a[i];
    ll curr = 0, strength = a[0];
    for (ll t = 0; t < q; ++t) {
        if (k[t] < strength) {
            strength -= k[t];
        } else {
            ll l = curr, r = n;
            while (r - l > 1) {
                ll m = r + l >> 1;
                if (strength + getsum(curr + 1, m) > k[t]) r = m;
                else l = m;
            }
            if (r == n) {
                curr = 0, strength = a[0];
            } else {
                k[t] -= strength + getsum(curr + 1, l);
                curr = l + 1;
                strength = a[curr] - k[t];
            }
        }
        cout << n - curr << '\n';
    } 
    return 0;
}