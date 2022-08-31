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


int solve(vector<int> A, int L, int R) {
    int N = int(A.size());

    if (N % 2 != 0) {
        int ans = 0;

        for (int i = L; i < R; i++)
            ans ^= i;

        for (auto &a : A)
            ans ^= a;

        return ans;
    }

    assert(L % 2 == R % 2);

    if (L % 2 == 0) {
        vector<int> NA;

        for (auto &a : A)
            if (a % 2 == 0)
                NA.push_back(a / 2);

        return 2 * solve(NA, L / 2, R / 2);
    }

    int maximum = *max_element(A.begin(), A.end());
    vector<bool> present(maximum + 2, false);

    for (auto &a : A)
        present[a] = true;

    vector<int> special;

    for (auto &a : A)
        if (!present[a ^ 1])
            special.push_back(a);

    vector<int> options;

    for (auto &s : special)
        options.push_back(s ^ L);

    for (auto &x : options) {
        bool good = true;

        for (auto &a : A)
            if (!(L <= (a ^ x) && (a ^ x) < R))
                good = false;

        if (good)
            return x;
    }

    assert(false);
}

void run_case() {
    int L, R;
    cin >> L >> R;
    R++;
    int N = R - L;
    vector<int> A(N);

    for (auto &a : A)
        cin >> a;

    cout << solve(A, L, R) << '\n';
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