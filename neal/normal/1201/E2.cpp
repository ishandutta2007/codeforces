#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

const int DIRS = 8;
const int DR[] = {-2, -2, -1, -1, +1, +1, +2, +2};
const int DC[] = {-1, +1, -2, +2, -2, +2, -1, +1};

const int INF = 1e9 + 5;

bool valid(int r, int c, int R, int C) {
    return 0 <= r && r < R && 0 <= c && c < C;
}

void bfs_check(queue<pair<int, int>> &q, vector<vector<int>> &dist, int r, int c, int current_dist) {
    if (current_dist < dist[r][c]) {
        dist[r][c] = current_dist;
        q.emplace(r, c);
    }
}

void grid_bfs(int R, int C, int source_r, int source_c, vector<vector<int>> &dist) {
    queue<pair<int, int>> q;
    dist.assign(R, vector<int>(C, INF));
    bfs_check(q, dist, source_r, source_c, 0);

    while (!q.empty()) {
        pair<int, int> top = q.front(); q.pop();
        int r = top.first, c = top.second;

        for (int dir = 0; dir < DIRS; dir++) {
            int nr = r + DR[dir];
            int nc = c + DC[dir];

            if (valid(nr, nc, R, C))
                bfs_check(q, dist, nr, nc, dist[r][c] + 1);
        }
    }
}

int knight_distance(int R, int C, int R1, int C1, int R2, int C2) {
    assert(valid(R1, C1, R, C));
    assert(valid(R2, C2, R, C));

    if (R > C) {
        swap(R, C);
        swap(R1, C1);
        swap(R2, C2);
    }

    if (R == 1)
        return C1 == C2 ? 0 : INF;

    if (R == 2) {
        int difference = abs(C1 - C2);

        if (difference % 2 != 0 || abs(R1 - R2) % 2 != (difference / 2) % 2)
            return INF;

        return difference / 2;
    }

    static const int BFS_BUFFER = 3;
    static const int MAX_BFS = 8;
    static vector<vector<int>> dist[MAX_BFS + 1][MAX_BFS + 1][MAX_BFS + 1][MAX_BFS + 1];

    int RD = abs(R1 - R2);
    int CD = abs(C1 - C2);
    int combined = RD + CD;

    if (RD <= BFS_BUFFER && CD <= BFS_BUFFER && combined < 2 * BFS_BUFFER) {
        int R_low = max(0, min(R1, R2) - (BFS_BUFFER - 1));
        int C_low = max(0, min(C1, C2) - (BFS_BUFFER - 1));
        int R_high = min(R, max(R1, R2) + BFS_BUFFER);
        int C_high = min(C, max(C1, C2) + BFS_BUFFER);

        R1 -= R_low;
        R2 -= R_low;
        C1 -= C_low;
        C2 -= C_low;
        R = R_high - R_low;
        C = C_high - C_low;

        if (R1 >= (R + 1) / 2) {
            // Reflect the rows.
            R1 = R - 1 - R1;
            R2 = R - 1 - R2;
        }

        if (C1 >= (C + 1) / 2) {
            // Reflect the columns.
            C1 = C - 1 - C1;
            C2 = C - 1 - C2;
        }

        if (R > C) {
            swap(R, C);
            swap(R1, C1);
            swap(R2, C2);
        }

        assert(R < MAX_BFS && C <= MAX_BFS);
        assert(R1 < (R + 1) / 2 && C1 < (C + 1) / 2);

        if (dist[R][C][R1][C1].empty())
            grid_bfs(R, C, R1, C1, dist[R][C][R1][C1]);

        return dist[R][C][R1][C1][R2][C2];
    }

    int answer = max({(RD + 1) / 2, (CD + 1) / 2, (combined + 2) / 3});

    if (answer % 2 != combined % 2)
        answer++;

    return answer;
}


const string COLORS[2] = {"WHITE", "BLACK"};

int N, M;

int get_dist(int goal, int r, int c) {
    int goal_r = goal == 0 ? N / 2 : N / 2 + 1;
    int goal_c = M / 2;
    return knight_distance(N, M, goal_r - 1, goal_c - 1, r - 1, c - 1);
}

void output(int r, int c) {
    cout << r << ' ' << c << endl;
}

int winner(int R[2], int C[2], int turn) {
    int right = turn, wrong = 1 - turn;

    // Determine who has the right parity.
    if ((R[0] + C[0]) % 2 == (R[1] + C[1]) % 2)
        swap(right, wrong);

    int wrong_to_wrong = get_dist(wrong, R[wrong], C[wrong]);
    int right_to_right = get_dist(right, R[right], C[right]) + (wrong == 0 ? 1 : 0);
    int right_to_wrong = get_dist(wrong, R[right], C[right]) - (wrong == 1 ? 1 : 0);

    if (wrong_to_wrong < min(right_to_right, right_to_wrong))
        return wrong;

    return right;
}

int main() {
    ios::sync_with_stdio(false);

    int R[2], C[2];
    cin >> N >> M >> R[0] >> C[0] >> R[1] >> C[1];

    int me = winner(R, C, 0);
    int other = 1 - me;
    cout << COLORS[me] << endl;

    for (int turn = 0; get_dist(me, R[me], C[me]) > 0; turn = 1 - turn) {
        if (turn != me) {
            cin >> R[other] >> C[other];
            continue;
        }

        int start_r = R[me], start_c = C[me];
        int best_r = 0, best_c = 0, best_dist = INF;

        for (int dir = 0; dir < DIRS; dir++) {
            int nr = start_r + DR[dir];
            int nc = start_c + DC[dir];

            if (1 <= nr && nr <= N && 1 <= nc && nc <= M) {
                // Always capture the opponent if possible.  
                if (nr == R[other] && nc == C[other]) {
                    output(nr, nc);
                    return 0;
                }

                R[me] = nr;
                C[me] = nc;

                if (winner(R, C, other) == me && get_dist(me, nr, nc) < best_dist) {
                    best_r = nr;
                    best_c = nc;
                    best_dist = get_dist(me, nr, nc);
                }
            }
        }

        output(best_r, best_c);
        R[me] = best_r;
        C[me] = best_c;
    }
}