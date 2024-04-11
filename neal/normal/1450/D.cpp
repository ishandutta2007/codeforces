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
    vector<int> A(N);

    for (auto &a : A)
        cin >> a;

    vector<int> freq(N + 1, 0);

    for (auto &a : A)
        freq[a]++;

    vector<bool> answer(N + 1, false);
    answer[N] = *min_element(A.begin(), A.end()) == 1;

    vector<int> sorted = A;
    sort(sorted.begin(), sorted.end());
    answer[1] = true;

    for (int i = 0; i < N; i++)
        if (sorted[i] != i + 1)
            answer[1] = false;

    int first = 0, last = N - 1, current = 0;

    while (first <= last && min(A[first], A[last]) == current + 1) {
        if (A[first] == current + 1)
            first++;
        else
            last--;

        current++;

        if (freq[current] > 1)
            break;
    }

    if (freq[current] <= 1 && first <= last && *min_element(A.begin() + first, A.begin() + last + 1) == current + 1)
        current++;

    for (int i = N + 1 - current; i < N; i++)
        answer[i] = true;

    for (int i = 1; i <= N; i++)
        cout << answer[i];

    cout << '\n';
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