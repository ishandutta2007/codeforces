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


const int BITS = 30;

void run_case() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);

    for (auto &a : A)
        cin >> a;

    for (auto &b : B)
        cin >> b;

    vector<int> everything(N);
    iota(everything.begin(), everything.end(), 0);
    vector<array<vector<int>, 2>> groups = {{everything, everything}};

    auto split_group = [&](array<vector<int>, 2> group, int bit) -> vector<array<vector<int>, 2>> {
        int n = int(group[0].size());
        int ones = 0;

        for (int i = 0; i < n; i++) {
            ones += A[group[0][i]] >> bit & 1;
            ones += B[group[1][i]] >> bit & 1;
        }

        if (ones != n)
            return {};

        vector<array<vector<int>, 2>> ngroup(2);

        for (int i = 0; i < n; i++) {
            ngroup[A[group[0][i]] >> bit & 1][0].push_back(group[0][i]);
            ngroup[!(B[group[1][i]] >> bit & 1)][1].push_back(group[1][i]);
        }

        return ngroup;
    };

    int64_t ans = 0;

    for (int bit = BITS - 1; bit >= 0; bit--) {
        bool good = true;

        for (auto &group : groups)
            good = good && !split_group(group, bit).empty();

        if (!good)
            continue;

        vector<array<vector<int>, 2>> ngroups;

        for (auto &group : groups) {
            vector<array<vector<int>, 2>> ngroup = split_group(group, bit);

            for (auto &ng : ngroup)
                if (!ng[0].empty())
                    ngroups.push_back(ng);
        }

        groups.swap(ngroups);
        ans |= 1LL << bit;
    }

    cout << ans << '\n';
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