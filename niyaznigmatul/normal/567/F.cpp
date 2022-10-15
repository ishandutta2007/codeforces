#include <bits/stdc++.h>

using namespace std;

int n, k;
int const N = 1234;

long long dp[N], ndp[N];

int v[N], u[N];
string op[N];

bool ins(int x, int left, int right) {
    return left <= x && x <= right;
}

bool check(int nleft, int nright, int left, int right) {
    for (int i = 0; i < k; i++) {
        if (!ins(v[i], nleft, nright) || !ins(u[i], nleft, nright)) continue;
        if (!ins(v[i], left, right) && !ins(u[i], left, right)) {
            if (op[i] == "<" || op[i] == ">") return false;
        } else if (!ins(v[i], left, right)) {
            if (op[i] == ">" || op[i] == ">=" || op[i] == "=") return false;
        } else if (!ins(u[i], left, right)) {
            if (op[i] == "<" || op[i] == "<=" || op[i] == "=") return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> v[i] >> op[i] >> u[i];
        --v[i];
        --u[i];
    }
    n *= 2;
    for (int i = 0; i + 1 < n; i++) {
        if (check(i, i + 1, n + 1, 0))
            dp[i] = 1;
    }
    for (int f = 1; 2 * f < n; f++) {
        for (int i = 0; i < n; i++) ndp[i] = 0;
        for (int i = 0; i + 2 * f <= n; i++) {
            long long val = dp[i];
            if (val == 0) continue;
            for (int left = 2; left >= 0; left--) {
                int right = 2 - left;
                if (i - left >= 0 && i + 2 * f + right <= n) {
                    if (check(i - left, i + 2 * f + right - 1, i, i + 2 * f - 1)) {
                        ndp[i - left] += val;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) dp[i] = ndp[i];
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) ans += dp[i];
    cout << ans << endl;
}