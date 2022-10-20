#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const long long INF = 3e18;

int n;
long long a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    set<pair<long long, long long>> s;
    s.insert({a[1] - 1, 0ll});
    for (int i = 2; i <= n; i++) {
        long long maxVal = -INF;
        while (!s.empty()) {
            auto u = *s.rbegin();
            if (u.first < a[i]) break;
            s.erase(u);
            long long newVal = u.first % a[i];
            long long newDelta = u.second + (u.first - newVal) * (i - 1);
            s.insert({newVal, newDelta});
            maxVal = max(maxVal, u.second + (u.first - newVal - a[i]) * (i - 1));
        }
        if (maxVal >= 0) {
            s.insert({a[i] - 1, maxVal});
        }
    }
    long long res = -INF;
    for (auto u : s) {
        res = max(res, u.first * n + u.second);
    }
    cout << res << endl;
    return 0;
}