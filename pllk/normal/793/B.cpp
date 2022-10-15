#include <iostream>
#include <cstdlib>

using namespace std;

int n, m;
string s[1111];
bool d[1111][1111][3][3][3];

void lol(int y, int x, int dy, int dx, int c) {
    if (y < 0 || x < 0 || y >= n || x >= m) return;
    if (s[y][x] == '*') return;
    if (d[y][x][dy+1][dx+1][c]) return;
    d[y][x][dy+1][dx+1][c] = 1;
    if (s[y][x] == 'T') {
        cout << "YES\n";
        exit(0);
    }
    lol(y+dy,x+dx,dy,dx,c);
    if (dy && c < 2) {
        lol(y,x,0,1,c+1);
        lol(y,x,0,-1,c+1);
    }
    if (dx && c < 2) {
        lol(y,x,1,0,c+1);
        lol(y,x,-1,0,c+1);
    }
}

int main() {
    cin >> n >> m;
    int sx, sy;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'S') {
                sy = i; sx = j;
            }
        }
    }
    lol(sy,sx,0,-1,0);
    lol(sy,sx,0,1,0);
    lol(sy,sx,-1,0,0);
    lol(sy,sx,1,0,0);
    cout << "NO\n";
}