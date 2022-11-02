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

ll n = 14;
vector<ll> arr(14);

ll solve(ll k) {
    if (arr[k] == 0) return 0;
    vector<ll> cop = arr;
    ll st = cop[k];
    cop[k] = 0;
    for (auto &i : cop) i += st / n;
    for (ll i = 1; i <= st % n; ++i)
        cop[(k + i) % n]++;
    ll ans = 0;
    for (auto i : cop)
        if (i % 2 == 0) ans += i;
    return ans;
}

int main() {
    FAST;
    for (auto &i : arr) cin >> i;
    ll ans = 0;
    for (int i = 0; i < n; ++i) checkmax(ans, solve(i));
    cout << ans;
    return 0;
}