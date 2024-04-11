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
    string S;
    cin >> N >> M >> S;

    auto value = [](char ch) -> int {
        return ch == '+' ? +1 : -1;
    };

    vector<int> prefix(N + 1, 0);
    vector<int> prefix_max(N + 1, 0), prefix_min(N + 1, 0);

    for (int i = 0; i < N; i++) {
        prefix[i + 1] = prefix[i] + value(S[i]);
        prefix_max[i + 1] = max(prefix_max[i], prefix[i + 1]);
        prefix_min[i + 1] = min(prefix_min[i], prefix[i + 1]);
    }

    vector<int> suffix(N + 1, 0);
    vector<int> suffix_max(N + 1, 0), suffix_min(N + 1, 0);

    for (int i = N - 1; i >= 0; i--) {
        suffix[i] = value(S[i]) + suffix[i + 1];
        suffix_max[i] = max(0, value(S[i]) + suffix_max[i + 1]);
        suffix_min[i] = min(0, value(S[i]) + suffix_min[i + 1]);
    }

    for (int q = 0; q < M; q++) {
        int L, R;
        cin >> L >> R;
        L--;

        int maximum = max(prefix_max[L], prefix[L] + suffix_max[R]);
        int minimum = min(prefix_min[L], prefix[L] + suffix_min[R]);
        cout << maximum - minimum + 1 << '\n';
    }
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