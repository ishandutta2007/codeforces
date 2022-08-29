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

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N;
    cin >> N;
    vector<int> P(N), A(N);

    for (auto &p : P) {
        cin >> p;
        p--;
    }

    for (auto &a : A) {
        cin >> a;
        a--;
    }

    vector<bool> seen(N, false);

    for (auto &p : P)
        seen[p] = true;

    int missing = N - accumulate(seen.begin(), seen.end(), 0);
    int maximum = *max_element(A.begin(), A.end());
    assert((maximum - (N - 1)) % missing == 0);
    int steps = (maximum - (N - 1)) / missing;
    vector<int> PP = P;
    vector<int> location(N);
    iota(location.begin(), location.end(), 0);
    set<int> remaining(location.begin(), location.end());

    auto apply = [&](vector<int> where, const vector<int> &go) -> vector<int> {
        for (int i = 0; i < N; i++)
            where[i] = go[where[i]];

        return where;
    };

    for (int k = 0; 1 << k <= steps; k++) {
        if (steps >> k & 1)
            location = apply(location, PP);

        PP = apply(PP, PP);
    }

    vector<vector<int>> from(N);

    for (int i = 0; i < N; i++)
        from[location[i]].push_back(i);

    vector<int> answer(N, -1);
    vector<int> at_least(N, -1);

    for (int i = 0; i < N; i++)
        if (!from[i].empty()) {
            int goal = A[i];
            int index = *min_element(from[i].begin(), from[i].end());
            answer[index] = goal;
            remaining.erase(goal);

            for (int x : from[i])
                at_least[x] = goal;
        }

    for (int i = 0; i < N; i++)
        if (answer[i] < 0) {
            answer[i] = *remaining.lower_bound(at_least[i]);
            remaining.erase(answer[i]);
        }

    output_vector(answer, true);
}