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
    string S;
    cin >> S;
    int N = int(S.size());
    int best = 0;

    for (int a = 0; a <= 9; a++)
        for (int b = 0; b <= 9; b++) {
            int a_cnt = 0, b_cnt = 0;

            for (auto &ch : S) {
                int d = ch - '0';

                if (a_cnt <= b_cnt) {
                    if (d == a)
                        a_cnt++;
                } else {
                    if (d == b)
                        b_cnt++;
                }
            }

            best = max(best, a == b ? a_cnt + b_cnt : 2 * b_cnt);
        }

    cout << N - best << '\n';
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