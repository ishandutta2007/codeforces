#pragma GCC optimize("O3","unroll-loops")
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define mp make_pair
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-9
#define mod 1000000007
#define inf 1000000000000000007ll
#define intinf ((1 << 31) - 1)
#define f first
#define s second

#include <bits/stdc++.h>
using namespace std;

template<typename T1, typename T2> inline void checkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2> inline void checkmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1> inline void sort(T1 &arr) { sort(arr.begin(), arr.end()); }
template<typename T1> inline void shuffle(T1 &arr) { 
    for (int i = -int(arr.size()); i < arr.size(); ++i) {
        int f = ((rand() << 16) + rand()) % arr.size(), s = ((rand() << 16) + rand()) % arr.size();
        swap(arr[f], arr[s]);
    }
}
template<typename T1> inline void reverse(T1 &arr) { reverse(arr.begin(), arr.end()); }
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> graph;

vector<ld> arr;
ll n, k;

bool check(ld c) {
    vector<ld> checkarr = arr;
    for (auto &i : checkarr) i -= c;
    for (int i = 1; i < n; ++i) checkarr[i] += checkarr[i - 1];
    if (checkarr[k - 1] > 0) return true;
    ld mn = 0;
    for (int i = k; i < n; ++i) {
        checkmin(mn, checkarr[i - k]);
        if (checkarr[i] - mn >= 0) return true;
    }
    return false;
}

signed main() {
    FAST;
    cin >> n >> k;
    arr = vector<ld>(n);
    for (auto &i : arr) cin >> i;
    ld l = -1, r = 50000;
    while (r - l > eps) {
        ld m = (r + l) / 2;
        if (check(m)) l = m;
        else r = m;
    }
    FIXED;
    cout << l;
    return 0;
}