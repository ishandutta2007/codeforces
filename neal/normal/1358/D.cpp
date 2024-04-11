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


int64_t sum_up_to(int64_t n) {
    return n * (n + 1) / 2;
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N;
    int64_t X;
    cin >> N >> X;
    vector<int64_t> D(N);

    for (auto &d : D)
        cin >> d;

    for (int i = 0; i < N; i++)
        D.push_back(D[i]);

    vector<int64_t> prefix_days(2 * N + 1, 0);
    vector<int64_t> prefix_hugs(2 * N + 1, 0);

    for (int i = 0; i < 2 * N; i++) {
        prefix_days[i + 1] = prefix_days[i] + D[i];
        prefix_hugs[i + 1] = prefix_hugs[i] + sum_up_to(D[i]);
    }

    int64_t best = 0;

    for (int end = N + 1, first = 0; end <= 2 * N; end++) {
        while (first < end && prefix_days[end] - prefix_days[first + 1] >= X)
            first++;

        int64_t hugs = prefix_hugs[end] - prefix_hugs[first + 1];
        int64_t days_in_first = X - (prefix_days[end] - prefix_days[first + 1]);
        hugs += sum_up_to(D[first]) - sum_up_to(D[first] - days_in_first);
        best = max(best, hugs);
    }

    cout << best << '\n';
}