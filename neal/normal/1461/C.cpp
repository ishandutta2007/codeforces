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


void run_case() {
    int N, M;
    cin >> N >> M;
    vector<int> P(N);

    for (auto &p : P) {
        cin >> p;
        p--;
    }

    int need = N;

    while (need > 0 && P[need - 1] == need - 1)
        need--;

    double fail = need > 0 ? 1 : 0;

    for (int i = 0; i < M; i++) {
        int r;
        double p;
        cin >> r >> p;

        if (r >= need)
            fail *= 1 - p;
    }

    cout << 1 - fail << '\n';
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    cout << setprecision(12);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}