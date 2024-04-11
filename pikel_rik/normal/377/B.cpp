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

struct item {
    int x, y, i;
    item(): x(), y(), i() {}
};

int n, m, sum, ans[N];
pair<int, int> b[N];
item a[N];

bool f(int x) {
    ll val = 0;
    int ptr = n - 1;

    priority_queue<int, vector<int>, greater<>> pq;
    while (ptr >= 0 and a[ptr].x >= b[m - 1].first) {
        pq.push(a[ptr--].y);
    }

    for (int i = m - x; i >= 0; i = max(i - x, 0)) {
        if (pq.empty())
            return false;

        val += pq.top();
        pq.pop();

        if (i == 0)
            break;

        while (ptr >= 0 and a[ptr].x >= b[i - 1].first) {
            pq.push(a[ptr--].y);
        }
    }

    return val <= sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> sum;
    for (int i = 0; i < m; i++) cin >> b[i].first, b[i].second = i;

    for (int i = 0; i < n; i++) cin >> a[i].x;
    for (int i = 0; i < n; i++) cin >> a[i].y, a[i].i = i;

    sort(b, b + m);
    sort(a, a + n, [&] (item i1, item i2) { return i1.x < i2.x; });

    if (!f(m)) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    int lo = 1, hi = m;

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (f(mid))
            hi = mid;
        else lo = mid + 1;
    }

    int ptr = n - 1, last = m - 1;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    while (ptr >= 0 and a[ptr].x >= b[m - 1].first) {
        pq.emplace(a[ptr].y, a[ptr].i);
        ptr--;
    }

    for (int i = m - lo; i >= 0; i = max(i - lo, 0)) {
        for (int j = i; j <= last; j++) {
            ans[b[j].second] = pq.top().second;
        }
        pq.pop();

        if (i == 0)
            break;

        while (ptr >= 0 and a[ptr].x >= b[i - 1].first) {
            pq.emplace(a[ptr].y, a[ptr].i);
            ptr--;
        }
        last = i - 1;
    }

    for (int i = 0; i < m; i++) cout << ans[i] + 1 << " ";
    cout << "\n";
    return 0;
}