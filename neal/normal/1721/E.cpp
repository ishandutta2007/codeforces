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


const int ALPHABET = 26;
const char MIN_CHAR = 'a';
const int L_MAX = 10;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    string S;
    cin >> S;

    int N = int(S.size());
    vector<array<int, ALPHABET>> link(N + L_MAX + 1, array<int, ALPHABET>());
    vector<int> fail(N + L_MAX + 1, 0);

    for (int i = 0; i < N; i++) {
        int c = S[i] - MIN_CHAR;
        int previous = link[i][c];
        fail[i + 1] = previous;
        link[i][c] = i + 1;
        link[i + 1] = link[previous];
    }

    int Q;
    cin >> Q;
    array<int, ALPHABET> link_N = link[N];

    for (int q = 0; q < Q; q++) {
        string T;
        cin >> T;
        int L = int(T.size());
        S += T;

        for (int i = N; i < N + L; i++) {
            int c = S[i] - MIN_CHAR;
            int previous = link[i][c];
            fail[i + 1] = previous;
            link[i][c] = i + 1;
            link[i + 1] = link[previous];

            cout << fail[i + 1] << (i < N + L - 1 ? ' ' : '\n');
        }

        S.resize(N);
        link[N] = link_N;
    }
}