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

int ceil_div(int a, int b) {
    return a / b + ((a ^ b) > 0 && a % b != 0);
}


void run_case() {
    int N;
    cin >> N;
    vector<array<int, 2>> ops;

    auto add_op = [&](int x, int y) {
        ops.push_back({x, y});
    };

    int big = N, current = N - 1;

    while (current > 2) {
        int x = current;

        while (ceil_div(big, x) < x)
            x--;

        while (current > x) {
            add_op(current, N);
            current--;
        }

        add_op(N, current);
        big = ceil_div(big, current);
        assert(big >= current);
    }

    assert(current == 2);

    while (big > 1) {
        add_op(N, current);
        big = ceil_div(big, current);
    }

    cout << ops.size() << '\n';

    for (auto &op : ops)
        cout << op[0] << ' ' << op[1] << '\n';

    assert(int(ops.size()) <= N + 5);
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