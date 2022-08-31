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

template<typename T, typename T_iterable>
vector<pair<T, int>> run_length_encoding(const T_iterable &items) {
    vector<pair<T, int>> encoding;
    T previous;
    int count = 0;

    for (const T &item : items)
        if (item == previous) {
            count++;
        } else {
            if (count > 0)
                encoding.emplace_back(previous, count);

            previous = item;
            count = 1;
        }

    if (count > 0)
        encoding.emplace_back(previous, count);

    return encoding;
}


void run_case() {
    int N;
    string S;
    cin >> N >> S;

    if (count(S.begin(), S.end(), 'L') == N || count(S.begin(), S.end(), 'R') == N) {
        cout << (N + 2) / 3 << '\n';
        return;
    }

    for (int i = 1; i < N; i++)
        if (S[i - 1] != S[i]) {
            rotate(S.begin(), S.begin() + i, S.end());
            break;
        }

    auto encoding = run_length_encoding<char>(S);
    int total = 0;

    for (auto &pr : encoding)
        total += pr.second / 3;

    cout << total << '\n';
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