#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 2e5 + 5;

int n, a[N], b[N], pos1[N], pos2[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], pos1[a[i]] = i;
    for (int j = 1; j <= n; j++) cin >> b[j], pos2[b[j]] = j;

    map<int, int> m;
    for (int i = 1; i <= n; i++) {
        m[pos1[i] - pos2[i]]++;
    }

    int best = 0;
    for (int i = 0; i < n; i++) {
        best = max(best, m[i] + m[i - n]);
    }

    cout << best << "\n";
    return 0;
}