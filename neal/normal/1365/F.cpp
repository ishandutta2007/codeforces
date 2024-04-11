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


vector<array<int, 2>> get_pairs(vector<int> v) {
    int n = int(v.size());
    vector<array<int, 2>> pairs;

    for (int i = 0, j = n - 1; i < j; i++, j--)
        pairs.push_back({min(v[i], v[j]), max(v[i], v[j])});

    sort(pairs.begin(), pairs.end());
    return pairs;
}

void run_case() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);

    for (auto &a : A)
        cin >> a;

    for (auto &b : B)
        cin >> b;

    bool answer = true;

    if (N % 2 != 0 && A[N / 2] != B[N / 2])
        answer = false;

    if (get_pairs(A) != get_pairs(B))
        answer = false;

    cout << (answer ? "Yes" : "No") << '\n';
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