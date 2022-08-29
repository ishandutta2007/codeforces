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

int64_t ceil_div(int64_t a, int64_t b) {
    return a / b + ((a ^ b) > 0 && a % b != 0);
}


const int INF = int(1e9) + 5;
const int DENOM = 1e5;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M;
    cin >> N >> M;
    vector<int> fastest(M + 1, INF);
    vector<int> ans(M + 1, INF);
    fastest[0] = ans[0] = 0;

    for (int i = 0; i < N; i++) {
        int t, y;
        int64_t x;
        cin >> t >> x >> y;

        if (t == 1) {
            x = ceil_div(x, DENOM);

            for (int j = 0; j + x <= M; j++)
                if (fastest[j] + 1 <= y)
                    fastest[j + x] = min(fastest[j + x], fastest[j] + 1);
        } else {
            for (int j = 0; j <= M; j++) {
                int64_t to = ceil_div(j * x, DENOM);

                if (fastest[j] + 1 <= y && to <= M)
                    fastest[to] = min(fastest[to], fastest[j] + 1);
            }
        }

        for (int j = 0; j <= M; j++)
            if (fastest[j] < INF) {
                ans[j] = min(ans[j], i + 1);
                fastest[j] = 0;
            }
    }

    for (int j = 1; j <= M; j++)
        cout << (ans[j] < INF ? ans[j] : -1) << (j < M ? ' ' : '\n');
}