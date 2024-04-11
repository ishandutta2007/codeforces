#include <algorithm>
#include <array>
#include <cassert>
#include <iomanip>
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


const int BINARY_SEARCH_ITERS = 60;

void run_case() {
    int N, L;
    cin >> N >> L;
    vector<int> A(N + 2);

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    A[0] = 0;
    A[N + 1] = L;

    auto meet = [&](double time) {
        double original = time;
        double x = 0;
        double speed = 1;

        for (int i = 1; i <= N + 1; i++)
            if ((A[i] - x) / speed <= time) {
                time -= (A[i] - x) / speed;
                x = A[i];
                speed++;
            } else {
                x += speed * time;
                break;
            }

        time = original;
        double y = L;
        speed = 1;

        for (int i = N; i >= 0; i--)
            if ((y - A[i]) / speed <= time) {
                time -= (y - A[i]) / speed;
                y = A[i];
                speed++;
            } else {
                y -= speed * time;
                break;
            }

        dbg(time, x, y);
        return x >= y;
    };

    double low = 0, high = L / 2;

    for (int iter = 0; iter < BINARY_SEARCH_ITERS; iter++) {
        double mid = (low + high) / 2;

        if (meet(mid))
            high = mid;
        else
            low = mid;
    }

    cout << low << '\n';
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    cout << setprecision(12);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}