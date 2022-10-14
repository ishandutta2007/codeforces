#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, K;
    cin >> N >> K;

    vector<vector<int>> grid(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < N; j++) {
            if (s[j] == 'B') grid[i][j] = 1;
        }
    }

    vector<vector<int>> hors(N + 1, vector<int>(N + 1, 0));
    vector<vector<int>> vert(N + 1, vector<int>(N + 1, 0));
    vector<vector<int>> point(N + 1, vector<int>(N + 1, 0));
    
    int free = 0;
    for (int i = 0; i < N; i++) {
        int l = 0;
        while (l < N && grid[i][l] != 1) l++;
        if (l == N) {
            free++;
            continue;
        }
        int r = N - 1;
        while (grid[i][r] != 1) r--;
        if (r - l + 1 > K) continue;

        for (int k = max(0, i - K + 1); k <= i; k++) {
            hors[k][max(0, r - K + 1)]++;
            hors[k][l + 1]--;
        }
    }

    for (int j = 0; j < N; j++) {
        int l = 0;
        while (l < N && grid[l][j] != 1) l++;
        if (l == N) {
            free++;
            continue;
        }
        int r = N - 1;
        while (grid[r][j] != 1) r--;
        if (r - l + 1 > K) continue;
        for (int k = max(0, j - K + 1); k <= j; k++) {
            vert[max(0, r - K + 1)][k]++;
            vert[l + 1][k]--;
        }
    }

    
    for (int i = 0; i < N; i++) {
        for (int j = 1; j < N; j++) {
            hors[i][j] += hors[i][j - 1];
        }
        for (int j = 0; j < N; j++) {
            point[i][j] += hors[i][j];
        }
    }

    for (int j = 0; j < N; j++) {
        for (int i = 1; i < N; i++) {
            vert[i][j] += vert[i - 1][j];
        }
        for (int i = 0; i < N; i++) {
            point[i][j] += vert[i][j];
        }
    }
    
    int ans = 0;
    for (int i = 0; i < N - K + 1; i++) {
        for (int j = 0; j < N - K + 1; j++) {
            ans = max(ans, point[i][j]);
        }
    }

    cout << ans + free << "\n";
    return 0;

}