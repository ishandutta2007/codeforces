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

// Finds the length of the longest subsequence of values such that compare is true for all consecutive pairs.
template<typename T, typename T_compare>
int longest_increasing_subsequence(vector<T> values, T_compare &&compare) {
    vector<T> best_ending;

    for (T value : values) {
        auto it = lower_bound(best_ending.begin(), best_ending.end(), value, compare);

        if (it == best_ending.end())
            best_ending.push_back(value);
        else
            *it = value;
    }

    return int(best_ending.size());
}


const int INF = 1e9 + 5;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, K;
    cin >> N >> K;
    vector<int> A(N + 2);

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        A[i] -= i;
    }

    vector<int> B(K);

    for (auto &b : B)
        cin >> b;

    assert(is_sorted(B.begin(), B.end()));
    B.insert(B.begin(), 0);
    B.push_back(N + 1);
    A[0] = -INF;
    A[N + 1] = INF;
    int total = 0;

    for (int b = 0; b <= K; b++) {
        int start = B[b];
        int end = B[b + 1];

        if (A[start] > A[end]) {
            cout << -1 << '\n';
            return 0;
        }

        vector<int> sequence;

        for (int i = start + 1; i < end; i++)
            if (A[start] <= A[i] && A[i] <= A[end])
                sequence.push_back(A[i]);

        total += (end - start - 1) - longest_increasing_subsequence(sequence, less_equal<int>());
    }

    cout << total << '\n';
}