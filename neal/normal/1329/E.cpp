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


const int64_t INF64 = (int64_t) 2e18 + 5;

int64_t ceil_div(int64_t a, int64_t b) {
    return (a + b - 1) / b;
}

int64_t N, M, K;
vector<int64_t> A;

int64_t minimum_cuts_to_stay_below(int64_t R) {
    int64_t sum = 0;

    for (int64_t &a : A)
        sum += (a - 1) / R;

    return sum;
}

int64_t maximum_cuts_to_stay_above(int64_t L) {
    int64_t sum = 0;

    for (int64_t &a : A) {
        if (a < L)
            return -INF64;

        sum += a / L - 1;
    }

    return sum;
}

void run_case() {
    cin >> N >> M >> K;
    A.resize(M + 1);
    int64_t previous = 0;

    for (int i = 0; i < M; i++) {
        int64_t p;
        cin >> p;
        A[i] = p - previous;
        previous = p;
    }

    A[M++] = N - previous;

    int64_t low = 1, high = N;

    while (low < high) {
        int64_t mid = (low + high) / 2;

        if (minimum_cuts_to_stay_below(mid) <= K)
            high = mid;
        else
            low = mid + 1;
    }

    int64_t R = low;

    low = 1; high = N;

    while (low < high) {
        int64_t mid = (low + high + 1) / 2;

        if (maximum_cuts_to_stay_above(mid) >= K)
            low = mid;
        else
            high = mid - 1;
    }

    int64_t L = low;
    dbg(L, R);
    assert(L <= R);
    vector<pair<int64_t, int64_t>> options;

    for (int64_t &a : A) {
        int64_t L_cuts = a / L - 1;
        int64_t my_R = ceil_div(a, L_cuts + 1);

        int64_t R_cuts = (a - 1) / R;
        int64_t my_L = a / (R_cuts + 1);

        my_L = min(my_L, L);
        my_R = max(my_R, R);
        options.emplace_back(my_L, my_R);
    }

    sort(options.begin(), options.end());
    int64_t best = INF64, max_R = R;

    for (pair<int64_t, int64_t> &option : options) {
        best = min(best, max_R - option.first);
        max_R = max(max_R, option.second);
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