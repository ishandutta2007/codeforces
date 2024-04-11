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
vector<pll> c;

void solve(ll n, ll x1, ll x2, bool flag) {
    sort(c);
    for (int i = n - 1; i >= 0; --i) {
        if (x2 > c[i].f * (n - i)) continue;
        for (int j = i - 1; j >= 0; --j) {
            if (x1 > c[j].f * (i - j)) continue;
            cout << "Yes\n";
            if (flag) {
                cout << n - i << ' ' << i - j << '\n';
                for (int t = i; t < n; ++t) cout << c[t].s + 1 << ' ';
                cout << '\n';
                for (int t = j; t < i; ++t) cout << c[t].s + 1 << ' ';
                cout << '\n';
            } else {
                cout << i - j << ' ' << n - i << '\n';
                for (int t = j; t < i; ++t) cout << c[t].s + 1 << ' ';
                cout << '\n';
                for (int t = i; t < n; ++t) cout << c[t].s + 1 << ' ';
                cout << '\n';
            }
            exit(0);
        }
        return;
    }
}

int main() {
    FAST;
    ll n, x1, x2;
    cin >> n >> x1 >> x2;
    c = vector<pll>(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i].f;
        c[i].s = i;
    }
    sort(c);
    solve(n, x1, x2, false);
    solve(n, x2, x1, true);
    cout << "No";
    return 0;
}