#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


const int A_MAX = 205;

void run_case() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<vector<int>> locations(A_MAX);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        locations[A[i]].push_back(i);
    }

    int best = 0;

    for (int a = 0; a < A_MAX; a++)
        best = max(best, (int) locations[a].size());

    for (int outer = 0; outer < A_MAX; outer++) {
        vector<int> freq(A_MAX, 0);
        int maximum = 0;

        auto &&add = [&](int a) {
            freq[a]++;
            maximum = max(maximum, freq[a]);
        };

        int size = locations[outer].size();

        if (size < 2)
            continue;

        for (int count = size / 2; count > 0; count--) {
            int a = locations[outer][count - 1];
            int a1 = locations[outer][count];
            int b = locations[outer][size - count];
            int b1 = locations[outer][size - count - 1];

            for (int i = a + 1; i < a1; i++)
                add(A[i]);

            if (a1 != b) {
                for (int i = b1; i < b; i++)
                    add(A[i]);
            }

            best = max(best, 2 * count + maximum);
        }
    }

    cout << best << '\n';
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