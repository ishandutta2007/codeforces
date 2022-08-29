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


int64_t square(int64_t x) {
    return x * x;
}

void run_case() {
    int64_t N;
    cin >> N;
    int64_t H = N / 2;
    vector<int64_t> P(N + 1, 0);
    vector<int64_t> P_ans(N + 1, 0);
    int64_t cost = 0;
    int64_t previous = N, previous_ans = N;

    auto set_P = [&](int64_t value) -> void {
        cost += square(previous - value);
        P[previous] = value;
        P_ans[previous_ans] = value;
        previous_ans = value;
    };

    for (int64_t i = 2; i <= H; i++)
        set_P(i);

    P_ans[previous_ans] = 1;
    previous = previous_ans = 1;

    for (int64_t i = H + 1; i <= N; i++)
        set_P(i);

    cout << cost << '\n';

    for (int i = 1; i <= N; i++)
        cout << P_ans[i] << (i < N ? ' ' : '\n');

    cout << N - 1 << '\n';

    for (int64_t i = 2; i <= H; i++)
        cout << i << ' ' << N << '\n';

    for (int64_t i = H + 1; i <= N; i++)
        cout << i << ' ' << 1 << '\n';
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