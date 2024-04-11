#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, K;
    cin >> N >> K;
    int MX = 1 << K;
    int max_answer = (MX - 1) / (N - 1);
    vector<int> A(N);
    vector<bool> exists(MX, false);

    for (auto &a : A) {
        cin >> a;
        exists[a] = true;
    }

    sort(A.begin(), A.end());
    vector<int> prefix_count(MX + 1, 0);

    for (int x = 0; x < MX; x++)
        prefix_count[x + 1] = prefix_count[x] + exists[x];

    vector<vector<int>> best_ans(K + 1);

    for (int len = 1; len <= K; len++)
        best_ans[len].assign(1 << len, max_answer);

    auto get_opposite_bit = [](int a, int bit) -> int {
        return (a & 1 << bit) ^ (1 << bit);
    };

    for (int a : A)
        for (int high = K - 1; high >= 0; high--) {
            int len = high + 1;
            int x_prefix = a & 1 << high;
            int bits = high;
            int b = a >> (high + 1) << (high + 1);
            b |= get_opposite_bit(a, high);

            while (bits > 0 && (1 << (bits - 1)) + 1 >= max_answer) {
                bits--;
                x_prefix |= get_opposite_bit(a, bits);
                b |= get_opposite_bit(a, bits);
            }

            y_combinator([&](auto recurse, int bit, int x, int start, int end) -> void {
                if (bit < 0) {
                    assert(end - start == 1);

                    if (prefix_count[end] - prefix_count[start] > 0) {
                        assert((start ^ x) > (a ^ x));
                        best_ans[len][x] = min(best_ans[len][x], (start ^ x) - (a ^ x));
                    }

                    return;
                }

                int mid = (start + end) / 2;

                // next bit 0
                if (prefix_count[mid] - prefix_count[start] > 0)
                    recurse(bit - 1, x, start, mid);
                else
                    recurse(bit - 1, x, mid, end);

                // next bit 1
                if (prefix_count[end] - prefix_count[mid] > 0)
                    recurse(bit - 1, x ^ 1 << bit, mid, end);
                else
                    recurse(bit - 1, x ^ 1 << bit, start, mid);
            })(bits - 1, x_prefix, b, b + (1 << bits));
        }

    for (int len = 1; len < K; len++)
        for (int x = 0; x < 1 << len; x++) {
            best_ans[len + 1][x] = min(best_ans[len + 1][x], best_ans[len][x]);
            best_ans[len + 1][x | 1 << len] = min(best_ans[len + 1][x | 1 << len], best_ans[len][x]);
        }

    output_vector(best_ans[K]);
}