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

    int N;
    cin >> N;
    vector<int> C(N);

    for (auto &c : C) {
        cin >> c;
        c--;
    }

    vector<int> where(N, -1);

    for (int i = 0; i < N; i++)
        where[C[i]] = i;

    vector<array<int, 2>> ops;

    auto add_op = [&](int a, int b) -> void {
        ops.push_back({where[a], where[b]});
        swap(C[where[a]], C[where[b]]);
        C[where[a]] *= -1;
        C[where[b]] *= -1;
        swap(where[a], where[b]);
    };

    auto solve_two_cycles = [&](vector<int> cycle1, vector<int> cycle2) -> void {
        int who1 = cycle1.back(), who2 = cycle2.back();
        add_op(who1, who2);
        cycle1.pop_back();
        cycle2.pop_back();

        while (!cycle1.empty()) {
            add_op(cycle1.back(), who1);
            who1 = cycle1.back();
            cycle1.pop_back();
        }

        while (!cycle2.empty()) {
            add_op(cycle2.back(), who2);
            who2 = cycle2.back();
            cycle2.pop_back();
        }

        add_op(who1, who2);
    };

    auto solve_cycle = [&](vector<int> cycle) -> void {
        if (cycle.size() == 2) {
            int a = cycle[0], b = cycle[1], c = 0;

            while (c == a || c == b)
                c++;

            add_op(b, c);
            add_op(a, b);
            add_op(a, c);
            return;
        }

        if (cycle.size() == 3) {
            int a = cycle[0], b = cycle[1], c = cycle[2];
            add_op(b, c);
            add_op(a, c);
            add_op(b, c);
            add_op(a, c);
            return;
        }

        assert(cycle.size() >= 4);
        add_op(cycle[1], cycle.back());

        while (cycle.size() > 4) {
            add_op(cycle[cycle.size() - 2], cycle.back());
            cycle.pop_back();
        }

        assert(cycle.size() == 4);
        int a = cycle[0], b = cycle[1], c = cycle[2], d = cycle[3];
        add_op(b, c);
        add_op(b, d);
        add_op(a, b);
        add_op(a, c);
    };

    // Find pairs of cycles (size >= 2) and solve them.
    vector<vector<int>> cycles;
    vector<bool> done(N, false);

    for (int i = 0; i < N; i++)
        if (!done[i] && where[i] != i) {
            vector<int> cycle;
            int x = i;

            do {
                done[x] = true;
                cycle.push_back(x);
                x = where[x];
            } while (x != i);

            cycles.push_back(cycle);
        }

    while (cycles.size() >= 2) {
        solve_two_cycles(cycles[cycles.size() - 2], cycles.back());
        cycles.pop_back();
        cycles.pop_back();
    }

    // At most one cycle remaining; solve it. If size = 2, special case this along with any fixed point.
    assert(cycles.size() <= 1);

    if (!cycles.empty())
        solve_cycle(cycles[0]);

    assert(int(ops.size()) <= N + 1);
    cout << ops.size() << '\n';

    for (auto &op : ops)
        cout << op[0] + 1 << ' ' << op[1] + 1 << '\n';
}