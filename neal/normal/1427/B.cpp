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

void run_case() {
    int N, K;
    string S;
    cin >> N >> K >> S;
    vector<int> L_count(N, INF);

    for (int i = 0, j = 0; i < N; i = j) {
        while (j < N && S[i] == S[j])
            j++;

        if (S[i] == 'L' && i != 0 && j != N) {
            for (int k = i; k < j; k++)
                L_count[k] = j - i;
        }
    }

    vector<int> L_indices;

    for (int i = 0; i < N; i++)
        if (S[i] == 'L')
            L_indices.push_back(i);

    int first_cutoff = 0;

    while (first_cutoff < N && S[first_cutoff] == 'L')
        first_cutoff++;

    sort(L_indices.begin(), L_indices.end(), [&](int a, int b) {
        if (a < first_cutoff && b < first_cutoff)
            return a > b;

        return make_pair(L_count[a], a) < make_pair(L_count[b], b);
    });

    K = min(K, int(L_indices.size()));

    for (int i = 0; i < K; i++)
        S[L_indices[i]] = 'W';

    dbg(S);
    int answer = 0;

    for (int i = 0; i < N; i++)
        if (S[i] == 'W') {
            answer++;
            answer += i > 0 && S[i - 1] == 'W';
        }

    cout << answer << '\n';
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