#include <iostream>

using namespace std;

char z[500][500];
char d[500][500][10][33];

int n;
int t[33];
int f[8][2] = {{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

void lol(int y, int x, int s, int k) {
    if (k == n+1) return;
    if (d[y][x][s][k]) return;
    d[y][x][s][k] = 1;
    for (int i = 0; i < t[k]; i++) {
        y += f[s][0];
        x += f[s][1];
        z[y][x] = 1;
    }
    lol(y,x,(s+1)%8,k+1);
    lol(y,x,(s-1+8)%8,k+1);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> t[i];
    lol(250,250,0,1);
    int c = 0;
    for (int i = 0; i < 500; i++) {
        for (int j = 0; j < 500; j++) {
            if (z[i][j]) c++;
        }
    }
    cout << c << "\n";
}