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


const string SHIRTS[] = {"S", "M", "L", "XL", "XXL", "XXXL"};
const int T = 6;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    array<int, T> shirts;

    for (int i = 0; i < T; i++)
        cin >> shirts[i];

    array<int, T> want;
    want.fill(0);
    array<vector<int>, T> either;

    int N;
    cin >> N;
    vector<string> answers(N);

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        answers[i] = str;

        for (int t = 0; t < T; t++)
            if (str == SHIRTS[t])
                want[t]++;

        for (int t = 0; t < T - 1; t++)
            if (str == SHIRTS[t] + "," + SHIRTS[t + 1])
                either[t].push_back(i);
    }

    bool success = true;

    for (int t = 0; t < T; t++) {
        if (t > 0 && shirts[t] < int(either[t - 1].size()))
            success = false;

        if (t > 0) {
            shirts[t] -= int(either[t - 1].size());

            for (int x : either[t - 1])
                answers[x] = SHIRTS[t];
        }

        if (shirts[t] < want[t])
            success = false;

        shirts[t] -= want[t];

        if (t < T - 1) {
            int extra = min(shirts[t], int(either[t].size()));
            shirts[t] -= extra;

            for (int iter = 0; iter < extra; iter++) {
                answers[either[t].back()] = SHIRTS[t];
                either[t].pop_back();
            }
        }
    }

    cout << (success ? "YES" : "NO") << '\n';

    if (success) {
        for (int i = 0; i < N; i++)
            cout << answers[i] << '\n';
    }
}