#include <algorithm>
#include <array>
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


void run_case() {
    int N, K;
    string S;
    cin >> N >> K >> S;

    for (int start = 0; start < K; start++) {
        array<bool, 2> seen = {false, false};

        for (int i = start; i < N; i += K)
            if (S[i] != '?')
                seen[S[i] - '0'] = true;

        if (seen[0] && seen[1]) {
            cout << "NO" << '\n';
            return;
        }

        if (seen[0] || seen[1]) {
            int which = seen[1];

            for (int i = start; i < N; i += K)
                if (S[i] == '?')
                    S[i] = char('0' + which);
        }
    }

    int ones = 0, qs = 0;

    for (int i = 0; i < K; i++) {
        ones += S[i] == '1';
        qs += S[i] == '?';
    }

    cout << (ones <= K / 2 && K / 2 <= ones + qs ? "YES" : "NO") << '\n';
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