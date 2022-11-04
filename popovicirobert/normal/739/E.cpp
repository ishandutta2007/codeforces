#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))
#define Test(x) cout << "Case #" << x << ": ";
 
using namespace std;

struct Data {
    double value;
    int cnt1, cnt2;

    Data() = default;

    Data(double value, int cnt1, int cnt2) : value(value), cnt1(cnt1), cnt2(cnt2) {}
};

Data max(const Data& a, const Data& b) {
    if (a.value == b.value) {
        if (a.cnt2 == b.cnt2) {
            return a.cnt1 < b.cnt1 ? a : b;
        }
        return a.cnt2 < b.cnt2 ? a : b;
    }
    return a.value < b.value ? b : a;
}

 
int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n, a, b;
    cin >> n >> a >> b;

    vector<double> p(n + 1), u(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> u[i];
    }

    vector<Data> dp(n + 1);

    auto Aliens = [&](double lambda1, double lambda2) -> pair<int, int> {
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];
            dp[i] = max(dp[i], Data(dp[i - 1].value + p[i] - lambda1, dp[i - 1].cnt1 + 1, dp[i - 1].cnt2));
            dp[i] = max(dp[i], Data(dp[i - 1].value + u[i] - lambda2, dp[i - 1].cnt1, dp[i - 1].cnt2 + 1));
            dp[i] = max(dp[i], Data(dp[i - 1].value + p[i] + u[i] - p[i] * u[i] - lambda1 - lambda2,
                                    dp[i - 1].cnt1 + 1, dp[i - 1].cnt2 + 1));
        }
        return {dp[n].cnt1, dp[n].cnt2};
    };

    double l1 = 0, r1 = 1e4;
    for (int i = 0; i < 50; i++) {
        double mid1 = (l1 + r1) * 0.5;

        double l2 = 0, r2 = 1e4;
        for (int j = 0; j < 50; j++) {
            double mid2 = (l2 + r2) * 0.5;
            if (Aliens(mid1, mid2).second > b) {
                l2 = mid2;
            } else {
                r2 = mid2;
            }
        }

        if (Aliens(mid1, r2).first > a) {
            l1 = mid1;
        } else {
            r1 = mid1;
        }
    }

    double l2 = 0, r2 = 1e4;
    for (int j = 0; j < 50; j++) {
        double mid2 = (l2 + r2) * 0.5;
        if (Aliens(r1, mid2).second > b) {
            l2 = mid2;
        } else {
            r2 = mid2;
        }
    }

    cout << fixed << setprecision(20) << dp[n].value + 1.0 * a * r1 + 1.0 * b * r2;

    return 0;
    
}