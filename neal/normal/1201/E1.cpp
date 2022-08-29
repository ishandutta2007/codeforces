#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

const string COLORS[2] = {"WHITE", "BLACK"};

const int LIMIT = 1024;
const int INF = 1e9 + 5;

const int DIRS = 8;
const int DR[] = {-2, -2, -1, -1, +1, +1, +2, +2};
const int DC[] = {-1, +1, -2, +2, -2, +2, -1, +1};

int N, M;

int encode(int r, int c) {
    return r * LIMIT + c;
}

pair<int, int> decode(int encoded) {
    return {encoded / LIMIT, encoded % LIMIT};
}

bool valid(int r, int c) {
    return 1 <= r && r <= N && 1 <= c && c <= M;
}

bool valid(int encoded) {
    pair<int, int> p = decode(encoded);
    return valid(p.first, p.second);
}

int parity(int r, int c) {
    return (r + c) % 2;
}

int parity(int encoded) {
    pair<int, int> p = decode(encoded);
    return parity(p.first, p.second);
}

int V;
vector<vector<int>> adj;

void bfs_check(queue<int> &q, queue<int> &next_q, vector<int> &dist, vector<int> &previous, int node, int current_dist,
               int add, int from) {
    assert(0 <= add && add <= 1);

    if (current_dist < dist[node]) {
        dist[node] = current_dist;
        previous[node] = from;
        (add == 0 ? q : next_q).push(node);
    }
}

void bfs(int source, vector<int> &dist, vector<int> &previous) {
    if (V == 0) return;
    // Two queues are needed for 0-1 BFS.
    queue<int> q, next_q;
    dist.assign(V, INF);
    previous.assign(V, -1);
    bfs_check(q, next_q, dist, previous, source, 0, 0, -1);
    int level = 0;

    while (!q.empty() || !next_q.empty()) {
        while (!q.empty()) {
            int top = q.front(); q.pop();

            if (level > dist[top])
                continue;

            for (int neighbor : adj[top])
                bfs_check(q, next_q, dist, previous, neighbor, dist[top] + 1, 1, top);
        }

        swap(q, next_q);
        level++;
    }
}

int positions[2];
int goals[2];
vector<int> dist[2];
vector<int> previous[2];

void output(int r, int c) {
    cout << r << ' ' << c << endl;
}

void output(int encoded) {
    pair<int, int> p = decode(encoded);
    output(p.first, p.second);
}

void go_directly(int who) {
    cout << COLORS[who] << endl;
    int position = positions[who], turn = 0;

    while (true) {
        if (turn != who) {
            int x, y;
            cin >> x >> y;
            turn = 1 - turn;
            continue;
        }

        int next_position = previous[who][position];
        output(next_position);
        position = next_position;

        if (position == goals[who])
            return;

        turn = 1 - turn;
    }
}

vector<bool> good;

void compute_good() {
    good.assign(V, false);

    // Good squares are 1 away from one goal and 2 away from the other.
    for (int i = 0; i < V; i++)
        if (i != goals[0] && i != goals[1] && dist[0][i] + dist[1][i] == 3)
            good[i] = true;
}

void block_and_win(int who) {
    cout << COLORS[who] << endl;
    int other = 1 - who;
    int position = positions[who], other_position = positions[other];
    int turn = 0;
    compute_good();

    while (true) {
        if (turn != who) {
            int x, y;
            cin >> x >> y;
            other_position = encode(x, y);
            turn = 1 - turn;
            continue;
        }

        // Always capture other if possible.
        for (int neighbor : adj[position])
            if (neighbor == other_position) {
                output(neighbor);
                return;
            }

        // Always go to my goal if possible.
        for (int neighbor : adj[position])
            if (neighbor == goals[who]) {
                output(neighbor);
                return;
            }

        // First move toward other's goal.
        if (dist[other][position] > 1) {
            int next_position = previous[other][position];
            output(next_position);
            position = next_position;
            turn = 1 - turn;
            continue;
        }

        // Try to move to a good square, which is a square that attacks one of the goals and is one away from attacking the other.
        bool found_good = false;

        for (int neighbor : adj[position])
            if (good[neighbor]) {
                output(neighbor);
                position = neighbor;
                found_good = true;
                break;
            }

        if (found_good) {
            turn = 1 - turn;
            continue;
        }

        // If attacking other's goal but not on a good square, move to other the next turn.
        bool found_other_goal = false;

        for (int neighbor : adj[position])
            if (neighbor == goals[other]) {
                output(neighbor);
                position = neighbor;
                found_other_goal = true;
                break;
            }

        if (found_other_goal) {
            turn = 1 - turn;
            continue;
        }

        assert(false);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M;

    int R1, C1, R2, C2;
    cin >> R1 >> C1 >> R2 >> C2;
    positions[0] = encode(R1, C1);
    positions[1] = encode(R2, C2);

    V = encode(N, M) + 1;
    adj.assign(V, {});

    for (int r = 1; r <= N; r++)
        for (int c = 1; c <= M; c++) {
            int encoded = encode(r, c);

            for (int dir = 0; dir < DIRS; dir++) {
                int nr = r + DR[dir];
                int nc = c + DC[dir];
                int n_encoded = encode(nr, nc);

                if (valid(n_encoded))
                    adj[encoded].push_back(n_encoded);
            }
        }

    goals[0] = encode(N / 2, M / 2);
    goals[1] = encode(N / 2 + 1, M / 2);
    bfs(goals[0], dist[0], previous[0]);
    bfs(goals[1], dist[1], previous[1]);
    int right = 0;
    int wrong = 1;

    if (parity(positions[0]) == parity(positions[1]))
        swap(right, wrong);

    int wrong_to_wrong = dist[wrong][positions[wrong]];
    int right_to_right = dist[right][positions[right]] + (wrong == 0 ? 1 : 0);
    int right_to_wrong = dist[wrong][positions[right]] - (wrong == 1 ? 1 : 0);

    if (wrong_to_wrong < min(right_to_right, right_to_wrong)) {
        go_directly(wrong);
        exit(0);
    }

    block_and_win(right);
}