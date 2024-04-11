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

// Given a list of values, finds the minimum total amount of movement needed to make them all equal.
template<typename T_out, typename T_in> T_out min_equal_distance(vector<T_in> values) {
    if (values.empty())
        return 0;

    int n = int(values.size());
    nth_element(values.begin(), values.begin() + n / 2, values.end());
    T_in median = values[n / 2];
    T_out total = 0;

    for (T_in x : values)
        total += abs(x - median);

    return total;
}

// Given a list of values, finds the minimum total amount of movement to make them contiguous (x, x + 1, x + 2, ...).
template<typename T_out, typename T_in> T_out min_contiguous_distance(vector<T_in> values) {
    if (!is_sorted(values.begin(), values.end()))
        sort(values.begin(), values.end());

    for (int i = 0; i < int(values.size()); i++)
        values[i] -= i;

    return min_equal_distance<T_out>(values);
}


void run_case() {
    int N;
    string str;
    cin >> N >> str;
    vector<int> sheep;

    for (int i = 0; i < N; i++)
        if (str[i] == '*')
            sheep.push_back(i);

    cout << min_contiguous_distance<int64_t>(sheep) << '\n';
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