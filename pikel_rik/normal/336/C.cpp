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
const int N = 1e5 + 1;

unsigned int n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    int best = -1, cnt = 0;
    for (int i = 0; i <= 30; i++) {
        int ans = INT_MAX, c = 0;

        for (int j = 0; j < n; j++) {
            if (a[j] & (1u << i))
                ans &= a[j], c++;
        }

        if ((ans & -ans) == (1u << i))
            best = i, cnt = c;
    }

    cout << cnt << "\n";
    for (int i = 0; i < n; i++) {
        if (a[i] & (1u << best))
            cout << a[i] << " ";
    }
    return 0;
}