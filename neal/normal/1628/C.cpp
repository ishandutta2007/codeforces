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


int solve(int N, const vector<vector<int>> &B, bool include_last) {
    int ans = 0, prev_diag = 0;

    for (int sum = 0; sum <= N - 2; sum += 2) {
        int diag = 0;

        for (int i = 0; i <= sum; i += 2)
            diag ^= B[i][sum - i];

        diag ^= prev_diag;
        prev_diag = diag;

        if (sum < N - 2 || include_last)
            ans ^= diag;
    }

    return ans;
}

vector<vector<int>> rotate(int N, const vector<vector<int>> &B) {
    vector<vector<int>> R(N, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            R[i][j] = B[N - 1 - j][i];

    return R;
}

void run_case() {
    int N;
    cin >> N;
    vector<vector<int>> B(N, vector<int>(N));

    for (auto &row : B)
        for (auto &b : row)
            cin >> b;

    int ans = 0;

    for (int rot = 0; rot < 4; rot++) {
        ans ^= solve(N, B, rot < 2);
        B = rotate(N, B);
    }

    cout << ans << '\n';
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