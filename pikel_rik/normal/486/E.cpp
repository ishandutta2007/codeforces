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

int n, a[N], dp[N], visited[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> tail(n);
    int length = 1;

    tail[0] = a[0];
    dp[0] = 1;

    for (int i = 1; i < n; i++) {
        int idx = lower_bound(tail.begin(), tail.begin() + length, a[i]) - tail.begin();
        dp[i] = idx + 1;
        if (idx == length)
            tail[length++] = a[i];
        else tail[idx] = a[i];
    }

    vector<int> arr(length + 1), ans(n);

    for (int i = n - 1; i >= 0; i--) {
        if (dp[i] < length and arr[dp[i] + 1] <= a[i])
            ans[i] = 1;
        else {
            if (visited[dp[i]]) {
                ans[i] = 2;
                visited[dp[i]] = 2;
                arr[dp[i]] = max(arr[dp[i]], a[i]);
            }
            else {
                ans[i] = 3;
                visited[dp[i]] = 1;
                arr[dp[i]] = a[i];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (ans[i] < 3 or visited[dp[i]] == 1)
            cout << ans[i];
        else cout << 2;
    }
    cout << "\n";
    return 0;
}