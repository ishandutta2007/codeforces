#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
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

int sign(int x) {
    return (x > 0) - (x < 0);
}

void run_case() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);

    for (auto &a : A)
        cin >> a;

    if (N == 1) {
        cout << (A[0] == K ? "yes" : "no") << '\n';
        return;
    }

    if (find(A.begin(), A.end(), K) == A.end()) {
        cout << "no" << '\n';
        return;
    }

    for (auto &a : A)
        a = a >= K ? +1 : -1;

    vector<int> prefix_sums(N + 1, 0);

    for (int i = 0; i < N; i++)
        prefix_sums[i + 1] = prefix_sums[i] + A[i];

    int maximum = -INF;

    for (int i = N - 2; i >= 0; i--) {
        maximum = max(maximum, prefix_sums[i + 2]);

        if (maximum > prefix_sums[i]) {
            cout << "yes" << '\n';
            return;
        }
    }

    cout << "no" << '\n';
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