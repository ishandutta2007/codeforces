#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, l;
int a[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> l;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        a[0] = 0;
        a[n + 1] = l;
        double low = 0, high = l;
        double res = 0;
        for (int it = 0; it < 100; it++) {
            double mid = 0.5 * (low + high);
            double t1 = 0;
            for (int i = 1; i <= n + 1; i++) {
                if (a[i] >= mid) {
                    t1 += (mid - a[i - 1]) / i;
                    break;
                } else {
                    t1 += 1.0 * (a[i] - a[i - 1]) / i;
                }
            }
            double t2 = 0;
            for (int i = n; i >= 0; i--) {
                if (a[i] <= mid) {
                    t2 += (1.0 * a[i + 1] - mid) / (n - i + 1);
                    break;
                } else {
                    t2 += 1.0 * (a[i + 1] - a[i]) / (n - i + 1);
                }
            }
            // cout << mid << ' ' << t1 << ' ' << t2 << endl;
            res = min(t1, t2);
            if (t1 > t2) high = mid;
            else low = mid;
        }
        cout << fixed << setprecision(10) << res << '\n';
    }
    return 0;
}