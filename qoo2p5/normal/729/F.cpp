#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef double ld;

const int N = 4001;
const int K = 140;

int n;
int a[N];
int p[N];

int get(int l, int r) {
    return p[r] - (l == 0 ? 0 : p[l - 1]);
}

int dp[N][K][90][2];

int calc(int l, int r, int k, bool s) {
    int shift = K / 2 + (l + r) - n;
    if (dp[l][shift][k][s] != -1) {
        return dp[l][shift][k][s];
    }
    if (r - l + 1 < k) {
        return dp[l][shift][k][s] = 0;
    }
    
    if (!s) {
        int best = get(l, l + k - 1) - calc(l + k, r, k, !s);
        if (r - l + 1 >= k + 1) {
            best = max(best, get(l, l + k) - calc(l + k + 1, r, k + 1, !s));
        }
        return dp[l][shift][k][s] = best;
    } else {
        int best = get(r - k + 1, r) - calc(l, r - k, k, !s);
        if (r - l + 1 >= k + 1) {
            best = max(best, get(r - k, r) - calc(l, r - k - 1, k + 1, !s));
        }
        return dp[l][shift][k][s] = best;
    }
}

void run() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            for (int t = 0; t < 90; t++) {
                dp[i][j][t][0] = -1;
                dp[i][j][t][1] = -1;
            }
        }
    }
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    partial_sum(a, a + n, p);
    cout << calc(0, n - 1, 1, 0) << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    run();
    return 0;
}