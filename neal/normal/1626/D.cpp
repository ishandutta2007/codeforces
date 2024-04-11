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

int highest_bit(unsigned x) {
    return x == 0 ? -1 : 31 - __builtin_clz(x);
}

int round_up_power_two(int n) {
    int bit = highest_bit(n);
    bit += bit < 0 || 1 << bit < n;
    return 1 << bit;
}


const int INF = int(1e9) + 5;

void run_case() {
    int N;
    cin >> N;
    int B = highest_bit(N) + 1;
    vector<int> freq(N, 0);

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        a--;
        freq[a]++;
    }

    vector<int> prefix_sum(N + 1, 0);

    for (int i = 0; i < N; i++)
        prefix_sum[i + 1] = prefix_sum[i] + freq[i];

    assert(prefix_sum[N] == N);
    vector<int> last_sum(N + (1 << B) + 1, -1);

    for (int i = 0; i <= N; i++)
        last_sum[prefix_sum[i]] = i;

    for (int s = 1; s <= N + (1 << B); s++)
        last_sum[s] = max(last_sum[s], last_sum[s - 1]);

    int best = INF;

    for (int x = 0; x <= B; x++)
        for (int y = 0; y <= B; y++) {
            int first = last_sum[1 << x];
            int second = last_sum[prefix_sum[first] + (1 << y)];
            best = min(best, (1 << x) + (1 << y) + round_up_power_two(N - prefix_sum[second]));
        }

    cout << best - N << '\n';
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