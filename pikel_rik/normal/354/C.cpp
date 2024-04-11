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
const int N = 3e5 + 5;
const int M = 1e6 + 5;

int n, k, a[N];
int num[M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];

    k = min(k, *min_element(a, a + n) - 1);

    for (int i = 0; i < n; i++) {
        num[a[i] + 1]--;
        num[max(1, a[i] - k)]++;
    }

    for (int i = 1; i < M; i++) {
        num[i] += num[i-1];
    }

    for (int i = 1; i < M; i++) {
        for (int j = 2 * i; j < M; j += i) {
            num[i] += num[j];
        }
    }

    int best = k + 1;
    for (int i = k + 2; i < M; i++) {
        if (num[i] == n)
            best = i;
    }

    cout << best << "\n";
    return 0;
}