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

template<typename T>
void output_vector(const vector<T> &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


void run_case() {
    int N, X, Y;
    cin >> N >> X >> Y;
    vector<int> B(N);
    vector<int> freq(N + 2, 0);

    for (auto &b : B) {
        cin >> b;
        freq[b]++;
    }

    vector<vector<int>> locations(N + 2);

    for (int i = 0; i < N; i++)
        locations[B[i]].push_back(i);

    int special = 1;

    while (freq[special] != 0)
        special++;

    dbg(special);
    vector<int> A(N, -1);

    vector<vector<int>> freq_list(N + 1);

    for (int b = 1; b <= N + 1; b++)
        freq_list[freq[b]].push_back(b);

    int most = N;

    for (int iter = 0; iter < X; iter++) {
        while (freq_list[most].empty())
            most--;

        assert(most > 0);
        int b = freq_list[most].back();
        freq_list[most].pop_back();
        freq_list[most - 1].push_back(b);
        A[locations[b][most - 1]] = b;
    }

    dbg(A);
    vector<pair<int, int>> remaining;

    for (int i = 0; i < N; i++)
        if (A[i] < 0)
            remaining.emplace_back(B[i], i);

    sort(remaining.begin(), remaining.end());
    int R = int(remaining.size());
    assert(R == N - X);
    int majority = -1;
    int maj_start = -1, maj_end = -1;

    for (int i = 0, j = 0; i < R; i = j) {
        while (j < R && remaining[i].first == remaining[j].first)
            j++;

        if (j - i > majority) {
            majority = j - i;
            maj_start = i;
            maj_end = j;
        }
    }

    if (2 * majority > R) {
        int goal = R - majority;
        remaining.erase(remaining.begin() + maj_start + goal, remaining.begin() + maj_end);
        R = 2 * goal;
    }

    int need = Y - X;

    if (R < need) {
        cout << "NO" << '\n';
        return;
    }

    for (int i = 0; i < R; i++) {
        int other = (i + R / 2) % R;
        assert(remaining[i].first != remaining[other].first);
        if (need-- > 0) A[remaining[i].second] = remaining[other].first;
    }

    for (int i = 0; i < N; i++)
        if (A[i] < 0)
            A[i] = special;

    cout << "YES" << '\n';
    output_vector(A);
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