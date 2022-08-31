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


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N;
    string L, R;
    cin >> N >> L >> R;

    if (R == string(N, '0')) {
        cout << R << '\n';
        return 0;
    }

    if (L[0] == '0') {
        cout << string(N, '1') << '\n';
        return 0;
    }

    auto increment = [&](string str) {
        assert(int(str.size()) == N);

        for (int i = N - 1; i >= 0; i--)
            if (str[i] == '0') {
                str[i]++;
                break;
            } else {
                str[i] = '0';
            }

        return str;
    };

    auto string_xor = [&](string a, string b) {
        string str(N, '?');

        for (int i = 0; i < N; i++)
            str[i] = char('0' + ((a[i] - '0') ^ (b[i] - '0')));

        return str;
    };

    string iter = L;
    int count = 0;

    while (iter != R && count < 4) {
        iter = increment(iter);
        count++;
    }

    if (count >= 4) {
        R.back() = '1';
        cout << R << '\n';
        return 0;
    }

    string best(N, '0');

    for (int i = 0; i <= count; i++)
        for (int j = i; j <= count; j++) {
            string a = L;
            string result(N, '0');

            for (int x = 0; x <= j; x++) {
                if (i <= x && x <= j)
                    result = string_xor(result, a);

                a = increment(a);
            }

            best = max(best, result);
        }

    cout << best << '\n';
}