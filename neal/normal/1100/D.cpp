#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int BOARD = 999;
const int HALF = (BOARD + 1) / 2;
const int ROOKS = 666;

int X, Y;
pair<int, int> rooks[ROOKS];
bool has_rook[BOARD + 1][BOARD + 1];

void make_move(int x, int y) {
    static int queries = 0;
    assert(queries++ < 2000);
    assert(max(abs(X - x), abs(Y - y)) == 1);
    assert(1 <= x && x <= BOARD && 1 <= y && y <= BOARD);

    if (has_rook[x][y]) {
        x = X;
        assert(!has_rook[x][y]);
    }

    X = x; Y = y;
    cout << x << ' ' << y << endl;

    int k;
    cin >> k >> x >> y;

    if (k <= 0 || x <= 0 || y <= 0)
        exit(0);

    k--;
    has_rook[rooks[k].first][rooks[k].second] = false;
    rooks[k] = {x, y};
    has_rook[rooks[k].first][rooks[k].second] = true;
}

int sign(int x) {
    return x == 0 ? 0 : (x < 0 ? -1 : +1);
}

int main() {
    cin >> X >> Y;

    for (int i = 0; i < ROOKS; i++) {
        cin >> rooks[i].first >> rooks[i].second;
        has_rook[rooks[i].first][rooks[i].second] = true;
    }

    while (X != HALF || Y != HALF)
        make_move(X + sign(HALF - X), Y + sign(HALF - Y));

    int counts[2][2] = {{ROOKS, ROOKS}, {ROOKS, ROOKS}};

    for (int i = 0; i < ROOKS; i++)
        counts[rooks[i].first < HALF][rooks[i].second < HALF]--;

    int max_x = 0, max_y = 0;

    for (int x = 0; x < 2; x++)
        for (int y = 0; y < 2; y++)
            if (counts[x][y] > counts[max_x][max_y]) {
                max_x = x;
                max_y = y;
            }

    while (true)
        make_move(X + (max_x ? +1 : -1), Y + (max_y ? +1 : -1));
}