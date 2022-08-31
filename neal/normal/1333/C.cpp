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


int N;
vector<int> A;
vector<int64_t> prefix_sums;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    cin >> N;
    A.resize(N);

    for (auto &a : A)
        cin >> a;

    prefix_sums.assign(N + 1, 0);

    for (int i = 0; i < N; i++)
        prefix_sums[i + 1] = prefix_sums[i] + A[i];

    map<int64_t, int> closest;
    int64_t total = 0;
    int start = 0;

    for (int i = 0; i <= N; i++) {
        if (closest.find(prefix_sums[i]) != closest.end())
            start = max(start, closest[prefix_sums[i]] + 1);

        total += i - start;
        closest[prefix_sums[i]] = i;
    }

    cout << total << '\n';
}