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


const int INF = 1e9 + 5;

int N, K, L;

int get_tide(int time) {
    time %= 2 * K;
    return min(time, 2 * K - time);
}

void run_case() {
    cin >> N >> K >> L;
    dbg(N, K, L);
    vector<int> D(N + 2, -INF);

    for (int i = 1; i <= N; i++)
        cin >> D[i];

    if (*max_element(D.begin(), D.end()) > L) {
        cout << "No" << '\n';
        return;
    }

    int time = 0;

    for (int i = 1; i <= N; i++) {
        int d = D[i];
        time = (time + 1) % (2 * K);

        if (D[i - 1] + K <= L)
            time = K;
        else if (time <= K && d + get_tide(time) > L) {
            cout << "No" << '\n';
            return;
        }

        if (time >= K) {
            int maximum = min(L - d, K);
            time = max(time, 2 * K - maximum);
        }

        dbg(i, time);
    }

    cout << "Yes" << '\n';
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