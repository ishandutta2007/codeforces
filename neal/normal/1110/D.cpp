#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> tiles;
int dp[3][3], next_dp[3][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    tiles.assign(M + 5, 0);

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        tiles[a]++;
    }

    memset(dp, -63, sizeof(dp));
    dp[0][0] = 0;

    for (int a = 1; a <= M; a++) {
        memset(next_dp, -63, sizeof(next_dp));

        for (int x = 0; x < 3; x++)
            for (int y = 0; y < 3; y++)
                for (int z = 0; z < 3; z++)
                    if (tiles[a] >= x + y + z && tiles[a + 1] >= y + z && tiles[a + 2] >= z) {
                        int remaining = tiles[a] - (x + y + z);
                        next_dp[y][z] = max(next_dp[y][z], dp[x][y] + z + remaining / 3);
                    }

        memcpy(dp, next_dp, sizeof(dp));
    }

    cout << dp[0][0] << '\n';
}