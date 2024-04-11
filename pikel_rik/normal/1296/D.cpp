#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 2e5 + 5;

int n, a, b, k, h[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> a >> b >> k;
    for (int i = 0; i < n; i++) cin >> h[i];

    int ans = 0;
    vector<int> v;

    for (int i = 0; i < n; i++) {
        int sum = a + b;
        h[i] %= sum;

        if (h[i] == 0)
            v.push_back((b + a - 1) / a);
        else if (h[i] > 0 and h[i] <= a)
            ans++;
        else {
            v.push_back((h[i] - 1) / a);
        }
    }

    sort(v.begin(), v.end());

    for (int i : v) {
        if (k < i)
            break;
        ans ++;
        k -= i;
    }

    cout << ans << "\n";
    return 0;
}