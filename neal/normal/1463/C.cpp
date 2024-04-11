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

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


const int64_t INF64 = int64_t(2e18) + 5;

void run_case() {
    int N;
    cin >> N;
    vector<pair<int64_t, int64_t>> path = {{0, 0}};
    vector<int64_t> T(N), X(N);

    for (int i = 0; i < N; i++) {
        cin >> T[i] >> X[i];

        if (T[i] >= path.back().first) {
            int64_t location = path.back().second;

            if (T[i] > path.back().first)
                path.emplace_back(T[i], location);

            path.emplace_back(T[i] + abs(location - X[i]), X[i]);
        }
    }

    auto get_location = [&](int64_t t) -> int64_t {
        auto it = lower_bound(path.begin(), path.end(), make_pair(t, INF64));
        auto prev_it = prev(it);
        return prev_it->second + (it->second - prev_it->second) * (t - prev_it->first) / (it->first - prev_it->first);
    };

    int successful = 0;

    for (int i = 0; i < N; i++) {
        int64_t before = get_location(T[i]);
        int64_t after = i < N - 1 ? get_location(T[i + 1]) : path.back().second;

        if (before > after)
            swap(before, after);

        successful += before <= X[i] && X[i] <= after;
    }

    cout << successful << '\n';
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