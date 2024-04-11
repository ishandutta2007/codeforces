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


const int BITS = 30;

int N;
vector<int> A;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    cin >> N;
    A.resize(N);

    for (auto &a : A)
        cin >> a;

    vector<vector<int>> arrays = {A};
    int64_t total = 0;
    int ans = 0;

    for (int bit = BITS - 1; bit >= 0; bit--) {
        int64_t counts[2] = {0, 0};

        for (vector<int> &arr : arrays) {
            int64_t occur[2] = {0, 0};
            int64_t inv = 0;

            for (int x : arr) {
                int b = x >> bit & 1;

                if (b == 0)
                    inv += occur[1];

                occur[b]++;
            }

            int64_t other = occur[0] * occur[1] - inv;
            counts[0] += inv;
            counts[1] += other;
        }

        if (counts[1] < counts[0]) {
            ans |= 1 << bit;
            total += counts[1];
        } else {
            total += counts[0];
        }

        vector<vector<int>> next_arrays;

        for (vector<int> &arr : arrays) {
            vector<int> next_arr[2];

            for (int x : arr)
                next_arr[x >> bit & 1].push_back(x);

            if (!next_arr[0].empty()) next_arrays.push_back(next_arr[0]);
            if (!next_arr[1].empty()) next_arrays.push_back(next_arr[1]);
        }

        swap(arrays, next_arrays);
    }

    cout << total << ' ' << ans << '\n';
}