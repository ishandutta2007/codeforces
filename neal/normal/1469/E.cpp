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
const int LOG = 21;

void run_case() {
    int N, K;
    string S;
    cin >> N >> K >> S;
    assert(int(S.size()) == N);

    for (auto &ch : S)
        ch = char('0' + '1' - ch);

    vector<bool> seen(N + 1, false);
    unsigned value = 0;
    int one_index = 0;

    for (int i = 0; i < N; i++) {
        int start = i - (K - 1);
        value = 2 * value + (S[i] - '0');

        if (K < 32)
            value &= (1U << K) - 1;

        if (start >= 0) {
            one_index = max(one_index, start);

            while (one_index < N && S[one_index] == '0')
                one_index++;

            if (one_index >= i - LOG && value <= unsigned(N))
                seen[value] = true;
        }
    }

    int limit = min(N + 1, K <= LOG ? 1 << K : INF);
    int ans = 0;

    while (ans < limit && seen[ans])
        ans++;

    if (ans >= limit) {
        cout << "NO" << '\n';
        return;
    }

    cout << "YES" << '\n';

    for (int i = K - 1; i >= 0; i--)
        cout << (i > LOG ? 0 : (ans >> i & 1));

    cout << '\n';
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