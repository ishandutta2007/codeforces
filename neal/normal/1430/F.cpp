#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


const int64_t INF64 = int64_t(2e18) + 5;

int main() {
    int N;
    int64_t K;
    cin >> N >> K;
    vector<int64_t> L(N), R(N), A(N);
    int64_t total = 0;

    for (int i = 0; i < N; i++) {
        cin >> L[i] >> R[i] >> A[i];
        total += A[i];
    }

    vector<int64_t> dp(N + 1, INF64);
    dp[N] = 0;
    // dp[N - 1] = (R[N - 1] - L[N - 1] + 1) * K >= A[N - 1] ? 0 : INF64;

    for (int i = N - 1; i >= 0; i--) {
        int64_t have = K;

        for (int j = i; j < N; j++) {
            int64_t days = R[j] - L[j] + 1;

            if (have + (days - 1) * K < A[j])
                break;

            bool early = days > 1 && have + (days - 2) * K >= A[j];
            early = early || j == N - 1 || (j < N - 1 && R[j] < L[j + 1]);

            if (have >= A[j]) {
                have -= A[j];
            } else {
                int64_t need = A[j] - have;
                have = (K - need % K) % K;
            }

            if (j == N - 1)
                dp[i] = min(dp[i], dp[N]);

            if (early)
                dp[i] = min(dp[i], dp[j + 1] + have);

            if (early && have == 0)
                have = K;
        }
    }

    if (dp[0] > INF64 / 2) {
        cout << -1 << '\n';
        return 0;
    }

    cout << total + dp[0] << '\n';
}