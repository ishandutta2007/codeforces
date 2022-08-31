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
    vector<int> A(N);

    for (int &a : A)
        cin >> a;

    int X = 0, Y = 0, moves = 0;
    int turn = 0, last = 0;
    int start = 0, end = N;

    while (start < end) {
        int current = 0;

        if (turn == 0) {
            while (start < end && current <= last)
                current += A[start++];

            X += current;
        } else {
            while (start < end && current <= last)
                current += A[--end];

            Y += current;
        }

        moves++;
        turn = 1 - turn;
        last = current;
    }

    cout << moves << ' ' << X << ' ' << Y << '\n';
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