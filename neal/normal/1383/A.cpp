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
    int N;
    string A, B;
    cin >> N >> A >> B;

    for (int i = 0; i < N; i++)
        if (A[i] > B[i]) {
            cout << -1 << '\n';
            return;
        }

    int moves = 0;

    for (char ch = 'a'; ch <= 't'; ch++) {
        vector<int> positions;
        char minimum = 'z';

        for (int i = 0; i < N; i++)
            if (A[i] == ch && B[i] > ch) {
                positions.push_back(i);
                minimum = min(minimum, B[i]);
            }

        if (!positions.empty()) {
            for (int x : positions)
                A[x] = minimum;

            moves++;
        }
    }

    assert(A == B);
    cout << moves << '\n';
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