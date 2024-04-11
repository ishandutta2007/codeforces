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


struct AB {
    int64_t A, B;

    AB() {}

    AB(int64_t _A, int64_t _B) : A(_A), B(_B) {}
};

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N;
    cin >> N;
    vector<int64_t> A(N), B(N);

    for (auto &a : A)
        cin >> a;

    for (auto &b : B)
        cin >> b;

    int64_t total = 0;

    for (int i = 0; i < N; i++)
        total += abs(A[i] - B[i]);

    int64_t best = 0;

    auto solve_best = [&]() -> void {
        vector<AB> A_high, B_high;

        for (int i = 0; i < N; i++)
            if (A[i] > B[i])
                A_high.emplace_back(A[i], B[i]);
            else
                B_high.emplace_back(A[i], B[i]);

        sort(A_high.begin(), A_high.end(), [](const AB &x, const AB &y) {
            return x.B < y.B;
        });

        sort(B_high.begin(), B_high.end(), [](const AB &x, const AB &y) {
            return x.A < y.A;
        });

        int bh = 0;
        int64_t maximum = 0;

        for (auto &a_high : A_high) {
            while (bh < int(B_high.size()) && B_high[bh].A <= a_high.B)
                maximum = max(maximum, B_high[bh++].B);

            best = max(best, min(maximum, a_high.A) - a_high.B);
        }
    };

    solve_best();
    A.swap(B);
    solve_best();

    cout << total - 2 * best << '\n';
}