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

vector<ll> l, e;
ll n, m, cl, ce, v;

ll solve(ll x1, ll y1, ll x2, ll y2) {
    ll ans = inf;
    ll left = -1, right = ce; 
    while (right - left > 1) {
        ll m = (right + left) / 2;
        if (e[m] > x1) right = m;
        else left = m;
    }
    if (left >= 0) checkmin(ans, abs(x1 - e[left]) + abs(x2 - e[left]) + (abs(y1 - y2) + v - 1) / v);
    if (right < ce) checkmin(ans, abs(x1 - e[right]) + abs(x2 - e[right]) + (abs(y1 - y2) + v - 1) / v);

    left = -1, right = cl; 
    while (right - left > 1) {
        ll m = (right + left) / 2;
        if (l[m] > x1) right = m;
        else left = m;
    }
    if (left >= 0) checkmin(ans, abs(x1 - l[left]) + abs(x2 - l[left]) + abs(y1 - y2));
    if (right < cl) checkmin(ans, abs(x1 - l[right]) + abs(x2 - l[right]) + abs(y1 - y2));

    return ans;
}

int main() {
    FAST;
    cin >> n >> m >> cl >> ce >> v;
    l = vector<ll>(cl);
    e = vector<ll>(ce);
    for (auto &i : l) cin >> i;
    for (auto &i : e) cin >> i;
    ll q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        swap(x1, y1);
        swap(x2, y2);
        if (y1 == y2) {
            cout << abs(x1 - x2) << '\n';
            continue;
        }
        ll ans = solve(x1, y1, x2, y2);
        cout << ans << '\n';
    }
    return 0;
}