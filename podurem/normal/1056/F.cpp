#include <bits/stdc++.h>
    #ifdef PoDuReM
        #define err(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
    #else
        #define err(...) 42
    #endif

typedef long long ll;
#define double long double

using namespace std;

#define TASK ""
#define multiTest 1

void solve();
int main() {
    #ifndef PoDuReM 
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (!strcmp(TASK, "input")) {
            assert(freopen("input.txt", "r", stdin)); assert(freopen("output.txt", "w", stdout));
        } else if (strcmp(TASK, "")) {
            assert(freopen(TASK".in", "r", stdin)); assert(freopen(TASK".out", "w", stdout));
        }
    #endif
    int t = 1;
    if (multiTest) {
        cin >> t;
    }
    while (t--) solve();
    return 0;
}

const double inf = 1e18;
const int dd = (int)1e2 + 3;

double dp[10 * dd][dd];

void uin(double &a, double b) {
    if (a > b) {
        a = b;
    }
}

void solve() {
    int n;
    cin >> n;
    double C, T;
    cin >> C >> T;
    vector<int> A(n), P(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i] >> P[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if (A[j] < A[j + 1]) {
                swap(A[j], A[j + 1]);
                swap(P[j], P[j + 1]);
            }
        }
    }

    int sumP = accumulate(P.begin(), P.end(), 0);
    for (int i = 0; i <= sumP; ++i) {
        fill(dp[i], dp[i] + n + 1, inf);
    }
    dp[0][0] = 0;
    vector<double> pw(n + 1);
    pw[0] = 10.0 / 9;
    for (int i = 1; i <= n; ++i) {
        pw[i] = pw[i - 1] * 10 / 9;
    }
    for (int i = 0; i < n; ++i) {
        for (int p = sumP; p >= 0; --p) for (int j = 0; j <= i; ++j) if (dp[p][j] < inf) {
            uin(dp[p + P[i]][j + 1], dp[p][j] + A[i] * pw[j]);
        }
    }
    for (int p = sumP; p >= 0; --p) {
        for (int i = 0; i <= n; ++i) {
            double mn = dp[p][i];
            double TT = T - 10 * i;
            if (mn == inf || TT < 0) continue;
            if (mn <= TT) {
                cout << p << "\n";
                return;
            }
            double D = (1 - C * TT) * (1 - C * TT) - 4 * C * (mn - TT);
            if (D < 0) continue;
            double t = (C * TT - 1 + sqrt(D)) / (2 * C);
            if (t >= 0) {
                cout << p << "\n";
                return;
            }
        }
    }
    assert(0);
}