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


int N;
vector<int> A;

int solve(int first, int last) {
    if (first > last)
        return 0;

    int outside = max(A[first - 1], A[last + 1]);
    int min_index = int(min_element(A.begin() + first, A.begin() + last + 1) - A.begin());
    int minimum = A[min_index];
    return min(last - first + 1, solve(first, min_index - 1) + solve(min_index + 1, last) + minimum - outside);
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    cin >> N;
    A.assign(N + 2, 0);

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    cout << solve(1, N) << '\n';
}