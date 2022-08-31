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


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M;
    cin >> N >> M;
    int same_count = 0, both_count = 0;
    map<pair<int, int>, char> edges;

    for (int i = 0; i < M; i++) {
        char type;
        cin >> type;

        if (type == '+') {
            int u, v;
            char ch;
            cin >> u >> v >> ch;
            edges[{u, v}] = ch;

            if (edges.count({v, u})) {
                both_count++;
                same_count += edges[{v, u}] == ch;
            }
        } else if (type == '-') {
            int u, v;
            cin >> u >> v;
            char ch = edges[{u, v}];
            edges.erase({u, v});

            if (edges.count({v, u})) {
                both_count--;
                same_count -= edges[{v, u}] == ch;
            }
        } else if (type == '?') {
            int k;
            cin >> k;
            cout << ((k % 2 == 0 ? same_count : both_count) > 0 ? "YES" : "NO") << '\n';
        } else {
            assert(false);
        }
    }
}