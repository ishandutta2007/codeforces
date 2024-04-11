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


const int INF = int(1e9) + 5;

void run_case() {
    int N, M;
    cin >> N >> M;
    vector<int> memory[3];
    vector<int> A(N), B(N);

    for (auto &a : A)
        cin >> a;

    for (auto &b : B)
        cin >> b;

    for (int i = 0; i < N; i++)
        memory[B[i]].push_back(A[i]);

    sort(memory[1].rbegin(), memory[1].rend());
    sort(memory[2].rbegin(), memory[2].rend());
    int N1 = int(memory[1].size());
    int N2 = int(memory[2].size());
    int64_t help = 0;
    int cost = 0;
    int best = INF;

    for (int x : memory[2]) {
        help += x;
        cost += 2;
    }

    for (int i = 0, j = N2; i <= N1; i++) {
        while (j > 0 && help - memory[2][j - 1] >= M) {
            help -= memory[2][--j];
            cost -= 2;
        }

        if (help >= M)
            best = min(best, cost);

        if (i < N1) {
            help += memory[1][i];
            cost++;
        }
    }

    cout << (best < INF ? best : -1) << '\n';
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