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
    int A, B, Q;
    cin >> A >> B >> Q;
    int AB =  A * B;
    vector<bool> status(AB, false);

    for (int x = 0; x < AB; x++)
        status[x] = x % A % B != x % B % A;

    vector<int> prefix_sum(AB + 1, 0);

    for (int x = 0; x < AB; x++)
        prefix_sum[x + 1] = prefix_sum[x] + status[x];

    for (int q = 0; q < Q; q++) {
        int64_t L, R;
        cin >> L >> R;
        R++;

        int64_t answer = 0;
        answer += prefix_sum[AB] - prefix_sum[L % AB];
        L += AB - L % AB;
        answer += prefix_sum[R % AB];
        R -= R % AB;
        answer += (R - L) / AB * prefix_sum[AB];
        cout << answer << (q < Q - 1 ? ' ' : '\n');
    }
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