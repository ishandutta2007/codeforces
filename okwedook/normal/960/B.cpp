#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define pb push_back
#define mp make_pair
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-8
#define mod 1000000007
#define inf 1000000000000000007ll
#define intinf (1 << 31) - 1
#define f first
#define s second

#include <bits/stdc++.h>

using namespace std;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> graph;

int main() {
    ll n, k1, k2;
    cin >> n >> k1 >> k2;
    vector<ll> a(n), b(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;
    for (int i = 0; i < n; ++i) a[i] = abs(a[i] - b[i]);
    k1 = k1 + k2;
    ll cnt = k1;
    sort(a.begin(), a.end());
    for (int i = 0; i < k1 && a[n - 1] > 0; ++i) {
        --a[n - 1];
        sort(a.begin(), a.end());
        --cnt;
    }
    cnt %= 2;
    ll ptr = 0;
    while (cnt > 0) {
        ++a[ptr];
        if (ptr == n) ptr = 0;
        --cnt;
    }
    ll ans = 0;
    for (auto i : a) ans += i * i;
    cout << ans;
    return 0;
}