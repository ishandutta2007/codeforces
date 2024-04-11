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

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


void run_case() {
    int N;
    cin >> N;
    vector<int> A(N), B(N), C(N);

    for (auto &a : A) cin >> a;
    for (auto &b : B) cin >> b;
    for (auto &c : C) cin >> c;

    vector<int> P(N);
    P[0] = A[0];

    for (int i = 1; i < N - 1; i++)
        if (A[i] != P[i - 1])
            P[i] = A[i];
        else if (B[i] != P[i - 1])
            P[i] = B[i];
        else
            P[i] = C[i];

    if (A[N - 1] != P[N - 2] && A[N - 1] != P[0])
        P[N - 1] = A[N - 1];
    else if (B[N - 1] != P[N - 2] && B[N - 1] != P[0])
        P[N - 1] = B[N - 1];
    else
        P[N - 1] = C[N - 1];

    output_vector(P);
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