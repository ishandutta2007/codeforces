#include <bits/stdc++.h>
using namespace std;

int W, H, dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
char c[1005][1005];
int vis[1005][1005][4];
deque< pair<int, pair< pair<int, int>, int> > > PQ;

bool checkvalid(int x, int y) {
    if (x < 0 || x >= H) return 0;
    if (y < 0 || y >= W) return 0;
    return 1;
}

int main() {
    scanf("%d%d", &H, &W);
    for (int i = 0; i < H; i++) scanf("%s", &c[i]);
    PQ.push_back(make_pair(0, make_pair(make_pair(H - 1, W - 1), 2)));
    memset(vis, 127, sizeof(vis));
    vis[H-1][W-1][2] = 0;
    while (!PQ.empty()) {
        int dist = PQ.front().first;
        int h = PQ.front().second.first.first, w = PQ.front().second.first.second, d = PQ.front().second.second;
        PQ.pop_front();
        //printf("%d %d %d %d\n", h,w,d,dist);
        if (h == 0 && w == 0 && d == 2) {
            printf("%d\n", dist);
            return 0;
        }
        int newh = h + dir[d][0], neww = w + dir[d][1];
        if (checkvalid(newh, neww) && vis[newh][neww][d] > dist) {
            PQ.push_front(make_pair(dist, make_pair(make_pair(newh, neww), d)));
            vis[newh][neww][d] = dist;
        }
        if (c[h][w] == '#') {
            for (int i = 0; i < 4; i++) {
                if (vis[h][w][i] <= dist + 1) continue;
                PQ.push_back(make_pair(dist + 1, make_pair(make_pair(h, w), i)));
                vis[h][w][i] = dist + 1;
            }
        }
    }
    printf("-1\n");
}