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
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M, Q;
    cin >> N >> M >> Q;
    vector<int64_t> A(N), B(M);

    for (auto &a : A)
        cin >> a;

    for (auto &b : B)
        cin >> b;

    vector<pair<int64_t, int>> C(N + M);

    for (int i = 0; i < N; i++)
        C[i] = {A[i], i};

    for (int i = N; i < N + M; i++)
        C[i] = {B[i - N], i};

    sort(C.begin(), C.end());
    vector<pair<int64_t, int>> sorted_gaps(N + M - 1);

    for (int i = 0; i < N + M - 1; i++)
        sorted_gaps[i] = {C[i + 1].first - C[i].first, i};

    sort(sorted_gaps.begin(), sorted_gaps.end());
    vector<pair<int64_t, int>> queries(Q);

    for (int q = 0; q < Q; q++) {
        cin >> queries[q].first;
        queries[q].second = q;
    }

    vector<int> parent(N + M);
    iota(parent.begin(), parent.end(), 0);
    vector<int> item_cnt(N + M, 0);

    for (int i = 0; i < N + M; i++)
        item_cnt[i] = C[i].second < N;

    vector<int64_t> prefix_sum(N + M + 1, 0);

    for (int i = 0; i < N + M; i++)
        prefix_sum[i + 1] = prefix_sum[i] + C[i].first;

    auto find = y_combinator([&](auto self, int x) -> int {
        return x == parent[x] ? x : parent[x] = self(parent[x]);
    });

    sort(queries.begin(), queries.end());
    vector<int64_t> answers(Q, -1);
    int64_t sum = accumulate(A.begin(), A.end(), 0LL);
    int s = 0;

    auto remove_gap = [&](int index) -> void {
        assert(find(index) == index);
        int after = find(index + 1);
        sum -= prefix_sum[index + 1] - prefix_sum[index + 1 - item_cnt[index]];
        int end = after + 1 - item_cnt[after];
        sum += prefix_sum[end] - prefix_sum[end - item_cnt[index]];
        item_cnt[after] += item_cnt[index];
        item_cnt[index] = 0;
        parent[index] = after;
    };

    for (auto &qry : queries) {
        int64_t k = qry.first;

        while (s < N + M - 1 && sorted_gaps[s].first <= k)
            remove_gap(sorted_gaps[s++].second);

        answers[qry.second] = sum;
    }

    for (int64_t ans : answers)
        cout << ans << '\n';
}