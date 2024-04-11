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


const int INF = 1e9 + 5;
const int S_MAX = 5e5 + 5;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N;
    cin >> N;
    vector<array<int, 2>> counts(N);

    for (int i = 0; i < N; i++) {
        counts[i] = {0, 0};
        string S;
        cin >> S;

        for (auto &ch : S)
            counts[i][ch == 'N']++;
    }

    sort(counts.begin(), counts.end());
    dbg(counts);

    auto &&has_intersection = [&](pair<int, int> p1, pair<int, int> p2) {
        return max(p1.first, p2.first) <= min(p1.second, p2.second);
    };

    int min_x, max_x, min_y, max_y, min_xy, max_xy;

    auto &&possible = [&](int distance) {
        min_x = -INF; max_x = INF;
        min_y = -INF; max_y = INF;
        min_xy = -INF; max_xy = INF;

        for (auto &count : counts) {
            int x = count[0];
            int y = count[1];

            min_x = max(min_x, x - distance);
            max_x = min(max_x, x + distance);

            min_y = max(min_y, y - distance);
            max_y = min(max_y, y + distance);

            min_xy = max(min_xy, x - y - distance);
            max_xy = min(max_xy, x - y + distance);
        }

        if (min_x > max_x || min_y > max_y || min_xy > max_xy)
            return false;

        return has_intersection({min_x - max_y, max_x - min_y}, {min_xy, max_xy});
    };

    int low = 0, high = 2 * S_MAX;

    while (low < high) {
        int mid = (low + high) / 2;

        if (possible(mid))
            high = mid;
        else
            low = mid + 1;
    }

    possible(low);
    int x = min_x, y = max_y;

    while (x - y < min_xy) {
        if (x < max_x)
            x++;
        else
            y--;
    }

    cout << low << '\n';
    cout << string(x, 'B') << string(y, 'N') << '\n';

    // for (auto &count : counts) {
    //     int d1 = x - count[0];
    //     int d2 = y - count[1];
    //     assert(max({abs(d1), abs(d2), abs(d1 - d2)}) <= low);
    // }
}