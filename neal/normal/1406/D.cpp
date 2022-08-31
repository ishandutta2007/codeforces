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

int64_t ceil_div(int64_t a, int64_t b) {
    return a / b + ((a ^ b) > 0 && a % b != 0);
}


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N;
    cin >> N;
    vector<int> A(N);

    for (auto &a : A)
        cin >> a;

    vector<int64_t> diffs(N - 1);
    int64_t diff_sum = 0;

    for (int i = 0; i < N - 1; i++) {
        diffs[i] = A[i + 1] - A[i];
        diff_sum += min(diffs[i], INT64_C(0));
    }

    int64_t a_back = A.back();

    auto &&update = [&](int index, int add) {
        diff_sum -= min(diffs[index], INT64_C(0));
        diffs[index] += add;
        diff_sum += min(diffs[index], INT64_C(0));
    };

    auto &&query = [&] {
        return ceil_div(a_back - diff_sum, 2);
    };

    cout << query() << '\n';
    int Q;
    cin >> Q;

    for (int q = 0; q < Q; q++) {
        int L, R, X;
        cin >> L >> R >> X;
        L--;
        if (L > 0) update(L - 1, X);
        if (R < N) update(R - 1, -X);
        if (R == N) a_back += X;
        cout << query() << '\n';
    }
}