#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


int64_t choose3(int64_t n) {
    return n < 0 ? 0 : n * (n - 1) * (n - 2) / 6;
}

int main() {
    int64_t A, B, C, D;
    cin >> A >> B >> C >> D;
    int64_t goal = B - 1;
    array<int64_t, 3> constraints = {B - A, C - B, D - C};

    // Let a = B - x, b = C - y, c = z - C.
    // How many ways are there to select 0 <= a <= B - A, 0 <= b <= C - B, 0 <= c <= D - C such that a + b + c <= goal?
    int64_t answer = 0;

    for (int mask = 0; mask < 1 << 3; mask++) {
        int64_t sum = goal;

        for (int i = 0; i < 3; i++)
            if (mask >> i & 1)
                sum -= constraints[i] + 1;

        answer += (__builtin_popcount(mask) % 2 == 0 ? 1 : -1) * choose3(sum + 3);
    }

    cout << answer << '\n';
}