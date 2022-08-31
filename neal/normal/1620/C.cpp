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

template<typename T, typename T_iterable>
vector<pair<T, int>> run_length_encoding(const T_iterable &items) {
    vector<pair<T, int>> encoding;
    T previous;
    int count = 0;

    for (const T &item : items)
        if (item == previous) {
            count++;
        } else {
            if (count > 0)
                encoding.emplace_back(previous, count);

            previous = item;
            count = 1;
        }

    if (count > 0)
        encoding.emplace_back(previous, count);

    return encoding;
}


void run_case() {
    int N, K;
    int64_t X;
    string S;
    cin >> N >> K >> X >> S;
    X--;
    vector<pair<char, int>> encoding = run_length_encoding<char>(S);
    dbg(encoding);
    vector<int64_t> bases;

    for (auto &pr : encoding)
        if (pr.first == '*')
            bases.push_back(pr.second * K + 1);

    dbg(bases);
    vector<int64_t> B;

    while (!bases.empty()) {
        B.push_back(X % bases.back());
        X /= bases.back();
        bases.pop_back();
    }

    dbg(B);
    string ans;

    for (auto &pr : encoding)
        if (pr.first == '*') {
            ans += string(B.back(), 'b');
            B.pop_back();
        } else {
            ans += string(pr.second, pr.first);
        }

    cout << ans << '\n';
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