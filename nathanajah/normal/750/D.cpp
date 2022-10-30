#include <bits/stdc++.h>
using namespace std;

int dirx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int diry[8] = {1, 0, -1, -1, -1, 0, 1, 1};

bool firework[300][300][8];
bool newfirework[300][300][8];
bool counted[300][300];
int t[30];
int n;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            //initialize 150,150 
            firework[150][150][3] = true;
            counted[150][150] = true;
        } else {
            //split existing fireworks
            memset(newfirework, 0, sizeof(newfirework));
            for (int x = 0; x < 300; x++) {
                for (int y = 0; y < 300; y++) {
                    for (int dir = 0; dir < 8; dir++) {
                        if (firework[x][y][dir]) {
                            int newdir1 = (dir + 1) % 8;
                            int newdir2 = (dir + 7) % 8;
                            int newx1 = x + dirx[newdir1];
                            int newy1 = y + diry[newdir1];
                            int newx2 = x + dirx[newdir2];
                            int newy2 = y + diry[newdir2];

                            newfirework[newx1][newy1][newdir1] = true;
                            newfirework[newx2][newy2][newdir2] = true;
                            counted[newx1][newy1] = true;
                            counted[newx2][newy2] = true;
                        }
                    }
                }
            }
            for (int x = 0; x < 300; x++) {
                for (int y = 0; y < 300; y++) {
                    for (int dir = 0; dir < 8; dir++) {
                        firework[x][y][dir] = newfirework[x][y][dir];
                    }
                }
            }
        }

        for (int j = 0; j < t[i] - 1; j++) {
            memset(newfirework, 0, sizeof(newfirework));
            for (int x = 0; x < 300; x++) {
                for (int y = 0; y < 300; y++) {
                    for (int dir = 0; dir < 8; dir++) {
                        if (firework[x][y][dir]) {
                            int newx = x + dirx[dir];
                            int newy = y + diry[dir];
                            newfirework[newx][newy][dir] = true;
                            counted[newx][newy] = true;
                        }
                    }
                }
            }
            for (int x = 0; x < 300; x++) {
                for (int y = 0; y < 300; y++) {
                    for (int dir = 0; dir < 8; dir++) {
                        firework[x][y][dir] = newfirework[x][y][dir];
                    }
                }
            }
        }
    }
    int cnt = 0;
    for (int x = 0; x < 300; x++) {
        for (int y = 0; y < 300; y++) {
            if (counted[x][y]) {
                ++cnt;
            }
        }
    }
    printf("%d\n", cnt);
}