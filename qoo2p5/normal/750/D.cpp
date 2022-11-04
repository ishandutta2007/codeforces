#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9 + 123;

const int N = 400;

int n;
bool ok[N][N];
bool go[N][N][8];
bool ngo[N][N][8];

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

void run() {
    cin >> n;
    
    go[N / 2][N / 2][0] = 1;
    
    for (int iter = 0; iter < n; iter++) {
        int t;
        cin >> t;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int dir = 0; dir < 8; dir++) {
                    if (!go[i][j][dir]) {
                        continue;
                    }
                    
                    for (int k = 0; k < t; k++) {
                        int x = i + dx[dir] * k;
                        int y = j + dy[dir] * k;
                        ok[x][y] = 1;
                    }
                    
                    int x = i + dx[dir] * (t - 1);
                    int y = j + dy[dir] * (t - 1);
                    
                    {
                        int dir1 = dir - 1;
                        if (dir1 < 0) {
                            dir1 += 8;
                        }
                        
                        ngo[x + dx[dir1]][y + dy[dir1]][dir1] = 1;
                    }
                    
                    {
                        int dir1 = dir + 1;
                        if (dir1 >= 8) {
                            dir1 -= 8;
                        }
                        
                        ngo[x + dx[dir1]][y + dy[dir1]][dir1] = 1;
                    }
                }
            }
        }
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                copy(ngo[i][j], ngo[i][j] + 8, go[i][j]);
                fill(ngo[i][j], ngo[i][j] + 8, 0);
            }
        }
    }
    
    int ans = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ans += ok[i][j];
        }
    }
    
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    run();
    return 0;
}