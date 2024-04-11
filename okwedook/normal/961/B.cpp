#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define pb push_back
#define mp make_pair
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-9
#define mod 1000000007
#define inf 1000000000000000007ll

#include <bits/stdc++.h>

using namespace std;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> graph;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), t(n);
    for (auto &i : a) cin >> i;
    for (auto &i : t) cin >> i;
    vector<ll> pref(n);
    ll summ = 0;
    for (int i = 0; i < n; ++i) {
        if (t[i] == 0) summ += a[i];
        pref[i] = summ;
    }
    summ = 0;
    for (int i = 0; i < n; ++i) summ += a[i] * t[i];
    ll ptr = 0, ans = 0, add = 0;
    ll prefsum = 0;
    for (int i = 0; i < n; ++i) {
        while (i - k >= ptr) ++ptr;
        ans = max(ans, summ + pref[i] - pref[ptr] + (1 - t[ptr]) * a[ptr]);
    }
    cout << ans;
    return 0;
}