#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> x, y;
        for (int i = 1; i <= 2 * n; i++) {
            int xx, yy;
            cin >> xx >> yy;
            if (xx == 0) y.push_back(abs(yy));
            else x.push_back(abs(xx));
        }
        assert(x.size() == n);
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        double res = 0;
        for (int i = 0; i < n; i++) {
            res += sqrt(1ll * x[i] * x[i] + 1ll * y[i] * y[i]);
        }
        cout << fixed << setprecision(10) << res << '\n';
    }
    return 0;
}