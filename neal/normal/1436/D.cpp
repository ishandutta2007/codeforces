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


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N;
    cin >> N;
    vector<int> parent(N, -1);
    vector<vector<int>> children(N);

    for (int i = 1; i < N; i++) {
        cin >> parent[i];
        parent[i]--;
        children[parent[i]].push_back(i);
    }

    vector<int64_t> A(N);

    for (auto &a : A)
        cin >> a;

    vector<int64_t> people = A;
    vector<int> leaves(N, 0);
    int64_t answer = 0;

    for (int i = N - 1; i >= 0; i--) {
        for (int child : children[i]) {
            people[i] += people[child];
            leaves[i] += leaves[child];
        }

        leaves[i] += children[i].empty();
        answer = max(answer, (people[i] + leaves[i] - 1) / leaves[i]);
    }

    cout << answer << '\n';
}