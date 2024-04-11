#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M;
    cin >> N >> M;
    vector<int> lengths(M);
    int64_t sum = 0;

    for (int &len : lengths) {
        cin >> len;
        sum += len;
    }

    if (sum < N) {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 0; i < M; i++)
        if (lengths[i] > N - i) {
            cout << -1 << '\n';
            return 0;
        }

    vector<int64_t> suffix_sum(M + 1, 0);

    for (int i = M - 1; i >= 0; i--)
        suffix_sum[i] = suffix_sum[i + 1] + lengths[i];

    int position = 0;

    for (int i = 0; i < M; i++) {
        while (position + suffix_sum[i] < N)
            position++;

        cout << position + 1 << (i < M - 1 ? ' ' : '\n');
        position++;
    }
}