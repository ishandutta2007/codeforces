#include <algorithm>
#include <array>
#include <bitset>
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

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


const int AB_MAX = 1005;
const int INF = int(1e9) + 5;

vector<int> cost(2 * AB_MAX + 1, INF);

void preprocess() {
    cost[1] = 0;

    for (int a = 1; a <= AB_MAX; a++)
        for (int x = 1; x <= AB_MAX; x++) {
            int b = a + a / x;
            cost[b] = min(cost[b], cost[a] + 1);
        }
}

void run_case() {
    int N, K;
    cin >> N >> K;
    vector<int> B(N), C(N);

    for (auto &b : B)
        cin >> b;

    for (auto &c : C)
        cin >> c;

    vector<int> dp(K + 1, -INF);
    dp[0] = 0;
    int current = 0;

    for (int i = 0; i < N; i++) {
        int b = B[i], c = C[i];
        int b_cost = cost[b];

        for (int x = min(current, K - b_cost); x >= 0; x--)
            dp[x + b_cost] = max(dp[x + b_cost], dp[x] + c);

        current = min(current + b_cost, K);
    }

    cout << *max_element(dp.begin(), dp.end()) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    preprocess();

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}