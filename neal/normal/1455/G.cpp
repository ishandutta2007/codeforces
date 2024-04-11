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


const int64_t INF64 = int64_t(2e18) + 5;

struct DP_DS {
    map<int, int64_t> dp;
    set<pair<int64_t, int>> values;
    int64_t offset = 0;

    void add_all(int64_t delta) {
        offset += delta;
    }

    bool contains(int x) const {
        return dp.count(x);
    }

    int64_t get(int x) const {
        return !contains(x) ? INF64 : dp.at(x) + offset;
    }

    int64_t pop(int x) {
        if (!contains(x))
            return INF64;

        int64_t dp_value = dp[x];
        dp.erase(x);
        values.erase({dp_value, x});
        return dp_value + offset;
    }

    void add_option(int x, int64_t cost) {
        if (contains(x))
            cost = min(cost, pop(x));

        cost -= offset;
        dp[x] = cost;
        values.emplace(cost, x);
    }

    int64_t get_min() const {
        return values.begin()->first + offset;
    }
};

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, BAD;
    cin >> N >> BAD;
    vector<DP_DS> dp_stack(1);
    dp_stack[0].add_option(0, 0);

    for (int i = 0; i < N; i++) {
        string instruction;
        cin >> instruction;

        if (instruction == "set") {
            int y, v;
            cin >> y >> v;

            if (y == BAD) {
                dp_stack.back().add_all(v);
            } else {
                int64_t minimum = dp_stack.back().get_min();
                dp_stack.back().add_all(v);
                dp_stack.back().add_option(y, minimum);
            }
        } else if (instruction == "if") {
            int y;
            cin >> y;
            int64_t cost = dp_stack.back().pop(y);
            dp_stack.emplace_back();
            dp_stack.back().add_option(y, cost);
        } else if (instruction == "end") {
            DP_DS &back = dp_stack.back();
            DP_DS &second = dp_stack[dp_stack.size() - 2];

            if (back.dp.size() > second.dp.size())
                swap(back, second);

            for (auto &pr : back.dp)
                second.add_option(pr.first, back.get(pr.first));

            dp_stack.pop_back();
        } else {
            assert(false);
        }
    }

    assert(dp_stack.size() == 1);
    cout << dp_stack[0].get_min() << '\n';
}