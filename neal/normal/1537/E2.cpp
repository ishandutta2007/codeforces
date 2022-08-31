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

// Also known as "extended KMP"
template<typename T>
vector<int> z_algorithm(const T &pattern) {
    // Z[i] = for the suffix [i, n) of pattern, the longest prefix that is also a prefix of pattern.
    int n = int(pattern.size());
    vector<int> Z(n, 0);
    Z[0] = n;
    int loc = 1;

    for (int i = 1; i < n; i++) {
        if (i < loc + Z[loc])
            Z[i] = min(Z[i - loc], loc + Z[loc] - i);

        while (i + Z[i] < n && pattern[Z[i]] == pattern[i + Z[i]])
            Z[i]++;

        // Find the location with the furthest-reaching umbrella.
        if (i + Z[i] > loc + Z[loc])
            loc = i;
    }

    return Z;
}


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, K;
    string S;
    cin >> N >> K >> S;
    vector<int> Z = z_algorithm(S);
    int x = 1;

    for (int end = 2; end <= N; end++) {
        int y = end - x;

        // Let x_str = S.substr(0, x) and y_str = S.substr(x, y). Determine whether y_str + x_str < x_str + y_str.
        if (Z[x] < y) {
            if (S[x + Z[x]] < S[Z[x]])
                x = end;
        } else if (Z[y] < x) {
            if (S[Z[y]] < S[y + Z[y]])
                x = end;
        }
    }

    string ans;

    for (int i = 0; i < K; i++)
        ans += S[i % x];

    cout << ans << '\n';
}