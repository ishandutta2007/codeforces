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
    int N;
    cin >> N;
    vector<int> A(N);

    auto &&mex = [&] {
        vector<bool> seen(N + 1, false);

        for (auto &a : A)
            seen[a] = true;

        int x = 0;

        while (seen[x])
            x++;

        return x;
    };

    auto &&good = [&] {
        for (int i = 0; i < N; i++)
            if (A[i] != i)
                return false;

        return true;
    };

    for (auto &a : A)
        cin >> a;

    vector<int> ops;

    while (!good()) {
        int m = mex();

        if (m < N) {
            ops.push_back(m);
            A[m] = m;
        } else {
            int wrong = -1;

            for (int i = 0; i < N; i++)
                if (A[i] != i) {
                    wrong = i;
                    break;
                }

            ops.push_back(wrong);
            A[wrong] = m;
        }
    }

    assert(int(ops.size()) <= 2 * N);
    cout << ops.size() << '\n';
    output_vector(ops, true);
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