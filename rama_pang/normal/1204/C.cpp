#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;
    vector<vector<lint>> matrix(N, vector<lint>(N, 0));
    vector<vector<lint>> dist(N, vector<lint>(N, 0));
    
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < N; j++) {
            if (s[j] == '1') dist[i][j] = 1;
            else dist[i][j] = 1000;
        }
        dist[i][i] = 0;
    }

    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) for (int k = 0; k < N; k++) {
        if (dist[i][j] > dist[i][k] + dist[k][j]) {
            dist[i][j] = dist[i][k] + dist[k][j];
        }
    }

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << dist[i][j] << " \n"[j == N - 1];
    //     }
    // }

    int M;
    cin >> M;
    vector<int> Path;
    int last = 0, last_v = 0;
    int a; cin >> a; a--;
    last_v = a;
    last = -1;
    for (int i = 1; i < M; i++) {
        int a; cin >> a; a--;
        if (Path.empty() || dist[Path.back()][a] < i - last) {
            Path.emplace_back(last_v);
            // last = i;
            // cout << i << " id " << i - last << "\n";
            last = i - 1;
        }

        last_v = a;
        if (i == M - 1) {
            Path.emplace_back(a);
        }
    }

    cout << Path.size() << "\n";
    for (auto i : Path) cout << i + 1 << " ";
    cout << "\n";

    return 0;

}