#include <bits/stdc++.h>
using namespace std;
using lint = long long;
constexpr int BITS = 18;
constexpr int MAXN = 300005;

int N;
int A[MAXN];
pair<int, int> S[BITS][MAXN]; // (val, index)
int LOG2[MAXN];
lint memo[MAXN];

int getmax(int i, int j) {
    int b = LOG2[j - i + 1];
    return max(S[b][i], S[b][j - (1 << b) + 1]).second;
}

void preproc() {
    memset(memo, -1, sizeof(memo));
    LOG2[1] = 0;
    for (int i = 2; i < MAXN; i++) {
        LOG2[i] = LOG2[i / 2] + 1;
    }
    for (int j = 1; j < BITS; j++) {
        for (int i = 0; i < N; i++) {
            S[j][i] = max(S[j - 1][i], S[j - 1][i + (1 << (j - 1))]);
        }
    }
}

lint dp(int n) {
    if (n >= N - 1) {
        return 0;
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    lint &res = memo[n] = 0;
    int nxt = getmax(n, A[n]);
    res += (N - n - 1);  // there are N - n - 1 routes that has distance incremented
    res += dp(nxt);      // add next DP state
    res -= (A[n] - nxt); // this is counted twice by current DP and next DP twice (since next DP assume that A[n] - nxt, ..., A[n] is unreached - however we can reach it)
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    lint ans = 0;
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        cin >> A[i];
        A[i]--;
        S[0][i].first = A[i];
        S[0][i].second = i;
    }
    S[0][N - 1].first = A[N - 1] = N - 1;
    S[0][N - 1].second = N - 1;

    preproc();

    for (int i = N - 1; i >= 0; i--) {
        ans += dp(i);
    }

    cout << ans << "\n";
    return 0;
}