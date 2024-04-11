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

bool prime(int64_t n) {
    if (n < 2)
        return false;

    if (n > 2 && n % 2 == 0)
        return false;

    for (int64_t i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;

    return true;
}


void run_case() {
    int N;
    cin >> N;
    int diff = 4 * (N - 1);
    int x = 1;

    while (!(!prime(x) && prime(x + diff)))
        x++;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cout << (i == j ? x : 4) << (j < N - 1 ? ' ' : '\n');
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