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


char opposite(char ch) {
    return '0' + '1' - ch;
}

void run_case() {
    int N;
    string A, B;
    cin >> N >> A >> B;
    vector<int> ops;
    bool flip = false;
    int start = 0, end = N;

    for (int index = N - 1; index >= 0; index--) {
        char first = flip ? opposite(A[end - 1]) : A[start];

        if (first == B[index])
            ops.push_back(1);

        ops.push_back(index + 1);

        if (!flip)
            start++;
        else
            end--;

        flip = !flip;
    }

    cout << ops.size();

    for (int x : ops)
        cout << ' ' << x;

    cout << '\n';
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