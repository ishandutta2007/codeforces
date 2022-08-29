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

template<typename T>
void output_vector(const vector<T> &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


const int INF = 1e9 + 5;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, H, M, K;
    cin >> N >> H >> M >> K;
    K--;

    vector<int> trains(N);

    for (int i = 0; i < N; i++) {
        int h;
        cin >> h >> trains[i];
    }

    vector<int> original = trains;
    sort(trains.begin(), trains.end());

    for (int i = 0; i < N; i++)
        trains.push_back(M + trains[i]);

    auto &&count_between = [&](int start, int end) {
        return int(lower_bound(trains.begin(), trains.end(), end) - lower_bound(trains.begin(), trains.end(), start));
    };

    int best = INF;
    int best_t = -1;

    for (int i = 0; i < N; i++) {
        int candidate = (trains[i] + 1) % (M / 2);
        int bad = count_between(candidate, candidate + K) + count_between(candidate + M / 2, candidate + M / 2 + K);

        if (bad < best) {
            best = bad;
            best_t = candidate;
        }
    }

    vector<int> cancel;

    for (int i = 0; i < N; i++)
        if ((best_t <= original[i] && original[i] < best_t + K) ||
            (best_t + M / 2 <= original[i] && original[i] < best_t + M / 2 + K) ||
            (best_t + M / 2 <= M + original[i] && M + original[i] < best_t + M / 2 + K))
            cancel.push_back(i);

    assert(int(cancel.size()) == best);
    cout << best << ' ' << (best_t + K) % (M / 2) << '\n';
    output_vector(cancel, true);
}