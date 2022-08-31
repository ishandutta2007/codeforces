#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const long long GOAL_DIST = 1.5e6;

struct xy_move {
    int x, y;
    int index;
};

int N;
vector<xy_move> moves;
vector<bool> flip;

long long get_dist(long long x, long long y) {
    return x * x + y * y;
}

bool solve() {
    long long x = 0, y = 0;

    for (xy_move m : moves) {
        long long x1 = x + m.x, y1 = y + m.y;
        long long x2 = x - m.x, y2 = y - m.y;

        if (get_dist(x1, y1) < get_dist(x2, y2)) {
            x = x1;
            y = y1;
            flip[m.index] = false;
        } else {
            x = x2;
            y = y2;
            flip[m.index] = true;
        }
    }

    return abs(x) <= GOAL_DIST && abs(y) <= GOAL_DIST && get_dist(x, y) <= GOAL_DIST * GOAL_DIST;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    scanf("%d", &N);
    moves.resize(N);
    flip.resize(N);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &moves[i].x, &moves[i].y);
        moves[i].index = i;
    }

    do {
        random_shuffle(moves.begin(), moves.end());
    } while (!solve());

    for (int i = 0; i < N; i++)
        cout << (flip[i] ? -1 : 1) << (i < N - 1 ? ' ' : '\n');

    return 0;
}