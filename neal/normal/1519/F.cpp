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


const int INF = int(1e9) + 5;
const int COINS = 4;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);

    for (auto &a : A)
        cin >> a;

    for (auto &b : B)
        cin >> b;

    int a_total = accumulate(A.begin(), A.end(), 0);
    int b_total = accumulate(B.begin(), B.end(), 0);

    if (a_total > b_total) {
        cout << -1 << '\n';
        return 0;
    }

    vector<vector<int>> C(N, vector<int>(M));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> C[i][j];

    vector<int> PC(M + 1, 1);

    for (int i = 0; i < M; i++)
        PC[i + 1] = (COINS + 1) * PC[i];

    auto encode = [&](const vector<int> &remain) -> int {
        assert(int(remain.size()) == M);
        int encoded = 0;

        for (int i = 0; i < M; i++)
            encoded += remain[i] * PC[i];

        return encoded;
    };

    auto get = [&](int encoded, int index) -> int {
        return encoded / PC[index] % (COINS + 1);
    };

    auto reduce = [&](int encoded, int index, int subtract) -> int {
        assert(subtract <= get(encoded, index));
        return encoded - subtract * PC[index];
    };

    int states = PC[M];
    vector<int> dp(states, INF);
    dp[encode(B)] = 0;

    for (int i = 0; i < N; i++) {
        vector<int> ndp(states, INF);

        auto recurse = y_combinator([&](auto self, int encoded, int key, int cost, int still) -> void {
            if (key >= M) {
                if (still == 0)
                    ndp[encoded] = min(ndp[encoded], cost);

                return;
            }

            self(encoded, key + 1, cost, still);
            cost += C[i][key];

            for (int take = 1; take <= min(get(encoded, key), still); take++)
                self(reduce(encoded, key, take), key + 1, cost, still - take);
        });

        for (int encoded = 0; encoded < states; encoded++)
            if (dp[encoded] < INF)
                recurse(encoded, 0, dp[encoded], A[i]);

        dp.swap(ndp);
    }

    cout << *min_element(dp.begin(), dp.end()) << '\n';
}