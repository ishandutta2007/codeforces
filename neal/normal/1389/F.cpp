#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <set>
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


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N;
    cin >> N;
    vector<array<int, 2>> left, right;

    for (int i = 0; i < N; i++) {
        int L, R, T;
        cin >> L >> R >> T;

        if (T == 1)
            left.push_back({L, R});
        else
            right.push_back({L, R});
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end(), [&](const array<int, 2> &a, const array<int, 2> &b) {
        return a[1] < b[1];
    });

    multiset<int> endings;
    int match = 0;
    size_t index = 0;

    for (auto &seg : right) {
        while (index < left.size() && left[index][0] <= seg[1])
            endings.insert(left[index++][1]);

        auto it = endings.lower_bound(seg[0]);

        if (it != endings.end()) {
            endings.erase(it);
            match++;
        }
    }

    cout << N - match << '\n';
}