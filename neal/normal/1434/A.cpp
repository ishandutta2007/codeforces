#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <set>
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


const int S = 6;
const int64_t INF64 = int64_t(2e18) + 5;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    array<int64_t, S> A;

    for (auto &a : A)
        cin >> a;

    int N;
    cin >> N;
    vector<int64_t> B(N);

    for (auto &b : B)
        cin >> b;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    vector<pair<int64_t, int>> events;

    for (int i = 0; i < N; i++)
        for (auto &a : A)
            events.emplace_back(B[i] - a, i);

    sort(events.rbegin(), events.rend());
    vector<int64_t> cost(N, INF64);
    set<pair<int64_t, int>> choices;

    for (int i = 0; i < N; i++)
        choices.emplace(cost[i], i);

    int64_t best = INF64;

    for (auto &e : events) {
        int index = e.second;
        choices.erase({cost[index], index});
        cost[index] = e.first;
        choices.emplace(cost[index], index);
        best = min(best, choices.rbegin()->first - e.first);
    }

    cout << best << '\n';
}