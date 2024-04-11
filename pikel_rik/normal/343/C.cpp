#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e5 + 5;

int n, m;
ll h[N], p[N];
bool visited[N];

bool f(ll x) {
    int ptr = 0;
    for (int i = 0, j = 0; i < m && j < n;) {
        if ((p[i] <= h[j]) == (p[ptr] <= h[j]) and max(abs(p[i] - h[j]), abs(p[ptr] - h[j])) <= x)
            visited[i] = true, i++;
        else if ((p[i] <= h[j]) != (p[ptr] <= h[j]) and abs(p[i] - h[j]) + abs(p[ptr] - h[j]) + min(abs(p[i] - h[j]), abs(p[ptr] - h[j])) <= x)
            visited[i] = true, i++;
        else {
            ptr = i;
            j++;
        }
    }

    bool ok = true;
    for (int i = 0; i < m; i++) {
        ok &= visited[i];
        visited[i] = false;
    }
    return ok;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> h[i];
    for (int i = 0; i < m; ++i) cin >> p[i];

    ll lo = 0, hi = 2e10;

    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (f(mid))
            hi = mid;
        else lo = mid + 1;
    }

    cout << lo << "\n";
    return 0;
}