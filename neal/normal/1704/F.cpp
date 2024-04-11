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

template<typename T_array>
int compute_mex(const T_array &values) {
    int n = int(values.size());
    vector<bool> seen(n + 1, false);

    for (const auto &x : values)
        if (x <= n)
            seen[x] = true;

    int mex = 0;

    while (seen[mex])
        mex++;

    return mex;
}


vector<int> save(1000, -1);

int solve(int n) {
    if (n <= 1)
        return 0;

    // Period 34 after a certain point
    if (n >= 100)
        n = 100 + (n - 100) % 34;

    if (save[n] >= 0)
        return save[n];

    vector<int> choices;

    for (int i = 0; i + 2 <= n; i++)
        choices.push_back(solve(i) ^ solve(n - i - 2));

    return save[n] = compute_mex(choices);
}


void run_case() {
    int N;
    string S;
    cin >> N >> S;
    string flip = S;

    for (int i = 1; i < N; i += 2)
        flip[i] ^= 'R' ^ 'B';

    vector<pair<char, int>> encoding = run_length_encoding<char>(flip);
    int SG = 0;

    for (auto &pr : encoding)
        SG ^= solve(pr.second);

    int difference = 0;

    for (auto &ch : S)
        difference += ch == 'R' ? +1 : -1;

    int win_RB = SG != 0;
    cout << (difference + win_RB >= 1 ? "Alice" : "Bob") << '\n';
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