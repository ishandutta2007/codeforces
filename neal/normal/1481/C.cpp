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

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


void run_case() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(N), C(M);

    for (auto &a : A)
        cin >> a;

    for (auto &b : B)
        cin >> b;

    for (auto &c : C)
        cin >> c;

    vector<vector<int>> wants(N + 1), needs(N + 1);

    for (int i = 0; i < N; i++) {
        wants[B[i]].push_back(i);

        if (A[i] != B[i])
            needs[B[i]].push_back(i);
    }

    if (wants[C.back()].empty()) {
        cout << "NO" << '\n';
        return;
    }

    vector<int> where(M, -1);

    for (int i = M - 1; i >= 0; i--) {
        if (!needs[C[i]].empty()) {
            where[i] = needs[C[i]].back();
            needs[C[i]].pop_back();
        } else if (!wants[C[i]].empty()) {
            where[i] = wants[C[i]].back();
        } else {
            where[i] = where.back();
        }
    }

    for (int c = 0; c <= N; c++)
        if (!needs[c].empty()) {
            cout << "NO" << '\n';
            return;
        }

    cout << "YES" << '\n';
    output_vector(where, true);
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