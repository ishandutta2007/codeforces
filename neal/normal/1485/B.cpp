#include <algorithm>
#include <array>
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


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, Q;
    int64_t K;
    cin >> N >> Q >> K;
    vector<int64_t> A(N);

    for (auto &a : A)
        cin >> a;

    vector<int64_t> choices(N, 0);

    for (int i = 1; i < N - 1; i++)
        choices[i] = A[i + 1] - A[i - 1] - 2;

    vector<int64_t> choices_sum(N + 1, 0);

    for (int i = 0; i < N; i++)
        choices_sum[i + 1] = choices_sum[i] + choices[i];

    for (int q = 0; q < Q; q++) {
        int L, R;
        cin >> L >> R;
        L--;

        if (R - L == 1) {
            cout << K - 1 << '\n';
            continue;
        }

        int64_t answer = choices_sum[R - 1] - choices_sum[L + 1];
        answer += max<int64_t>(A[L + 1] - 2, 0);
        answer += max<int64_t>(K - 1 - A[R - 2], 0);
        cout << answer << '\n';
    }
}