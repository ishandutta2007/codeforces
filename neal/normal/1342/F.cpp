#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template<typename T1, typename T2>
bool minimize(T1 &a, const T2 &b) {
    if (b < a) {
        a = b;
        return true;
    }

    return false;
}


const int INF = 1e9 + 5;
const int N_MAX = 15;

int N;
vector<int> A;
vector<int> mask_sum;

int dp[N_MAX + 1][1 << N_MAX];
int8_t source[N_MAX + 1][1 << N_MAX];
int previous[N_MAX][N_MAX + 1][1 << N_MAX];

void run_case() {
    cin >> N;
    A.resize(N);

    for (auto &a : A)
        cin >> a;

    mask_sum.assign(1 << N, 0);

    for (int mask = 1; mask < 1 << N; mask++)
        mask_sum[mask] = mask_sum[mask & (mask - 1)] + A[__builtin_ctz(mask)];

    for (int k = 0; k < N; k++)
        for (int have = 0; have <= N; have++)
            for (int mask = 0; mask < 1 << N; mask++) {
                dp[have][mask] = INF;
                previous[k][have][mask] = -1;
            }

    int best = 0, best_k = -1;

    for (int k = 0; k < N; k++) {
        for (int have = k; have >= 1; have--)
            for (int k_mask = 0; k_mask < 1 << N; k_mask++) {
                if ((k_mask >> k & 1) == 0)
                    continue;

                int remain = (1 << N) - 1 - k_mask;

                for (int other = remain; other != 0; other = (other - 1) & remain) {
                    int overall_mask = k_mask | other;

                    if (dp[have][other] < mask_sum[k_mask] && minimize(dp[have + 1][overall_mask], mask_sum[k_mask])) {
                        previous[k][have + 1][overall_mask] = (source[have][other] << N) | other;
                        source[have + 1][overall_mask] = k;
                    }
                }
            }

        for (int k_mask = 0; k_mask < 1 << N; k_mask++)
            if ((k_mask >> k & 1) && minimize(dp[1][k_mask], mask_sum[k_mask])) {
                previous[k][1][k_mask] = 0;
                source[1][k_mask] = k;
            }

        for (int have = best + 1; have <= N; have++)
            if (dp[have][(1 << N) - 1] < INF) {
                best = have;
                best_k = k;
            }
    }

    assert(best_k >= 0);
    cout << N - best << '\n';
    int best_mask = (1 << N) - 1;
    vector<int> masks(N, 0);

    while (best > 0) {
        int encoded = previous[best_k][best][best_mask];
        assert(encoded >= 0);
        int prev_k = encoded >> N;
        int prev_mask = encoded & ((1 << N) - 1);
        assert(prev_k < best_k || prev_mask == 0);
        assert((best_mask & prev_mask) == prev_mask);
        dbg(best, best_k, best_mask, prev_k, prev_mask);
        masks[best_k] = best_mask ^ prev_mask;
        best_k = prev_k;
        best_mask = prev_mask;
        best--;
    }

    dbg(masks);
    vector<bool> exists(N, true);

    auto &&get_new_index = [&](int index) {
        int count = 0;

        for (int i = 0; i < index; i++)
            count += exists[i];

        return count;
    };

    for (int k = 0; k < N; k++)
        for (int bit = 0; bit < N; bit++)
            if (bit != k && (masks[k] >> bit & 1)) {
                // bit -> k
                assert(exists[bit]);
                cout << get_new_index(bit) + 1 << ' ' << get_new_index(k) + 1 << '\n';
                exists[bit] = false;
            }
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}