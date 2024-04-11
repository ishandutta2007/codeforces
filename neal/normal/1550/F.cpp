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


const int INF = int(1e9) + 5;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, Q, S, D;
    cin >> N >> Q >> S >> D;
    S--;
    vector<int> A(N);

    for (auto &a : A)
        cin >> a;

    auto valid = [&](int index) -> bool {
        return 0 <= index && index < N;
    };

    auto closest = [&](int x) -> array<int, 3> {
        int index = int(lower_bound(A.begin(), A.end(), x) - A.begin());
        return {index - 1, index, index + 1};
    };

    auto get_dist = [&](int x, int y) -> int {
        return abs(A[x] - A[y]);
    };

    auto get_k = [&](int x, int y) -> int {
        return abs(get_dist(x, y) - D);
    };

    vector<array<int, 3>> events;

    for (int i = 0; i < N; i++)
        for (int sign = -1; sign <= +1; sign += 2) {
            int goal = A[i] + D * sign;

            for (int index : closest(goal))
                if (valid(index))
                    events.push_back({get_k(i, index), i, index});
        }

    for (int i = 0; i < N - 1; i++) {
        int middle = (A[i] + A[i + 1]) / 2;

        for (int sign = -1; sign <= +1; sign += 2) {
            int goal = middle + D * sign;

            for (int index : closest(goal))
                if (valid(index)) {
                    int k = max(get_k(index, i), get_k(index, i + 1));
                    events.push_back({k, i, i + 1});
                }
        }
    }

    sort(events.begin(), events.end());
    dbg(events);
    vector<vector<int>> list(N);

    for (int i = 0; i < N; i++)
        list[i] = {i};

    vector<int> root(N);
    iota(root.begin(), root.end(), 0);
    vector<int> answer(N, INF);
    answer[S] = 0;

    auto merge = [&](int x, int y, int k) -> void {
        x = root[x];
        y = root[y];

        if (x == y)
            return;

        if (y == S)
            swap(x, y);

        if (x == S) {
            for (int who : list[y])
                answer[who] = k;
        } else if (list[x].size() < list[y].size()) {
            swap(x, y);
        }

        for (int who : list[y])
            root[who] = x;

        list[x].insert(list[x].end(), list[y].begin(), list[y].end());
        list[y].clear();
    };

    for (auto &e : events)
        merge(e[1], e[2], e[0]);

    dbg(answer);

    for (int q = 0; q < Q; q++) {
        int i, k;
        cin >> i >> k;
        i--;
        cout << (k >= answer[i] ? "Yes" : "No") << '\n';
    }
}