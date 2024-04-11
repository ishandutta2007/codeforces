#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


void run_case() {
    int N;
    cin >> N;

    int D = 31 - __builtin_clz(N);
    vector<int> splits(D);

    for (int d = 0; d < D; d++)
        splits[d] = 1 << d;

    int current = (2 << D) - 1;
    int extra = current - N;
    int remove = 0;

    for (int d = 0; d < D; d++) {
        int take = (1 << (D - d)) - 1;
        int here = min(extra / take, splits[d] - remove);
        extra -= here * take;
        splits[d] -= remove + here;
        remove = 2 * remove + here;
    }

    assert(extra == 0);
    cout << D << '\n';

    for (int d = 0; d < D; d++)
        cout << splits[d] << (d < D - 1 ? ' ' : '\n');
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