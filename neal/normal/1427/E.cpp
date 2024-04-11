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


const int P = 20;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int64_t X;
    cin >> X;
    vector<string> ops;
    ops.push_back(to_string(X) + " ^ " + to_string(X));

    while (X != 1) {
        vector<int64_t> numbers = {0, X};

        for (int p = 0; p < P; p++) {
            ops.push_back(to_string(X << p) + " + " + to_string(X << p));
            numbers.push_back(X << (p + 1));
        }

        for (int p = 1; p < P; p++) {
            ops.push_back(to_string(X * ((1 << p) - 1)) + " + " + to_string(X << p));
            numbers.push_back(X * ((1 << (p + 1)) - 1));
        }

        sort(numbers.begin(), numbers.end());
        int n = int(numbers.size());
        int64_t best = X;
        vector<int64_t> choices;

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                for (int k = j + 1; k < n; k++) {
                    int64_t candidate = numbers[i] ^ numbers[j] ^ numbers[k];

                    if (candidate % 2 != 0 && candidate < best) {
                        best = candidate;
                        choices = {numbers[i], numbers[j], numbers[k]};
                    }
                }

        assert(best < X);
        ops.push_back(to_string(choices[0]) + " ^ " + to_string(choices[1]));
        ops.push_back(to_string(choices[0] ^ choices[1]) + " ^ " + to_string(choices[2]));
        X = best;
    }

    cout << ops.size() << '\n';

    for (auto &op : ops)
        cout << op << '\n';
}