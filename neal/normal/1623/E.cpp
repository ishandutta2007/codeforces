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


const int LOG = 18;
const int BAD = -2;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, K;
    string C;
    cin >> N >> K >> C;
    vector<array<int, 2>> children(N);

    for (auto &child : children) {
        cin >> child[0] >> child[1];
        child[0]--; child[1]--;
    }

    string current;
    vector<int> locations(N);
    vector<int> parent(N, -1);
    vector<vector<int>> jump(N, vector<int>(LOG, BAD));

    y_combinator([&](auto dfs, int node, int par) -> void {
        if (node < 0)
            return;

        parent[node] = par;

        if (par < 0 || node == children[par][0])
            jump[node][0] = par;

        for (int k = 0; k < LOG - 1; k++)
            jump[node][k + 1] = jump[node][k] < 0 ? BAD : jump[jump[node][k]][k];

        dfs(children[node][0], node);
        locations[current.size()] = node;
        current += C[node];
        dfs(children[node][1], node);
    })(0, -1);

    string next_different(N, 0);
    char last_different = 0;

    for (int i = N - 1; i >= 0; i--) {
        if (i < N - 1 && current[i] != current[i + 1])
            last_different = current[i + 1];

        next_different[i] = last_different;
    }

    vector<bool> duplicated(N, false);

    auto get_count_up = [&](int node) -> int {
        if (duplicated[node])
            return 0;

        int x = node, count = 0;

        for (int k = LOG - 1; k >= 0; k--)
            if (jump[x][k] >= 0 && !duplicated[jump[x][k]]) {
                x = jump[x][k];
                count += 1 << k;
            }

        if (jump[x][0] == BAD && !duplicated[parent[x]])
            return 0;

        return count + 1;
    };

    auto mark = [&](int node, int up) -> void {
        while (up-- > 0) {
            assert(!duplicated[node]);
            duplicated[node] = true;
            node = parent[node];
        }
    };

    for (int i = 0; i < N; i++)
        if (current[i] < next_different[i]) {
            int node = locations[i];
            int up = get_count_up(node);

            if (up == 0 || up > K)
                continue;

            dbg(node + 1, up);
            mark(node, up);
            K -= up;
        }

    string ans;

    y_combinator([&](auto dfs, int node) -> void {
        if (node < 0)
            return;

        dfs(children[node][0]);
        ans += C[node];

        if (duplicated[node])
            ans += C[node];

        dfs(children[node][1]);
    })(0);

    cout << ans << '\n';
}