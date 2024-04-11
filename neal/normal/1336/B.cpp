#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


const int64_t INF64 = (int64_t) 4e18 + 5;

int N[3];
vector<int64_t> gem[3];

int64_t square(int64_t x) {
    return x * x;
}

int64_t solve_middle() {
    int64_t best = INF64;

    for (auto &x : gem[0]) {
        auto it = lower_bound(gem[1].begin(), gem[1].end(), x);

        if (it == gem[1].end())
            continue;

        auto y = *it;
        it = upper_bound(gem[2].begin(), gem[2].end(), x);

        if (it == gem[2].begin())
            continue;

        it--;
        auto z = *it;
        best = min(best, square(x - y) + square(y - z) + square(z - x));
    }

    return best;
}

void run_case() {
    for (int g = 0; g < 3; g++)
        cin >> N[g];

    for (int g = 0; g < 3; g++) {
        gem[g].resize(N[g]);

        for (auto &x : gem[g])
            cin >> x;

        sort(gem[g].begin(), gem[g].end());
    }

    int64_t best = INF64;

    for (int p = 0; p < 6; p++) {
        best = min(best, solve_middle());

        if (p % 2 == 0)
            swap(gem[1], gem[2]);
        else
            swap(gem[0], gem[2]);
    }

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