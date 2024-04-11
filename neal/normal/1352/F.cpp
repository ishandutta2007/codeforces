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


void run_case() {
    int N0, N1, N2;
    cin >> N0 >> N1 >> N2;

    if (N1 == 0) {
        assert(N0 == 0 || N2 == 0);

        if (N0 != 0)
            cout << string(N0 + 1, '0') << '\n';
        else
            cout << string(N2 + 1, '1') << '\n';

        return;
    }

    string ans = string(N0 + 1, '0') + string(N2 + 1, '1');

    while (N1 > 1) {
        ans += '0' + '1' - ans.back();
        N1--;
    }

    cout << ans << '\n';
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