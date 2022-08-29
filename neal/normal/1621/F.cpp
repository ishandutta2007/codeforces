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
    vector<pair<T, int>> runs;
    T previous;
    int count = 0;

    for (const T &item : items)
        if (item == previous) {
            count++;
        } else {
            if (count > 0)
                runs.emplace_back(previous, count);

            previous = item;
            count = 1;
        }

    if (count > 0)
        runs.emplace_back(previous, count);

    return runs;
}


void run_case() {
    int N;
    int64_t A, B, C;
    string S;
    cin >> N >> A >> B >> C >> S;
    vector<pair<char, int>> runs = run_length_encoding<char>(S);
    int a_count = 0, b_count = 0;

    for (auto &run : runs)
        if (run.first == '0')
            a_count += run.second - 1;
        else
            b_count += run.second - 1;

    if (B <= C) {
        a_count = min(a_count, b_count + 1);
        b_count = min(b_count, a_count + 1);
        cout << a_count * A + b_count * B << '\n';
        return;
    }

    assert(B > C);
    int R = int(runs.size());

    if (a_count >= b_count) {
        vector<int> zero_runs;

        for (int i = 1; i < R - 1; i++)
            if (runs[i].first == '0')
                zero_runs.push_back(runs[i].second);

        sort(zero_runs.begin(), zero_runs.end());
        int Z = int(zero_runs.size());
        int remaining = b_count;
        int single_zeros = 0;

        while (single_zeros < Z && remaining >= zero_runs[single_zeros] - 1) {
            remaining -= zero_runs[single_zeros] - 1;
            single_zeros++;
        }

        int64_t ans = b_count * (A + B);
        ans += single_zeros * (B - C);
        ans += (a_count > b_count) * A;
        cout << ans << '\n';
        return;
    }

    assert(a_count < b_count);
    int remaining_zeros = int(count(S.begin(), S.end(), '0')) - a_count;
    int remaining_ones = int(count(S.begin(), S.end(), '1')) - (a_count + 1);
    int64_t ans = a_count * A + (a_count + 1) * B;
    ans += max(min(remaining_zeros, remaining_ones - 1), 0) * (B - C);
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