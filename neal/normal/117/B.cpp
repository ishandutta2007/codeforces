#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <iomanip>
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


const int BASE = 1e9;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int A, B, MOD;
    cin >> A >> B >> MOD;

    if (B + 1 >= MOD) {
        cout << 2 << '\n';
        return 0;
    }

    for (int x = 0; x <= min(A, MOD + 5); x++) {
        int64_t start = BASE * x;
        int start_mod = start % MOD;

        if (start_mod > 0 && start_mod + B < MOD) {
            cout << 1 << ' ' << setw(9) << setfill('0') << x << '\n';
            return 0;
        }
    }

    cout << 2 << '\n';
}