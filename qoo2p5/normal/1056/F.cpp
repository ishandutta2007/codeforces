#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) (1e9 + 1e6 + 123);
const ll LINF = (ll) (1e18 + 1e9 + 123);

bool mini(auto& x, const auto& y) {
    if (y < x) {
        x = y;
        return true;
    }
    return false;
}

bool maxi(auto& x, const auto& y) {
    if (x < y) {
        x = y;
        return true;
    }
    return false;
}

void run();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    run();
    return 0;
}

const double EPS = (double) 1e-9;

const int N = 102;
const int P = N * 10 + 2;

int n;
double c, t;
vector<pair<int, int>> items;
int a[N], p[N];
double pw[N];
double dp[N][N][P];

void solve() {
    pw[0] = 1;
    for (int i = 1; i < N; i++) {
        pw[i] = pw[i - 1] / 0.9;
    }
    cin >> n;
    cin >> c >> t;
    items.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> items[i].first >> items[i].second;
    }
    sort(items.rbegin(), items.rend());
    for (int i = 0; i < n; i++) {
        a[i] = items[i].first;
        p[i] = items[i].second;
    }

    for (int j = 0; j < P; j++) {
        for (int cnt = 0; cnt < N; cnt++) {
            dp[0][cnt][j] = 1e18;
        }
    }
    dp[0][0][0] = 0.0;
    for (int i = 0; i < n; i++) {
        for (int cnt = 0; cnt <= n; cnt++) {
            for (int j = 0; j < P; j++) {
                dp[i + 1][cnt][j] = dp[i][cnt][j];
            }
        }
        for (int cnt = 0; cnt < n; cnt++) {  
            for (int j = 0; j < P; j++) {
                if (j + p[i] >= P || abs(dp[i][cnt][j] - 1e18) < EPS) continue;
                double to = dp[i][cnt][j];
                to += a[i] * pw[cnt + 1];
                int nj = j + p[i];
                mini(dp[i + 1][cnt + 1][nj], to);
            }
        }
    }

    for (int j = P - 1; j > 0; j--) {
        for (int cnt = 0; cnt <= n; cnt++) {
            double q = dp[n][cnt][j];
            if (abs(q - 1e18) < EPS || t - 10 * cnt < 0) {
                continue;
            }
            double tt = t;
            t -= 10 * cnt;
            if (q <= t) {
                cout << j << "\n";
                // cerr << q + 10 * cnt << "\n";
                return;
            }

            // q / (1 + Cx) <= t - x
            double best_x = (t * c - 1) / (2 * c);
            best_x = max(best_x, 0.0);
            best_x = min(best_x, t);
            if (1.0 / (1 + c * best_x) * q <= t - best_x + EPS) {
                cout << j << "\n";
                // cerr << 1.0 / (1 + c * best_x) * q + 10 * cnt + c * best_x << "\n";
                return;
            }
            t = tt;
        }
    }
    cout << "0\n";
}

void run() {
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}