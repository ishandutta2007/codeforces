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


int main() {
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<vector<int>> adj(N);

    auto query = [&](int root) -> vector<int> {
        cout << "? " << root + 1 << endl;
        vector<int> D(N);

        for (auto &d : D)
            cin >> d;

        adj[root] = D;
        return D;
    };

    vector<int> levels = query(0);
    vector<int> halves[2];

    for (int i = 1; i < N; i++)
        halves[levels[i] % 2].push_back(i);

    int which = halves[0].size() > halves[1].size();

    for (int x : halves[which])
        query(x);

    set<array<int, 2>> edges;

    for (int i = 0; i < N; i++)
        if (!adj[i].empty())
            for (int j = 0; j < N; j++)
                if (adj[i][j] == 1) {
                    int x = min(i, j);
                    int y = max(i, j);
                    edges.insert({x, y});
                }

    cout << "!" << endl;

    for (auto &e : edges)
        cout << e[0] + 1 << ' ' << e[1] + 1 << endl;
}