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
    vector<int> P(N);

    for (auto &p : P)
        cin >> p;

    vector<int> location(N + 1, -1);

    for (int i = 0; i < N; i++)
        location[P[i]] = i;

    bool works = true;
    int current = 1;
    int start = location[1];
    int last = N - 1;

    while (current <= N) {
        if (current > 1 && location[current] != location[current - 1] + 1) {
            if (location[current - 1] != last)
                works = false;

            last = start - 1;
            start = location[current];
        }

        current++;
    }

    cout << (works ? "Yes" : "No") << '\n';
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