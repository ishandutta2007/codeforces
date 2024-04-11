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


const int INF = int(1e9) + 5;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N;
    cin >> N;
    vector<int> A(N);

    for (auto &a : A)
        cin >> a;

    auto evaluate = [](int me, int neighbor, int neighbor_finish) -> int {
        if (me < min(neighbor, neighbor_finish))
            return INF;

        if (neighbor < neighbor_finish) {
            if (me < neighbor_finish)
                return neighbor_finish;
            else
                return neighbor + 1;
        } else {
            if (me < neighbor)
                return neighbor + 1;
            else
                return neighbor_finish;
        }
    };

    array<vector<int>, 2> min_finish;
    min_finish.fill(vector<int>(N, INF));
    min_finish[0][0] = -1;

    for (int i = 1; i < N; i++)
        min_finish[0][i] = evaluate(A[i], A[i - 1], min_finish[0][i - 1]);

    min_finish[1][N - 1] = -1;

    for (int i = N - 2; i >= 0; i--)
        min_finish[1][i] = evaluate(A[i], A[i + 1], min_finish[1][i + 1]);

    int max_index = int(max_element(A.begin(), A.end()) - A.begin());
    int min_inc, max_dec;
    int total = 0;

    auto add_element = [&](int previous, int current, int limit) -> void {
        int nmin_inc = INF, nmax_dec = -INF;

        if (current >= limit) {
            if (current > min_inc)
                nmax_dec = max(nmax_dec, previous);

            if (current > previous)
                nmax_dec = max(nmax_dec, max_dec);
        }

        if (current < previous)
            nmin_inc = min(nmin_inc, min_inc);

        if (current < max_dec)
            nmin_inc = min(nmin_inc, previous);

        min_inc = nmin_inc;
        max_dec = nmax_dec;
    };

    min_inc = -INF;
    max_dec = INF;

    for (int i = max_index + 1; i < N; i++) {
        add_element(A[i - 1], A[i], min_finish[0][max_index]);
        total += max_dec >= min_finish[1][i];
    }

    min_inc = -INF;
    max_dec = INF;

    for (int i = max_index - 1; i >= 0; i--) {
        add_element(A[i + 1], A[i], min_finish[1][max_index]);
        total += max_dec >= min_finish[0][i];
    }

    cout << total << '\n';
}