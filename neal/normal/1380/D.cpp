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


const int64_t INF64 = int64_t(2e18) + 5;

int N, M, K;
int64_t X, Y;

int64_t solve(const vector<int> &A, int start, int end) {
    int count = end - start;

    if (count <= 0)
        return 0;

    int bigger = max(start <= 0 ? 0 : A[start - 1], end >= N ? 0 : A[end]);

    if (bigger > *max_element(A.begin() + start, A.begin() + end)) {
        // No restrictions on fireballs
        return (count / K) * min(X, Y * K) + (count % K) * Y;
    } else {
        // At least one fireball
        if (count < K)
            return INF64;

        return X + (count / K - 1) * min(X, Y * K) + (count % K) * Y;
    }
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    cin >> N >> M >> X >> K >> Y;
    vector<int> A(N), B(M);

    for (auto &a : A)
        cin >> a;

    for (auto &b : B)
        cin >> b;

    int64_t answer = 0;
    int position = 0;

    for (auto &b : B) {
        int start = position;

        while (position < N && A[position] != b)
            position++;

        if (position >= N) {
            cout << -1 << '\n';
            return 0;
        }

        assert(A[position] == b);
        answer += solve(A, start, position);
        position++;

        if (answer >= INF64) {
            cout << -1 << '\n';
            return 0;
        }
    }

    if (position < N) {
        answer += solve(A, position, N);

        if (answer >= INF64) {
            cout << -1 << '\n';
            return 0;
        }
    }

    cout << answer << '\n';
}