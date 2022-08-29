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


bool solve(int64_t K, int64_t L, int64_t R, int64_t T, int64_t X, int64_t Y) {
    if (K + Y <= R)
        K += Y;

    if (Y < X) {
        K -= X;

        if (K < L)
            return T <= 0;

        // K - L = how much extra space we have
        // each day we do +Y and then -X; net is a loss of (X - Y)

        return T <= (K - L) / (X - Y) + 1;
    }

    assert(Y >= X);

    // danger zone = [L, L + X - 1]
    // ok: <= R - Y
    // L = 8, X = 5, R = 20, Y = 10
    // danger zone: [8, 12]
    // ok: [8, 10]

    for (int64_t iter = 0; iter <= X; iter++) {
        int64_t take = (K - L) / X;

        if (T <= take)
            return true;

        if (take == 0)
            return false;

        T -= take;
        K -= take * X;
        assert(T > 0);
        assert(K >= L);
        K += Y;

        if (K > R)
            return false;
    }

    return true;
}

int main() {
    int64_t K, L, R, T, X, Y;
    cin >> K >> L >> R >> T >> X >> Y;
    cout << (solve(K, L, R, T, X, Y) ? "Yes" : "No") << '\n';
}