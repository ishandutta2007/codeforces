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


const int BITS = 30;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, Q;
    cin >> N >> Q;
    vector<array<int, 3>> statements(Q);

    for (auto &st : statements) {
        cin >> st[0] >> st[1] >> st[2];
        st[0]--; st[1]--;
    }

    vector<vector<array<int, 2>>> adj(N);

    for (auto &st : statements) {
        adj[st[0]].push_back({st[1], st[2]});
        adj[st[1]].push_back({st[0], st[2]});
    }

    vector<int> ans(N, 0);

    for (int bit = BITS - 1; bit >= 0; bit--) {
        vector<int> A(N, -1);

        auto set_to = y_combinator([&](auto self, int index, int value) -> void {
            assert(value == 0 || value == 1);

            if (A[index] >= 0)
                return;

            A[index] = value;

            if (value == 1)
                return;

            for (auto &pr : adj[index])
                if (pr[1] >> bit & 1)
                    self(pr[0], 1);
        });

        for (auto &st : statements)
            if (st[0] == st[1])
                set_to(st[0], st[2] >> bit & 1);

        for (auto &st : statements)
            if ((st[2] >> bit & 1) == 0) {
                set_to(st[0], 0);
                set_to(st[1], 0);
            }

        for (int i = 0; i < N; i++)
            if (A[i] < 0)
                set_to(i, 0);

        for (int i = 0; i < N; i++)
            ans[i] |= A[i] << bit;
    }

    output_vector(ans);
}