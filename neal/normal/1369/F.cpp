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


bool solve(int64_t S, int64_t E, bool lose) {
    bool all = lose;
    bool top = lose;

    while (S <= E / 2) {
        if (all) {
            all = top = false;
        } else {
            all = top ^ (E % 2 == 0);
            top = top ^ ((E / 2) % 2 != E % 2);
        }

        E /= 2;
    }

    return all || (top ^ (S % 2 != E % 2));
}

bool can_win(int64_t S, int64_t E) {
    return solve(S, E, false);
}

bool can_lose(int64_t S, int64_t E) {
    return solve(S, E, true);
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N;
    cin >> N;
    vector<int64_t> S(N), E(N);

    for (int i = 0; i < N; i++)
        cin >> S[i] >> E[i];

    vector<array<bool, 2>> need(N + 1);
    need[N] = {true, false};

    for (int i = N - 1; i >= 0; i--)
        for (int t = 0; t < 2; t++)
            need[i][t] = !(need[i + 1][t] ? can_win(S[i], E[i]) : can_lose(S[i], E[i]));

    cout << !need[0][0] << ' ' << !need[0][1] << '\n';
}