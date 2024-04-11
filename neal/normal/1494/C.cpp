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


int solve(vector<int> A, vector<int> B) {
    assert(is_sorted(A.begin(), A.end()));
    assert(is_sorted(B.begin(), B.end()));
    int N = int(A.size());
    int M = int(B.size());
    vector<int> suffix_match(N + 1, 0);

    for (int i = N - 1; i >= 0; i--)
        suffix_match[i] = suffix_match[i + 1] + binary_search(B.begin(), B.end(), A[i]);

    int best = 0;

    for (int prefix = 0; prefix <= N; prefix++) {
        int start = prefix > 0 ? int(lower_bound(B.begin(), B.end(), A[prefix - 1]) - B.begin()) : 0;
        int end = prefix < N ? int(lower_bound(B.begin(), B.end(), A[prefix]) - B.begin()) : M;
        int prefix_match = 0;

        for (int i = start; i < end; i++) {
            int cutoff = int(upper_bound(B.begin(), B.end(), B[i] - prefix) - B.begin());
            prefix_match = max(prefix_match, i - cutoff + 1);
        }

        best = max(best, prefix_match + suffix_match[prefix]);
    }

    return best;
}

void run_case() {
    int N, M;
    cin >> N >> M;
    vector<int> A_neg, B_neg;
    vector<int> A_pos, B_pos;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;

        if (a < 0)
            A_neg.push_back(-a);
        else
            A_pos.push_back(a);
    }

    for (int i = 0; i < M; i++) {
        int b;
        cin >> b;

        if (b < 0)
            B_neg.push_back(-b);
        else
            B_pos.push_back(b);
    }

    reverse(A_neg.begin(), A_neg.end());
    reverse(B_neg.begin(), B_neg.end());
    cout << solve(A_neg, B_neg) + solve(A_pos, B_pos) << '\n';
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