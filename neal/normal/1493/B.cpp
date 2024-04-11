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


const array<int, 10> FLIP = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};

void run_case() {
    int H, M;
    string s;
    cin >> H >> M >> s;

    auto reflect = [&](int h, int m) -> bool {
        int ht = h / 10, ho = h % 10;
        int mt = m / 10, mo = m % 10;

        int nht = FLIP[mo];
        int nho = FLIP[mt];
        int nmt = FLIP[ho];
        int nmo = FLIP[ht];

        if (min({nht, nho, nmt, nmo}) < 0)
            return false;

        return 10 * nht + nho < H && 10 * nmt + nmo < M;
    };

    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3));

    while (true) {
        if (reflect(h, m)) {
            printf("%02d:%02d\n", h, m);
            return;
        }

        m++;

        if (m >= M) {
            m = 0;
            h++;

            if (h >= H)
                h = 0;
        }
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