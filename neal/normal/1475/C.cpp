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
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> A(K), B(K);
    vector<int> a_cnt(N + 1, 0), b_cnt(M + 1, 0);

    for (auto &a : A) {
        cin >> a;
        a--;
        a_cnt[a]++;
    }

    for (auto &b : B) {
        cin >> b;
        b--;
        b_cnt[b]++;
    }

    int64_t answer = K * (K - 1LL);

    for (int i = 0; i < K; i++)
        answer -= a_cnt[A[i]] + b_cnt[B[i]] - 2;

    assert(answer % 2 == 0);
    cout << answer / 2 << '\n';
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