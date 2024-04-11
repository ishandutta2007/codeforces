#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    constexpr int N = 1000;
    static long long prefix_sums[N + 1][N + 1];

    while (t--) {
        memset(prefix_sums, 0, sizeof(prefix_sums));

        int n, q;
        cin >> n >> q;

        for (int i = 0, h, w; i < n; i++) {
            cin >> h >> w;
            prefix_sums[h][w] += h * w;
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                prefix_sums[i][j] += prefix_sums[i - 1][j];
                prefix_sums[i][j] += prefix_sums[i][j - 1];
                prefix_sums[i][j] -= prefix_sums[i - 1][j - 1];
            }
        }

        while (q--) {
            int hs, ws, hb, wb;
            cin >> hs >> ws >> hb >> wb;

            hb -= 1, wb -= 1;
            long long answer = prefix_sums[hb][wb];
            answer -= prefix_sums[hs][wb];
            answer -= prefix_sums[hb][ws];
            answer += prefix_sums[hs][ws];
            cout << answer << '\n';
        }
    }
    return 0;
}