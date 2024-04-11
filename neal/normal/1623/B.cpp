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


void run_case() {
    int N;
    cin >> N;
    vector<array<int, 2>> ranges(N);

    for (auto &range : ranges) {
        cin >> range[0] >> range[1];
        range[0]--;
    }

    sort(ranges.begin(), ranges.end(), [](array<int, 2> a, array<int, 2> b) -> bool {
        return a[1] - a[0] > b[1] - b[0];
    });

    for (int i = 0; i < N; i++) {
        vector<int> delta(N + 1, 0);

        for (int j = i + 1; j < N; j++)
            if (ranges[i][0] <= ranges[j][0] && ranges[j][1] <= ranges[i][1]) {
                delta[ranges[j][0]]++;
                delta[ranges[j][1]]--;
            }

        int value = 0;
        int erased = -1;

        for (int x = ranges[i][0]; x < ranges[i][1]; x++) {
            value += delta[x];

            if (value == 0)
                erased = x;
        }

        cout << ranges[i][0] + 1 << ' ' << ranges[i][1] << ' ' << erased + 1 << '\n';
    }

    cout << '\n';
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