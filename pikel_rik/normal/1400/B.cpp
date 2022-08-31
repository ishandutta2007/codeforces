#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

int solve(int p, int f, int cnts, int cntw, int s, int w, int i) {
    int ans = i;
    p -= w * i;

    ans += min(p / s, cnts);
    cnts -= min(p / s, cnts);

    ans += min(f / s, cnts);
    f -= s * min(f / s, cnts);

    ans += min(f / w, cntw - i);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int p, f, cnts, cntw, s, w;
        cin >> p >> f >> cnts >> cntw >> s >> w;

        if (s > w) {
            swap(s, w);
            swap(cnts, cntw);
        }

        int ans = 0;

        for (int i = 0; i <= cntw; i++) {
            if (p < w * (ll)i)
                break;
            ans = max(ans, solve(p, f, cnts, cntw, s, w, i));
        }

        cout << ans << "\n";
    }
    return 0;
}