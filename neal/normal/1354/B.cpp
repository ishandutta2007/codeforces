#include <algorithm>
#include <array>
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


const int INF = 1e9 + 5;

void run_case() {
    string S;
    cin >> S;
    int N = int(S.size());
    array<int, 4> freq = {0, 0, 0, 0};
    int distinct = 0;
    int answer = INF;

    for (int i = 0, j = 0; i < N; i++) {
        while (j < N && distinct < 3) {
            if (freq[S[j] - '0']++ == 0)
                distinct++;

            j++;
        }

        if (distinct == 3)
            answer = min(answer, j - i);

        if (--freq[S[i] - '0'] == 0)
            distinct--;
    }

    cout << (answer < INF ? answer : 0) << '\n';
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