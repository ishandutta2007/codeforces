#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const ll INF = 1e16;
const int MAXN = 100;
const int MAXP = 10;
const double eps = 1e-6;

double dp[MAXN + 1][MAXN * MAXP + 1], s[MAXN + 1];

inline double squ(double x) {
    return 1.0 * x * x;
}

double C, T;

inline double get(double t, int j, int k) {
    return 1.0 * dp[j][k] / (1.0 + t * C) + t;
}

struct Data {
    int a, p;
    bool operator <(const Data &other) const {
        return a > other.a;
    }
}arr[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, k, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    s[0] = 1;
    for(i = 1; i <= MAXN; i++) {
        s[i] = s[i - 1] * 0.9;
    }
    int tests;
    cin >> tests;
    while(tests > 0) {
        tests--;
        cin >> n >> C >> T;
        int sum = 0;
        for(i = 1; i <= n; i++) {
            cin >> arr[i].a >> arr[i].p;
            sum += arr[i].p;
        }
        sort(arr + 1, arr + n + 1);
        for(j = 0; j <= n; j++) {
            for(k = 0; k <= sum; k++) {
                dp[j][k] = INF;
            }
        }
        dp[0][0] = 0;
        for(i = 1; i <= n; i++) {
            for(j = i; j >= 1; j--) {
                for(k = sum; k >= 0; k--) {
                    if(k - arr[i].p >= 0) {
                        dp[j][k] = min(dp[j][k], dp[j - 1][k - arr[i].p] + arr[i].a / s[j]);
                    }
                }
            }
        }
        // min(10 * j + dp[j][k] / (1 + C * t) + t)
        int ans = 0;
        for(j = 1; j <= n; j++) {
            for(k = 1; k <= sum; k++) {
                if(dp[j][k] == INF) {
                    continue;
                }
                double l = 0, r = T - 10 * j;
                if(l > r) {
                    continue;
                }
                for(i = 0; i < 50; i++) {
                    double mid = (l + r) * 0.5;
                    if(get(mid, j, k) - get(mid + eps, j, k) > 0) {
                        l = mid;
                    }
                    else {
                        r = mid;
                    }
                }
                double mid = (l + r) * 0.5;
                if(j * 10.0 + get(mid, j, k) - T < 0) {
                    ans = max(ans, k);
                }
            }
        }
        cout << ans << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}