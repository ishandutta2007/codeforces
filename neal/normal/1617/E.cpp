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

int highest_bit(unsigned x) {
    return x == 0 ? -1 : 31 - __builtin_clz(x);
}


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    auto parent = [&](int x) -> int {
        return (x & (x - 1)) == 0 ? 0 : (1 << (highest_bit(x) + 1)) - x;
    };

    auto dist = [&](int x, int y) -> int {
        int d = 0;

        while (x != y) {
            if (x < y)
                swap(x, y);

            x = parent(x);
            d++;
        }

        return d;
    };

    int N;
    cin >> N;
    vector<int> A(N);

    for (auto &a : A)
        cin >> a;

    auto farthest = [&](int x) -> pair<int, int> {
        int far = -1, y = -1;

        for (int i = 0; i < N; i++) {
            int d = dist(x, A[i]);

            if (d > far) {
                far = d;
                y = i;
            }
        }

        return {far, y};
    };

    int x = farthest(0).second;
    pair<int, int> diameter = farthest(A[x]);
    cout << x + 1 << ' ' << diameter.second + 1 << ' ' << diameter.first << '\n';
}