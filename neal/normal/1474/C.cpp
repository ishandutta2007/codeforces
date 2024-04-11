#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


void run_case() {
    int N;
    cin >> N;
    vector<int> A(2 * N);

    for (auto &a : A)
        cin >> a;

    sort(A.begin(), A.end());

    for (int skip = 0; skip < 2 * N; skip++) {
        vector<bool> skipped(2 * N, false);
        skipped[skip] = true;

        auto search = [&](int value) {
            int low = 0, high = 2 * N;

            while (low < high) {
                int mid = low + (high - low) / 2;

                if (A[mid] < value || (A[mid] == value && skipped[mid]))
                    low = mid + 1;
                else
                    high = mid;
            }

            return low;
        };

        int bigger = 2 * N;
        vector<array<int, 2>> pairs;

        for (int i = 2 * N - 1; i >= 0; i--) {
            if (skipped[i])
                continue;

            if (bigger == 2 * N) {
                if (i < skip)
                    break;

                pairs.push_back({A[i], A[skip]});
            } else {
                int need = A[bigger] - A[i];
                int index = search(need);

                if (index >= i || A[index] != need)
                    break;

                skipped[index] = true;
                pairs.push_back({A[index], A[i]});
            }

            bigger = i;
        }

        if (int(pairs.size()) < N)
            continue;

        cout << "YES" << '\n';
        cout << pairs.front()[0] + pairs.front()[1] << '\n';

        for (auto &pr : pairs)
            cout << pr[0] << ' ' << pr[1] << '\n';

        return;
    }

    cout << "NO" << '\n';
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