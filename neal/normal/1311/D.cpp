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


const int MAX = 2e4 + 5;
const int INF = 1e9 + 5;

void run_case() {
    int A, B, C;
    cin >> A >> B >> C;
    int best = INF;
    int best_a = -1, best_b = -1, best_c = -1;

    for (int a = 1; a <= MAX; a++)
        for (int b = a; b <= MAX; b += a) {
            int cost = abs(a - A) + abs(b - B);

            if (cost < best) {
                int c = (C + b / 2) / b * b;
                cost += abs(c - C);

                if (cost < best) {
                    best = cost;
                    best_a = a;
                    best_b = b;
                    best_c = c;
                }
            }
        }

    cout << best << '\n';
    cout << best_a << ' ' << best_b << ' ' << best_c << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}