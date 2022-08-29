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
    vector<vector<int>> A(N, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];

    vector<int> parent(2 * N - 1, -1);
    vector<int> salary(2 * N - 1, -1);
    vector<int> _who(N);
    iota(_who.begin(), _who.end(), 0);
    int next_node = N;

    int root = y_combinator([&](auto solve, const vector<int> &who) -> int {
        if (who.size() == 1) {
            salary[who[0]] = A[who[0]][who[0]];
            return who[0];
        }

        int n = int(who.size());
        int big = 0;

        for (int i = 0; i < n; i++)
            big = max(big, A[who[0]][who[i]]);

        vector<vector<int>> sections;
        vector<bool> done(n, false);

        for (int i = 0; i < n; i++)
            if (!done[i]) {
                sections.emplace_back();

                for (int j = i; j < n; j++)
                    if (A[who[i]][who[j]] != big) {
                        sections.back().push_back(who[j]);
                        done[j] = true;
                    }
            }

        vector<int> roots;

        for (const vector<int> &section : sections)
            roots.push_back(solve(section));

        for (int child : roots)
            parent[child] = next_node;

        salary[next_node] = big;
        return next_node++;
    })(_who);

    salary.resize(root + 1);
    cout << root + 1 << '\n';
    output_vector(salary);
    cout << root + 1 << '\n';

    for (int i = 0; i < root; i++)
        cout << i + 1 << ' ' << parent[i] + 1 << '\n';
}