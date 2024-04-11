#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;

int N, M;
vector<vector<int>> dist;
vector<int> P;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    dist.assign(N, vector<int>(N, INF));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            char c;
            cin >> c;

            if (c == '1')
                dist[i][j] = 1;
        }

    for (int i = 0; i < N; i++)
        dist[i][i] = 0;

    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    cin >> M;
    P.resize(M);

    for (int &p : P) {
        cin >> p;
        p--;
    }

    vector<int> answer = {P.front()};
    int current = P.front(), index = 0;

    for (int i = 1; i < M; i++)
        if (dist[current][P[i]] < i - index) {
            current = P[i - 1];
            index = i - 1;
            answer.push_back(current);
        }

    answer.push_back(P.back());
    cout << answer.size() << '\n';

    for (int i = 0; i < (int) answer.size(); i++)
        cout << answer[i] + 1 << (i < (int) answer.size() - 1 ? ' ' : '\n');
}