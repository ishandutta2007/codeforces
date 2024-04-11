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


int64_t INF64 = int64_t(2e18) + 5;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    array<int, 3> N;
    cin >> N[0] >> N[1] >> N[2];
    array<vector<int64_t>, 3> bags;

    for (int b = 0; b < 3; b++) {
        bags[b].resize(N[b]);

        for (auto &v : bags[b])
            cin >> v;

        sort(bags[b].begin(), bags[b].end());
    }

    int64_t best = -INF64;

    // Negate a whole bag.
    for (int neg = 0; neg < 3; neg++) {
        int64_t sum = 0;

        for (int b = 0; b < 3; b++)
            for (auto &v : bags[b])
                sum += (b == neg ? -1 : +1) * v;

        best = max(best, sum);
    }

    // Negate one number from each of two bags.
    for (int x = 0; x < 3; x++)
        for (int y = x + 1; y < 3; y++) {
            int64_t sum = 0;

            for (int b = 0; b < 3; b++)
                for (auto &v : bags[b])
                    sum += v;

            sum -= 2LL * (bags[x].front() + bags[y].front());
            best = max(best, sum);
        }

    cout << best << '\n';
}