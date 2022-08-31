#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
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


void run_case() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N + 2, 0);

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    auto get_diff = [&](int index) {
        return max(A[index] - A[index + 1], 0);
    };

    int64_t answer = 0;

    for (int i = 0; i <= N; i++)
        answer += get_diff(i);

    cout << answer << '\n';

    auto modify = [&](int index, int value) {
        answer -= get_diff(index - 1) + get_diff(index);
        A[index] = value;
        answer += get_diff(index - 1) + get_diff(index);
    };

    for (int q = 0; q < Q; q++) {
        int L, R;
        cin >> L >> R;
        int AL = A[L], AR = A[R];
        modify(L, AR);
        modify(R, AL);
        cout << answer << '\n';
    }
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