#pragma GCC optimize("O3","unroll-loops")
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20  )
#define pb push_back
#define pf pop_front
#define popb pop_back
#define popf pop_front
#define mp make_pair
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-9
#define mod 1000000009
#define inf 1000000000000000007ll
#define intinf ((1 << 31) - 1)
#define f first
#define s second

#include <bits/stdc++.h>
using namespace std;

template<typename T1, typename T2> inline void checkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2> inline void checkmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1> inline void sort(T1 &arr) { sort(arr.begin(), arr.end()); }
template<typename T1> inline void reverse(T1 &arr) { reverse(arr.begin(), arr.end()); }
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> graph;

int main() {
    FAST;
    ll n, k;
    cin >> n >> k;
    vector<ll> p(n);
    for (auto &i : p) cin >> i;
    vector<ll> start = p;
    vector<ll> minn(257, -1);
    vector<bool> used(257);
    for (int i = 0; i < n; ++i) {
        ll last;
        for (int j = p[i]; j >= 0 && j > p[i] - k && !used[j]; --j) last = j;
        if (minn[p[i]] >= 0) checkmin(last, minn[p[i]]);
        for (int j = last; j < last + k && j < minn.size() && !used[j]; ++j) minn[j] = last;
        used[p[i]] = true;
        used[last] = true;
    }
    for (auto i : start) cout << minn[i] << ' ';
    return 0; 
}