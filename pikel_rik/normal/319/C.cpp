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

int n, a[N], b[N];
ll dp[N];

using point = pair<ll, ll>;

bool intersect(point l1, point l2, point l3) {
    return (ld)(l1.second - l2.second) * (ld)(l3.first - l1.first) >= (ld)(l1.second - l3.second) * (ld)(l2.first - l1.first);
}

bool intersect(point l1, point l2, int x) {
    return (ld)(l1.second - l2.second) <= (ld)(l2.first - l1.first) * (ld)x;
}

vector<point> lines;

void addline(ll m, ll c) {
    point nw(m, c);
    while (lines.size() > 1 and intersect(lines[lines.size() - 2], lines[lines.size() - 1], nw)) {
        lines.pop_back();
    }
    lines.push_back(nw);
}

ll get(ll x) {
    int lo = 0, hi = lines.size() - 1;

    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        if (intersect(lines[mid - 1], lines[mid], x))
            hi = mid - 1;
        else lo = mid;
    }

    return lines[lo].first * x + lines[lo].second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    addline(a[n - 1], 0);
    for (int i = n - 2; i >= 0; i--) {
        dp[i] = get(b[i]);
        addline(a[i], dp[i]);
    }
    cout << dp[0] << "\n";
    return 0;
}