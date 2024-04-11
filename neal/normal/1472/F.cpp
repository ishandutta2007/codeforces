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


struct cell {
    int r, c;

    int get_parity() const {
        return (r + c) & 1;
    }

    bool operator<(const cell &other) const {
        return c < other.c;
    }
};

void run_case() {
    int N, M;
    cin >> N >> M;
    vector<cell> blocked(M);

    for (int i = 0; i < M; i++) {
        cell &c = blocked[i];
        cin >> c.r >> c.c;
    }

    if (M % 2 != 0) {
        cout << "NO" << '\n';
        return;
    }

    sort(blocked.begin(), blocked.end());

    for (int i = 0; i < M; i += 2) {
        if (i + 2 < M && blocked[i + 1].c == blocked[i + 2].c) {
            cout << "NO" << '\n';
            return;
        }

        if (blocked[i].get_parity() == blocked[i + 1].get_parity()) {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';
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