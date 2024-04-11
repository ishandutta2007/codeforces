#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


const int N_MAX = 4005;

void run_case() {
    int N;
    cin >> N;
    vector<int> P(2 * N);

    for (auto &p : P)
        cin >> p;

    int L = 2 * N;
    vector<int> lengths;

    for (int big = 2 * N; big > 0; big--) {
        for (int i = 0; i < L; i++)
            if (P[i] == big) {
                lengths.push_back(L - i);
                L = i;
                break;
            }
    }

    bitset<N_MAX> possible;
    possible[0] = true;

    for (int len : lengths)
        possible |= possible << len;

    cout << (possible[N] ? "YES" : "NO") << '\n';
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