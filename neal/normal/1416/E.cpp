#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T> ostream& operator<<(ostream &os, const set<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


const int64_t INF64 = int64_t(2e18) + 5;

void run_case() {
    int64_t b_low = -INF64, b_high = -INF64;
    set<int64_t> points;
    int64_t sign = 1, offset = 0;
    int answer = 0;

    auto transform = [&](int64_t x) {
        return (x - offset) * sign;
    };

    auto contains = [&](int64_t x) {
        if (b_low <= x && x <= b_high)
            return true;

        return points.find(transform(x)) != points.end();
    };

    auto insert = [&](int64_t x) {
        x = transform(x);
        points.insert(x);
    };

    auto clear = [&] {
        b_low = b_high = -INF64;
        points.clear();
        sign = 1;
        offset = 0;
    };

    auto overlaps_segment = [&](int64_t low, int64_t high) {
        if (max(low, b_low) <= min(high, b_high))
            return true;

        low = transform(low);
        high = transform(high);

        if (low > high)
            swap(low, high);

        auto it = points.lower_bound(low);
        return it != points.end() && *it <= high;
    };

    auto biggest_point = [&] {
        return sign > 0 ? prev(points.end()) : points.begin();
    };

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int64_t a;
        cin >> a;
        int64_t half = a % 2 == 0 ? a / 2 : -1;

        if (half >= 0 && contains(half)) {
            clear();
            insert(half);
        } else if (half >= 0 || overlaps_segment(1, a - 1)) {
            while (!points.empty() && *biggest_point() * sign + offset > a - 1)
                points.erase(biggest_point());

            if (b_high >= 0) {
                b_high = min(b_high, a - 1);
                b_low = a - b_low;
                b_high = a - b_high;
                swap(b_low, b_high);
            }

            sign *= -1;
            offset = a - offset;

            if (half >= 0)
                insert(half);

            answer++;
        } else {
            clear();
            b_low = 1;
            b_high = a - 1;
            answer += 2;
        }
    }

    cout << answer << '\n';
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