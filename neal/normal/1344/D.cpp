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

template<typename T>
void output_vector(const vector<T> &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = v.size();

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


const int64_t INF64 = (int64_t) 4e18 + 5;

int64_t N, K;
vector<int64_t> A, B;

int64_t evaluate(int64_t cutoff) {
    int64_t total = 0;

    for (int i = 0; i < N; i++) {
        int64_t low = 0, high = A[i];

        while (low < high) {
            int64_t mid = (low + high) / 2;

            if (A[i] - (3 * mid * mid + 3 * mid + 1) >= cutoff)
                low = mid + 1;
            else
                high = mid;
        }

        B[i] = low;
        total += B[i];
    }

    return total;
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    cin >> N >> K;
    A.resize(N);

    for (auto &a : A)
        cin >> a;

    B.assign(N, 0);
    int64_t low = -INF64, high = INF64;

    while (low < high) {
        int64_t mid = (low + high + 1) / 2;

        if (evaluate(mid) >= K)
            low = mid;
        else
            high = mid - 1;
    }

    int64_t out = evaluate(low);
    int64_t extra = out - K;

    for (int i = 0; i < N; i++)
        if (B[i] > 0 && A[i] - (3 * (B[i] - 1) * (B[i] - 1) + 3 * (B[i] - 1) + 1) == low && extra > 0) {
            B[i]--;
            extra--;
        }

    output_vector(B);
}