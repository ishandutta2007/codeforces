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


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N;
    cin >> N;
    vector<int> A(N), B(N);
    vector<int> A_loc(N + 1), B_loc(N + 1);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A_loc[A[i]] = i;
    }

    for (int i = 0; i < N; i++) {
        cin >> B[i];
        B_loc[B[i]] = i;
    }

    vector<int> freq(N, 0);

    for (int x = 1; x <= N; x++)
        freq[(B_loc[x] - A_loc[x] + N) % N]++;

    cout << *max_element(freq.begin(), freq.end()) << '\n';
}