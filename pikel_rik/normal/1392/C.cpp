#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n), visited(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        ll ans = 0;

        stack<int> s;
        s.push(0);

        b[0] = -1;
        for (int i = 1; i < n; i++) {
            while (!s.empty() and a[i] >= a[s.top()]) {
                s.pop();
            }
            if (!s.empty())
                b[i] = s.top();
            else b[i] = -1;
            s.push(i);
        }

        for (int i = 0; i < n; i++) {
            if (b[i] == -1 or visited[b[i]]) continue;
            ans += a[b[i]] - a[i];
            visited[b[i]] = 1;
        }

        cout << ans << "\n";
    }
    return 0;
}