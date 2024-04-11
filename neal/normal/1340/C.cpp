#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <queue>
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

const int M_MAX = 10005;
const int G_MAX = 1005;

struct state {
    int16_t island, gr_time;
    int dist;

    state() {}

    state(int _island, int _gr_time, int _dist) : island(_island), gr_time(_gr_time), dist(_dist) {}

    bool operator<(const state &other) const {
        return dist > other.dist;
    }
};

int N, M, G, R;
vector<int> D;
int _dist[M_MAX][G_MAX];

int &dist(const state &s) {
    return _dist[s.island][s.gr_time];
}

void dijkstra_check(priority_queue<state> &pq, const state &s) {
    if (s.dist < dist(s)) {
        dist(s) = s.dist;
        pq.push(s);
    }
}

int dijkstra() {
    memset(_dist, 63, sizeof(_dist));
    priority_queue<state> pq;
    dijkstra_check(pq, state(0, 0, 0));

    while (!pq.empty()) {
        state top = pq.top();
        pq.pop();

        // Skip if obsolete.
        if (top.dist > dist(top))
            continue;

        assert(top.dist == dist(top));

        if (top.island == M)
            return top.dist;

        if (top.gr_time >= G) {
            dijkstra_check(pq, state(top.island, 0, top.dist + G + R - top.gr_time));
            continue;
        }

        if (top.island > 0) {
            int gap = D[top.island] - D[top.island - 1];

            if (top.gr_time + gap <= G)
                dijkstra_check(pq, state(top.island - 1, top.gr_time + gap, top.dist + gap));
        }

        if (top.island < M) {
            int gap = D[top.island + 1] - D[top.island];

            if (top.gr_time + gap <= G)
                dijkstra_check(pq, state(top.island + 1, top.gr_time + gap, top.dist + gap));
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    cin >> N >> M;
    M--;
    D.resize(M + 1);

    for (auto &d : D)
        cin >> d;

    sort(D.begin(), D.end());
    cin >> G >> R;
    cout << dijkstra() << '\n';
}