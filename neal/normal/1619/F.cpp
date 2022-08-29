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
    int N, M, K;
    cin >> N >> M >> K;
    int offset = 0;
    int small = N / M;
    int big = (N + M - 1) / M;
    int ceil_count = N % M;
    int floor_count = M - ceil_count;
    vector<vector<int>> tables;

    for (int round = 0; round < K; round++) {
        int current = offset;

        for (int t = 0; t < ceil_count; t++) {
            vector<int> table;

            for (int i = 0; i < big; i++) {
                table.push_back(current);
                current = (current + 1) % N;
            }

            tables.push_back(table);
        }

        for (int t = 0; t < floor_count; t++) {
            vector<int> table;

            for (int i = 0; i < small; i++) {
                table.push_back(current);
                current = (current + 1) % N;
            }

            tables.push_back(table);
        }

        assert(current == offset);
        offset = (offset + ceil_count * big) % N;
    }

    for (const auto &table : tables) {
        cout << table.size();

        for (int x : table)
            cout << ' ' << x + 1;

        cout << '\n';
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