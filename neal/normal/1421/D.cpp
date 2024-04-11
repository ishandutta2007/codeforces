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


void run_case() {
    int64_t X, Y;
    array<int64_t, 6> C;
    cin >> X >> Y;

    for (auto &c : C)
        cin >> c;

    for (int i = 0; i < 6; i++)
        C[i] = min(C[i], C[(i + 5) % 6] + C[(i + 1) % 6]);

    auto rotate60 = [&] {
        int64_t new_X = Y;
        int64_t new_Y = Y - X;
        X = new_X;
        Y = new_Y;
        rotate(C.begin(), C.begin() + 1, C.end());
    };

    while (!(X >= 0 && Y >= X))
        rotate60();

    int64_t right = Y - X;
    int64_t up_right = X;
    cout << C[0] * up_right + C[1] * right << '\n';
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