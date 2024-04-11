#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int LCM = 2520;

int N, Q;
vector<int> K, M;
vector<vector<int>> E;
vector<vector<int>> answers;
vector<vector<bool>> seen;
vector<int> current;
int current_index = 0;

void solve(int node, int m) {
    if (answers[node][m] >= 0)
        return;

    vector<pair<int, int>> path = {{node, m}};

    while (answers[node][m] < 0 && !seen[node][m]) {
        seen[node][m] = true;
        m = (m + K[node]) % LCM;
        node = E[node][m % M[node]];
        path.emplace_back(node, m);
    }

    if (answers[node][m] >= 0) {
        for (pair<int, int> &p : path)
            answers[p.first][p.second] = answers[node][m];

        return;
    }

    int P = path.size();
    assert(P > 1);
    int cycle_index = -1;

    for (int i = P - 2; i >= 0; i--)
        if (path[i] == path[P - 1]) {
            cycle_index = i;
            break;
        }

    assert(cycle_index >= 0);
    current_index++;
    int cycle_count = 0;

    for (int i = cycle_index; i < P; i++)
        if (current[path[i].first] != current_index) {
            current[path[i].first] = current_index;
            cycle_count++;
        }

    for (pair<int, int> &p : path)
        answers[p.first][p.second] = cycle_count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    K.resize(N);
    M.assign(N, 0);
    E.assign(N, {});

    for (int &k : K) {
        cin >> k;
        k = (k % LCM + LCM) % LCM;
    }

    for (int i = 0; i < N; i++) {
        cin >> M[i];
        E[i].resize(M[i]);

        for (int &e : E[i]) {
            cin >> e;
            e--;
        }
    }

    answers.assign(N, vector<int>(LCM, -1));
    seen.assign(N, vector<bool>(LCM, false));
    current.assign(N, -1);

    for (int i = 0; i < N; i++)
        for (int m = 0; m < LCM; m++)
            solve(i, m);

    cin >> Q;

    for (int q = 0; q < Q; q++) {
        int x, y;
        cin >> x >> y;
        x--;
        y = (y % LCM + LCM) % LCM;
        cout << answers[x][y] << '\n';
    }
}