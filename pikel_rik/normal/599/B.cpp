#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e5 + 5;

int n, m, f[N], b[N], cnt1[N], cnt2[N], pos[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> f[i], pos[f[i]] = i;
    for (int i = 0; i < m; i++) cin >> b[i];

    for (int i = 0; i < n; i++)
        cnt1[f[i]]++;

    for (int i = 0; i < m; i++)
        cnt2[b[i]]++;

    for (int i = 1; i <= n; i++) {
        if (cnt2[i] and !cnt1[i]) {
            cout << "Impossible\n";
            return 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (cnt1[i] > 1 and cnt2[i] > 0) {
            cout << "Ambiguity\n";
            return 0;
        }
    }

    cout << "Possible\n";
    for (int i = 0; i < m; i++) {
        cout << pos[b[i]] + 1 << " ";
    }
    return 0;
}