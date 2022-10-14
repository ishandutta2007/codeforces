#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint INF = 1e13;

lint N, K;
vector<lint> A;
vector<vector<lint>> last, DP;

int main() {
    cin >> N >> K;
    A.resize(N);
    for (int i = 0; i < N; i++) {
        char a; cin >> a;
        A[i] = a - 'a';
    }

    last.assign(N, vector<lint>(26, -1));
    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j <= 25; j++) {
            for (int k = i; k >= 0; k--) {
                if (A[k] == j) {
                    last[i][j] = k;
                    break;
                }
            }
        }
    }

    DP.assign(N + 1, vector<lint>(N + 1, 0));
    for (int i = 0; i < N; i++) DP[i][1] = 1;
    lint ans = 0;
    for (int ln = 2; ln <= N; ln++) { // length
        for (int i = 1; i < N; i++) {
            for (int j = 0; j <= 25; j++) {     
                if (last[i - 1][j] == -1) continue;
                DP[i][ln] += DP[last[i - 1][j]][ln - 1];
                DP[i][ln] = min(DP[i][ln], INF);
            }
        }
    }

    for (int ln = N; ln >= 1; ln--) {
        lint cnt = 0;
        for (int i = 0; i <= 25; i++) {
            if (last[N - 1][i] == -1) continue;
            cnt += DP[last[N - 1][i]][ln];
        }
        if (cnt >= K) {
            ans += K * (N - ln);
            K = 0;
            break;
        } else {
            ans += cnt * (N - ln);
            K -= cnt;
        }
    }

    if (K == 1) {
        ans += N;
        K--;
    }

    if (K > 0) ans = -1;

    cout << ans << "\n";
}