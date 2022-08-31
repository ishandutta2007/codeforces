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
    int N, M;
    cin >> N >> M;
    vector<string> A(N);

    for (string &a : A)
        cin >> a;

    string front = A.front();
    vector<string> candidates = {front};

    for (int i = 0; i < M; i++)
        for (int c = 0; c < ALPHABET; c++)
            if (front[i] != MIN_CHAR + c) {
                string x = front;
                x[i] = char(MIN_CHAR + c);
                candidates.push_back(x);
            }

    for (string candidate : candidates) {
        bool valid = true;

        for (string &a : A) {
            int diff = 0;

            for (int i = 0; i < M; i++)
                diff += candidate[i] != a[i];

            if (diff > 1) {
                valid = false;
                break;
            }
        }

        if (valid) {
            cout << candidate << '\n';
            return;
        }
    }

    cout << -1 << '\n';
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