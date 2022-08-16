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
const int N = 2e5 + 5;

int n, m, k, a[N], b[N];
ll x, y;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> x >> k >> y;

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    int j = 0;
    vector<int> pos = {0};

    for (int i = 0; i < n && j < m; i++) {
        if (a[i] == b[j]) {
            j++;
            pos.push_back(i + 1);
        }
    }

    if (j != m) {
        cout << "-1\n";
        return 0;
    }

    pos.push_back(n + 1);

    for (int i = 1; i < pos.size(); i++) {
        int mx = *max_element(a + pos[i - 1], a + pos[i] - 1);
        if (mx > a[pos[i - 1] - 1] and mx > a[pos[i] - 1] and pos[i] - pos[i - 1] - 1 < k) {
            cout << "-1\n";
            return 0;
        }
    }

    ll cost = 0;
    for (int i = 1; i < pos.size(); i++) {
        int len = pos[i] - pos[i - 1] - 1, mx = *max_element(a + pos[i - 1], a + pos[i] - 1);
        if (mx > a[pos[i - 1] - 1] and mx > a[pos[i] - 1]) {
            cost += x;
            len -= k;
            cost += min((len / k) * x + (len % k) * y, len * y);
        }
        else cost += min((len / k) * x + (len % k) * y, len * y);
    }
    cout << cost << "\n";
    return 0;
}