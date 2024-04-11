#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
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
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N;
    int64_t A, R, M;
    cin >> N >> A >> R >> M;
    M = min(M, A + R);
    vector<int64_t> H(N);

    for (auto &h : H)
        cin >> h;

    if (N == 1) {
        cout << 0 << '\n';
        return 0;
    }

    sort(H.begin(), H.end());
    vector<int64_t> prefix_sum(N + 1, 0);

    for (int i = 0; i < N; i++)
        prefix_sum[i + 1] = prefix_sum[i] + H[i];

    int64_t best = INF64;

    for (int i = 1; i < N; i++) {
        int low_count = i, high_count = N - i;
        int64_t low_sum = prefix_sum[i], high_sum = prefix_sum[N] - prefix_sum[i];

        // Can add low_count to need_add and subtract high_count from need_remove up to (high - low) times.

        // Or just do ternary search instead.
        auto &&evaluate = [&](int64_t goal) {
            int64_t need_add = goal * low_count - low_sum;
            int64_t need_remove = high_sum - goal * high_count;
            int64_t smaller = min(need_add, need_remove);
            return smaller * M + (need_add - smaller) * A + (need_remove - smaller) * R;
        };

        int64_t low = H[i - 1], high = H[i];

        while (low < high) {
            int64_t mid = (low + high) / 2;

            if (evaluate(mid) < evaluate(mid + 1))
                high = mid;
            else
                low = mid + 1;
        }

        best = min(best, evaluate(low));
    }

    cout << best << '\n';
}