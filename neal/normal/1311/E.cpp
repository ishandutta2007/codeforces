#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):"; dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


int compute_maximum(int n) {
    return n * (n - 1) / 2;
}

int compute_minimum(int n) {
    int sum = 0;

    for (int depth = 0; 1 << depth <= n; depth++) {
        int count = min(n - (1 << depth) + 1, 1 << depth);
        sum += count * depth;
    }

    return sum;
}

bool in_range(int x, int low, int high) {
    return low <= x && x <= high;
}

bool possible(int n, int d) {
    return in_range(d, compute_minimum(n), compute_maximum(n));
}

vector<int> P;

void construct(int n, int d, int root, int parent) {
    dbg(n, d, root, parent);

    if (n <= 0)
        return;

    assert(possible(n, d));
    P[root] = parent;

    for (int left = 0; left <= n / 2; left++) {
        int right = n - 1 - left;
        int left_min = left + compute_minimum(left), left_max = left + compute_maximum(left);
        int right_min = right + compute_minimum(right), right_max = right + compute_maximum(right);

        int LD = -1, RD = -1;

        if (in_range(d - left_min, right_min, right_max)) {
            LD = left_min;
            RD = d - LD;
        } else if (in_range(d - left_max, right_min, right_max)) {
            LD = left_max;
            RD = d -LD;
        } else if (in_range(d - right_min, left_min, left_max)) {
            RD = right_min;
            LD = d - RD;
        } else if (in_range(d - right_max, left_min, left_max)) {
            RD = right_max;
            LD = d - RD;
        }

        if (LD >= 0) {
            construct(left, LD - left, root + 1, root);
            construct(right, RD - right, root + left + 1, root);
            return;
        }
    }

    assert(false);
}

void run_case() {
    int N, D;
    cin >> N >> D;

    if (!possible(N, D)) {
        cout << "NO" << '\n';
        return;
    }

    P.assign(N + 1, -1);
    construct(N, D, 1, -1);

    cout << "YES" << '\n';

    for (int i = 2; i <= N; i++)
        cout << P[i] << (i < N ? ' ' : '\n');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}