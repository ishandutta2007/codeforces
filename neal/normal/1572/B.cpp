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


void run_case() {
    int N;
    cin >> N;
    vector<int> A(N);

    for (auto &a : A)
        cin >> a;

    vector<int> prefix_xor(N + 1, 0);

    for (int i = 0; i < N; i++)
        prefix_xor[i + 1] = prefix_xor[i] ^ A[i];

    if (prefix_xor[N] == 1 || *min_element(A.begin(), A.end()) == 1) {
        cout << "NO" << '\n';
        return;
    }

    vector<int> ops;

    auto solve_odd = [&](int start, int end) -> void {
        assert((end - start) % 2 != 0);

        for (int i = start; i < end - 3; i += 2)
            ops.push_back(i);

        for (int i = end - 3; i >= start; i -= 2)
            ops.push_back(i);
    };

    if (N % 2 != 0) {
        solve_odd(0, N);
    } else {
        bool found = false;

        for (int split = 1; split <= N; split += 2)
            if (prefix_xor[split] == 0) {
                solve_odd(0, split);
                solve_odd(split, N);
                found = true;
                break;
            }

        if (!found) {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';
    cout << ops.size() << '\n';
    output_vector(ops, true);
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