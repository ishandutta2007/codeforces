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

    int B;
    string S;
    cin >> B >> S;
    int N = 1 << B;
    assert(int(S.size()) == N);
    vector<int> sorted(N, -1);
    vector<int> freq(128, 0);

    for (int i = 0; i < N; i++)
        freq[S[i]]++;

    for (int c = 1; c < 128; c++)
        freq[c] += freq[c - 1];

    for (int i = 0; i < N; i++)
        sorted[--freq[S[i]]] = i;

    vector<int> rank(N);
    rank[sorted[0]] = 0;

    for (int i = 1; i < N; i++)
        rank[sorted[i]] = S[sorted[i]] == S[sorted[i - 1]] ? rank[sorted[i - 1]] : i;

    for (int bit = 0; bit < B; bit++) {
        vector<int> next_index(N);
        iota(next_index.begin(), next_index.end(), 0);
        vector<int> values(N, -1);

        for (int i = 0; i < N; i++) {
            int other = sorted[i] ^ 1 << bit;
            values[next_index[rank[other]]++] = other;
        }

        sorted.swap(values);
        values[sorted[0]] = 0;

        for (int i = 1; i < N; i++) {
            int s = sorted[i], before = sorted[i - 1];

            if (rank[s] == rank[before] && rank[s ^ 1 << bit] == rank[before ^ 1 << bit])
                values[s] = values[before];
            else
                values[s] = i;
        }

        rank.swap(values);
    }

    int x = sorted[0];

    for (int i = 0; i < N; i++)
        cout << S[x ^ i];

    cout << '\n';
}