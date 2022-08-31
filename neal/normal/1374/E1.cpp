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


const int64_t INF64 = int64_t(2e18) + 5;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, K;
    cin >> N >> K;
    vector<int> A, B, both;

    for (int i = 0; i < N; i++) {
        int t, a, b;
        cin >> t >> a >> b;

        if (a + b == 2)
            both.push_back(t);
        else if (a == 1)
            A.push_back(t);
        else if (b == 1)
            B.push_back(t);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(both.begin(), both.end());
    int64_t best = INF64;
    int64_t sum = 0;

    vector<int64_t> A_sum(A.size() + 1, 0);
    vector<int64_t> B_sum(B.size() + 1, 0);

    for (int i = 0; i < int(A.size()); i++)
        A_sum[i + 1] = A_sum[i] + A[i];

    for (int i = 0; i < int(B.size()); i++)
        B_sum[i + 1] = B_sum[i] + B[i];

    for (int x = 0; x <= int(both.size()); x++) {
        if (x > 0)
            sum += both[x - 1];

        int need = K - x;

        if (need >= 0 && int(A.size()) >= need && int(B.size()) >= need)
            best = min(best, sum + A_sum[need] + B_sum[need]);
    }

    cout << (best < INF64 ? best : -1) << '\n';
}