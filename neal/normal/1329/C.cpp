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

template<typename T>
void output_vector(const vector<T> &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = v.size();

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


int N, H, G;
vector<int64_t> A;
vector<int> moves;

bool take(int x, bool dry_run) {
    if (A[2 * x] == 0 && A[2 * x + 1] == 0) {
        if (!dry_run)
            A[x] = 0;

        return x >= 1 << G;
    }

    if (A[2 * x] > A[2 * x + 1]) {
        if (!dry_run)
            A[x] = A[2 * x];

        return take(2 * x, dry_run);
    } else {
        if (!dry_run)
            A[x] = A[2 * x + 1];

        return take(2 * x + 1, dry_run);
    }
}

int64_t solve(int x) {
    if (A[x] == 0)
        return 0;

    int64_t ans = 0;

    while (take(x, true)) {
        ans += A[x];
        moves.push_back(x);
        take(x, false);
    }

    return ans + solve(2 * x) + solve(2 * x + 1);
}

void run_case() {
    cin >> H >> G;
    N = (1 << H) - 1;
    A.assign(2 * (N + 1), 0);
    int64_t sum = 0;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        sum += A[i];
    }

    moves.clear();
    int64_t answer = solve(1);
    cout << sum - answer << '\n';
    output_vector(moves);
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