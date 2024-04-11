#include <bits/stdc++.h>

using namespace std;

const int N = 510;
const long long INF = 1e18;

int n, k;
int a[N], b[N];
long long dp[N][N];

inline int addMod(int u, int v) {
    return (u += v) >= k ? u - k : u;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i <= n; i++) {
        fill(dp[i], dp[i] + k, -INF);
    }
    dp[0][0] = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int aa = 0; aa < k; aa++) {
            if (dp[i][aa] < 0) continue;
            int bb = (sum - aa + k) % k;

            for (int add = 0; add < k; add++) {
                if (add > a[i + 1]) break;
                int left = a[i + 1] - add;
                long long now = left / k;
                now += (add + aa >= k);
                left %= k;
                int inB = b[i + 1];
                if (left > 0) {
                    if (inB < k - left) continue;
                    inB -= (k - left);
                    now++;
                }
                now += inB / k;
                now += ((inB % k) + bb) >= k;
                dp[i + 1][addMod(aa, add)] = max(dp[i + 1][addMod(aa, add)], dp[i][aa] + now);
            }
        }
        sum = addMod(sum, a[i + 1] % k);
        sum = addMod(sum, b[i + 1] % k);
    }
    cout << *max_element(dp[n], dp[n] + k) << endl;
    return 0;
}