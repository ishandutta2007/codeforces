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


const int64_t XY_MAX = int(1e9) + 5;

void run_case() {
    auto get_median = [](array<int64_t, 4> &X) {
        nth_element(X.begin(), X.begin() + 1, X.end());
        return X[1];
    };

    auto evaluate = [&](array<int64_t, 4> CX, array<int64_t, 4> CY, int64_t len) {
        CX[1] -= len; CX[3] -= len;
        CY[2] -= len; CY[3] -= len;
        int64_t X_median = get_median(CX);
        int64_t Y_median = get_median(CY);
        int64_t value = 0;

        for (int i = 0; i < 4; i++)
            value += abs(CX[i] - X_median) + abs(CY[i] - Y_median);

        return value;
    };

    auto get_choices = [](array<int64_t, 2> low, array<int64_t, 2> high) -> array<int64_t, 2> {
        sort(low.begin(), low.end());
        sort(high.begin(), high.end());
        return {high[1] - low[0], high[0] - low[1]};
    };

    array<int64_t, 4> X, Y;

    for (int i = 0; i < 4; i++)
        cin >> X[i] >> Y[i];

    array<int, 4> perm = {0, 1, 2, 3};
    int64_t best = XY_MAX * XY_MAX;

    do {
        array<int64_t, 4> CX, CY;

        for (int i = 0; i < 4; i++) {
            CX[i] = X[perm[i]];
            CY[i] = Y[perm[i]];
        }

        array<int64_t, 2> x_choices = get_choices({CX[0], CX[2]}, {CX[1], CX[3]});
        array<int64_t, 2> y_choices = get_choices({CY[0], CY[1]}, {CY[2], CY[3]});
        array<int64_t, 4> choices = {x_choices[0], x_choices[1], y_choices[0], y_choices[1]};
        int64_t len = max<int64_t>(get_median(choices), 0);
        best = min(best, evaluate(CX, CY, len));
    } while (next_permutation(perm.begin(), perm.end()));

    cout << best << '\n';
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