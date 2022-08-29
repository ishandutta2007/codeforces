// Solution to https://codeforces.com/contest/1065/problem/D
#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int ENCODE_BITS = 15;
const int MOVE_COST = 1 << ENCODE_BITS;

const int N_MAX = 30;
const int LOC_MAX = N_MAX * N_MAX + 1;

enum chess_piece { KNIGHT = 0, BISHOP = 1, ROOK = 2 };
const vector<chess_piece> PIECES = {KNIGHT, BISHOP, ROOK};

const int KNIGHT_DIRS = 8;
const int KNIGHT_DR[] = {-2, -2, -1, -1, +1, +1, +2, +2};
const int KNIGHT_DC[] = {-1, +1, -2, +2, -2, +2, -1, +1};

struct state {
    int step, r, c;
    chess_piece piece;
    int dist;

    bool operator<(const state &other) const {
        return dist > other.dist;
    }
};

int N;
vector<pair<int, int>> locations;
int _dist[LOC_MAX][3][N_MAX][N_MAX];

int &dist(const state &s) {
    return _dist[s.step][s.piece][s.r][s.c];
}

bool valid(int r, int c) {
    return 0 <= r && r < N && 0 <= c && c < N;
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

    for (chess_piece p : PIECES)
        dijkstra_check(pq, {0, locations[0].first, locations[0].second, p, 0});

    while (!pq.empty()) {
        state current = pq.top();
        pq.pop();

        // Skip if obsolete
        if (current.dist > dist(current))
            continue;

        assert(current.dist == dist(current));

        if (current.step == N * N)
            return current.dist;

        // Moving to the next step (free)
        if (current.r == locations[current.step].first && current.c == locations[current.step].second)
            dijkstra_check(pq, {current.step + 1, current.r, current.c, current.piece, current.dist});

        // Changing pieces
        for (chess_piece p : PIECES)
            dijkstra_check(pq, {current.step, current.r, current.c, p, current.dist + MOVE_COST + 1});

        if (current.piece == KNIGHT) {
            for (int dir = 0; dir < KNIGHT_DIRS; dir++) {
                int nr = current.r + KNIGHT_DR[dir];
                int nc = current.c + KNIGHT_DC[dir];

                if (valid(nr, nc))
                    dijkstra_check(pq, {current.step, nr, nc, current.piece, current.dist + MOVE_COST});
            }
        } else if (current.piece == BISHOP) {
            for (int dr = -1; dr <= +1; dr += 2)
                for (int dc = -1; dc <= +1; dc += 2) {
                    int nr = current.r + dr;
                    int nc = current.c + dc;

                    while (valid(nr, nc)) {
                        dijkstra_check(pq, {current.step, nr, nc, current.piece, current.dist + MOVE_COST});
                        nr += dr;
                        nc += dc;
                    }
                }
        } else if (current.piece == ROOK) {
            for (int i = 0; i < N; i++) {
                dijkstra_check(pq, {current.step, current.r, i, current.piece, current.dist + MOVE_COST});
                dijkstra_check(pq, {current.step, i, current.c, current.piece, current.dist + MOVE_COST});
            }
        } else {
            assert(false);
        }
    }

    assert(false);
}

int main() {
    scanf("%d", &N);
    locations.resize(N * N);

    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++) {
            int order;
            scanf("%d", &order);
            order--;
            locations[order] = {r, c};
        }

    int answer = dijkstra();
    cout << (answer >> ENCODE_BITS) << ' ' << (answer & (MOVE_COST - 1)) << '\n';
}