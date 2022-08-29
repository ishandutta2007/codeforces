#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int DY[] = {1, 0, -1, 0};
const int DX[] = {0, 1, 0, -1};
const int UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3;

struct position {
    int x, y;

    position(int _x = -1, int _y = -1) : x(_x), y(_y) {}

    bool operator<(const position &other) const {
        return make_pair(y, x) < make_pair(other.y, other.x);
    }

    position move(int direction) const {
        return position(x + DX[direction], y + DY[direction]);
    }
};

struct cube_move {
    int x1, y1, x2, y2;

    cube_move(int _x1 = -1, int _y1 = -1, int _x2 = -1, int _y2 = -1) : x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}

    cube_move(const position &p1, const position &p2) {
        x1 = p1.x;
        y1 = p1.y;
        x2 = p2.x;
        y2 = p2.y;
    }
};

int N, M;

bool valid(int x, int y) {
    return x >= 1 && x <= N && y >= 1 && y <= N;
}

bool can_move(const vector<position> &positions, int index, int direction) {
    int nx = positions[index].x + DX[direction];
    int ny = positions[index].y + DY[direction];

    if (!valid(nx, ny))
        return false;

    for (const position &p : positions)
        if (p.x == nx && p.y == ny)
            return false;

    return true;
}

bool try_move(vector<position> &positions, int index, int direction, vector<cube_move> &moves) {
    if (can_move(positions, index, direction)) {
        position next_position = positions[index].move(direction);
        moves.emplace_back(positions[index], next_position);
        positions[index] = next_position;
        return true;
    }

    return false;
}

void make_diagonal(vector<position> &positions, vector<cube_move> &moves) {
    vector<int> goal(M, -1);

    for (int m = M; m > 0; m--) {
        position down(-1, -1);
        int down_index = -1;

        for (int i = 0; i < M; i++)
            if (goal[i] == -1 && down < positions[i]) {
                down = positions[i];
                down_index = i;
            }

        assert(down_index != -1);
        goal[down_index] = m;
    }

    bool done;

    do {
        done = true;

        for (int i = 0; i < M; i++)
            if (positions[i].y != goal[i]) {
                done = false;
                int direction = goal[i] > positions[i].y ? UP : DOWN;
                try_move(positions, i, direction, moves);
            }
    } while (!done);

    for (int i = 0; i < M; i++)
        while (positions[i].x != goal[i]) {
            int direction = goal[i] > positions[i].x ? RIGHT : LEFT;
            bool move_success = try_move(positions, i, direction, moves);
            assert(move_success);
        }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    vector<position> cubes(M), goals(M);
    vector<cube_move> moves, reverse_moves;

    for (int i = 0; i < M; i++)
        cin >> cubes[i].x >> cubes[i].y;

    for (int i = 0; i < M; i++)
        cin >> goals[i].x >> goals[i].y;

    make_diagonal(cubes, moves);
    make_diagonal(goals, reverse_moves);

    for (int i = 0; i < M; i++)
        while (cubes[i].x != goals[i].x) {
            int direction = goals[i].x > cubes[i].x ? RIGHT : LEFT;
            bool move_success = try_move(cubes, i, direction, moves);
            assert(move_success);
        }

    for (int i = 0; i < M; i++)
        while (cubes[i].y != goals[i].y) {
            int direction = goals[i].y > cubes[i].y ? UP : DOWN;
            bool move_success = try_move(cubes, i, direction, moves);
            assert(move_success);
        }

    reverse(reverse_moves.begin(), reverse_moves.end());
    cout << moves.size() + reverse_moves.size() << '\n';

    for (cube_move &m : moves)
        cout << m.x1 << ' ' << m.y1 << ' ' << m.x2 << ' ' << m.y2 << '\n';

    for (cube_move &m : reverse_moves)
        cout << m.x2 << ' ' << m.y2 << ' ' << m.x1 << ' ' << m.y1 << '\n';

    return 0;
}