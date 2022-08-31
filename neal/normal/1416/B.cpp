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


void run_case() {
    int N;
    cin >> N;
    vector<int> A(N + 1);
    int sum = 0;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        sum += A[i];
    }

    if (sum % N != 0) {
        cout << -1 << '\n';
        return;
    }

    int goal = sum / N;
    vector<array<int, 3>> moves;

    auto add_move = [&](int i, int j, int x) {
        if (i == j)
            return;

        assert(A[i] >= x * i);
        A[i] -= x * i;
        A[j] += x * i;
        moves.push_back({i, j, x});
    };

    for (int i = 2; i <= N; i++) {
        if (A[i] % i != 0)
            add_move(1, i, i - A[i] % i);

        assert(A[i] % i == 0);
        add_move(i, 1, A[i] / i);
        assert(A[i] == 0);
    }

    for (int i = 2; i <= N; i++)
        add_move(1, i, goal);

    cout << moves.size() << '\n';

    for (auto &move : moves)
        cout << move[0] << ' ' << move[1] << ' ' << move[2] << '\n';
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