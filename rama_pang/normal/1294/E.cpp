#include <bits/stdc++.h>
using namespace std;
using lint = long long;

lint N, M;
vector<vector<lint>> A;

lint solve(const vector<lint>& a) { // min cost to become {0, m, 2m, 3m, ...}
    vector<lint> freq(N + N, 0);
    for (lint i = 0; i < N; i++) {
        if (a[i] % M == 0) {
            lint to = a[i] / M;
            if (!(0 <= to && to < N)) {
                continue;
            }
            if (to <= i) {
                freq[i - to]++;
            } else {
                freq[i + N - to]++;
            }
        }
    }

    lint res = N;
    for (lint i = 0; i < N; i++) {
        res = min(res, N - freq[i] + i);
    }

    return res;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    A.assign(N + N, vector<lint>(M + M, 0));
    for (lint i = 0; i < N; i++) {
        for (lint j = 0; j < M; j++) {
            cin >> A[i][j];
            A[i][j]--;
        }
    }

    lint ans = 0;
    for (lint j = 0; j < M; j++) {
        for (lint i = 0; i < N; i++) {
            A[i][j] -= j;
        }
        vector<lint> tmp(N);
        for (lint i = 0; i < N; i++) {
            tmp[i] = A[i][j];
        }
        ans += solve(tmp);
    }

    cout << ans << "\n";
    return 0;
}