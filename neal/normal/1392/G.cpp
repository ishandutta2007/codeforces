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


const int INF = 1e9 + 5;

int read_string() {
    int mask = 0;
    string str;
    cin >> str;

    for (int i = 0; i < int(str.size()); i++)
        mask |= (str[i] - '0') << i;

    return mask;
}

int swap_bits(int mask, int a, int b) {
    int diff = (mask >> a & 1) ^ (mask >> b & 1);
    return mask ^ (diff << a) ^ (diff << b);
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M, K;
    cin >> N >> M >> K;
    int S = read_string(), T = read_string();
    int ones = __builtin_popcount(S) + __builtin_popcount(T);
    vector<int> location(K);

    for (int k = 0; k < K; k++)
        location[k] = k;

    vector<int> earliest(1 << K, INF);
    vector<int> latest(1 << K, -INF);
    earliest[S] = latest[T] = 0;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        swap(location[a], location[b]);
        S = swap_bits(S, location[a], location[b]);
        T = swap_bits(T, location[a], location[b]);
        earliest[S] = min(earliest[S], i + 1);
        latest[T] = max(latest[T], i + 1);
    }

    for (int bit = 0; bit < K; bit++)
        for (int mask = 0; mask < 1 << K; mask++)
            if ((mask >> bit & 1) == 0) {
                earliest[mask] = min(earliest[mask], earliest[mask | 1 << bit]);
                latest[mask] = max(latest[mask], latest[mask | 1 << bit]);
            }

    int most = -1, early = -1, late = -1;

    for (int mask = 0; mask < 1 << K; mask++)
        if (__builtin_popcount(mask) > most && latest[mask] - earliest[mask] >= M) {
            most = __builtin_popcount(mask);
            early = earliest[mask];
            late = latest[mask];
        }

    int answer = most + K - (ones - most);
    cout << answer << '\n';
    cout << early + 1 << ' ' << late << '\n';
}