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


struct result {
    // dp[d] = the xor of SG values at depth d.
    vector<int> dp;
    vector<bool> have;
    int mex = 0;

    result(int value = 0) {
        dp = {value};
        set_have(value);
    }

    int size() const {
        return int(dp.size());
    }

    void set_have(int d) {
        if (d + 2 > int(have.size()))
            have.resize(d + 2, false);

        have[d] = true;
    }
};

vector<vector<int>> adj;
vector<result> results;

void dfs(int node, int parent) {
    result &current = results[node];
    current = result(0);
    bool first = true;

    for (int neigh : adj[node]) {
        assert(neigh != parent);
        dfs(neigh, node);
        result &child = results[neigh];

        if (first) {
            swap(current, child);
            first = false;
        } else {
            int size = min(current.size(), child.size());
            current.dp.erase(current.dp.begin(), current.dp.end() - size);
            child.dp.erase(child.dp.begin(), child.dp.end() - size);

            for (int d = 0; d < size; d++)
                current.dp[d] ^= child.dp[d];
        }

        child = result();
    }

    if (adj[node].size() >= 2) {
        // Rebuild the have table.
        current.have.clear();

        for (int d : current.dp)
            current.set_have(d);

        current.mex = 0;
    }

    while (current.mex < int(current.have.size()) && current.have[current.mex])
        current.mex++;

    current.dp.push_back(current.mex);
    current.set_have(current.dp.back());
}


void run_case() {
    int N;
    cin >> N;
    adj.assign(N, {});
    results.assign(N, {});
    vector<int> P(N);

    for (auto &p : P) {
        cin >> p;
        p--;
    }

    for (int i = 0; i < N; i++)
        if (P[i] >= 0)
            adj[P[i]].push_back(i);

    int SG = 0;

    for (int i = 0; i < N; i++)
        if (P[i] < 0) {
            dfs(i, -1);
            SG ^= results[i].dp.back();
        }

    cout << (SG != 0 ? "YES" : "NO") << '\n';
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