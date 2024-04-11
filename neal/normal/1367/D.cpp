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


const int ALPHABET = 26;
const char MIN_CHAR = 'a';

void run_case() {
    string S;
    cin >> S;
    int M;
    cin >> M;
    vector<int> B(M);

    for (auto &b : B)
        cin >> b;

    vector<int> freq(ALPHABET, 0);

    for (char &ch : S)
        freq[ch - MIN_CHAR]++;

    int current = ALPHABET - 1;
    string T(M, '?');

    while (true) {
        vector<int> zeros;

        for (int i = 0; i < M; i++)
            if (B[i] == 0) {
                zeros.push_back(i);
                B[i] = -1;
            }

        if (zeros.empty())
            break;

        while (current >= 0 && freq[current] < int(zeros.size()))
            current--;

        for (int z : zeros)
            T[z] = char(MIN_CHAR + current);

        current--;

        for (int i = 0; i < M; i++)
            for (int z : zeros)
                B[i] -= abs(i - z);
    }

    cout << T << '\n';
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