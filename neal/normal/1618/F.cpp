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


string to_binary(int64_t n) {
    string str;

    while (n != 0) {
        str += char('0' + n % 2);
        n /= 2;
    }

    reverse(str.begin(), str.end());
    return str;
}

string reversed(string str) {
    reverse(str.begin(), str.end());
    return str;
}

bool matches(string in, string out) {
    int n = int(in.size());
    int m = int(out.size());

    for (int i = 0; i + n <= m; i++) {
        if (out.substr(i, n) != in)
            continue;

        bool good = true;

        for (int j = 0; j < i; j++)
            good = good && out[j] == '1';

        for (int j = i + n; j < m; j++)
            good = good && out[j] == '1';

        if (good)
            return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int64_t X, Y;
    cin >> X >> Y;
    string X_bin = to_binary(X);
    string Y_bin = to_binary(Y);
    string X1_bin = X_bin + '1';

    while (!X_bin.empty() && X_bin.back() == '0')
        X_bin.pop_back();

    bool ans = X == Y;
    ans = ans || matches(X_bin, Y_bin);
    ans = ans || matches(reversed(X_bin), Y_bin);
    ans = ans || matches(X1_bin, Y_bin);
    ans = ans || matches(reversed(X1_bin), Y_bin);
    cout << (ans ? "YES" : "NO") << '\n';
}