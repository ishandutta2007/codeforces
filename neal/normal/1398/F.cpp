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


vector<int> next_on;

int find_on(int x) {
    return next_on[x] == x ? x : next_on[x] = find_on(next_on[x]);
}

void turn_off(int x) {
    assert(next_on[x] == x);
    next_on[x] = x + 1;
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N;
    string S;
    cin >> N >> S;
    vector<vector<int>> indices_by_jump(N + 1);
    array<int, 2> closest = {N, N};

    for (int i = N - 1; i >= 0; i--) {
        if (S[i] != '?')
            closest[S[i] - '0'] = i;

        int jump = *max_element(closest.begin(), closest.end()) - i;
        indices_by_jump[jump].push_back(i);
    }

    next_on.resize(N + 1);

    for (int i = 0; i <= N; i++)
        next_on[i] = i;

    for (int x = 1; x <= N; x++) {
        for (int index : indices_by_jump[x - 1])
            turn_off(index);

        int current = 0, count = 0;

        while (current < N) {
            current = find_on(current);

            if (current >= N)
                break;

            current += x;
            count++;
        }

        cout << count << (x < N ? ' ' : '\n');
    }
}