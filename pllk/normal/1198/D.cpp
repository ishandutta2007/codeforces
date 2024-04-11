#include <iostream>

using namespace std;

int n;
string s[55];
int a[55][55];
int b[55][55];

int vv[55][55][55][55];
int dd[55][55][55][55];

int lol(int y1, int x1, int y2, int x2) {
    if (y1 > y2 || x1 > x2) return 0;
    if (vv[y1][x1][y2][x2]) return dd[y1][x1][y2][x2];
    int yd = y2-y1+1;
    int xd = x2-x1+1;
    int u = max(yd,xd);
    if (a[y1][x1] >= yd) return lol(y1,x1+1,y2,x2);
    if (a[y1][x2] >= yd) return lol(y1,x1,y2,x2-1);
    if (b[y1][x1] >= xd) return lol(y1+1,x1,y2,x2);
    if (b[y2][x1] >= xd) return lol(y1,x1,y2-1,x2);
    for (int i = x1; i <= x2; i++) {
        if (a[y1][i] >= yd) {
            u = min(u,lol(y1,x1,y2,i-1)+lol(y1,i+1,y2,x2));
        }
    }
    for (int i = y1; i <= y2; i++) {
        if (b[i][x1] >= xd) {
            u = min(u,lol(y1,x1,i-1,x2)+lol(i+1,x1,y2,x2));
        }
    }
    vv[y1][x1][y2][x2] = 1;
    dd[y1][x1][y2][x2] = u;
    return u;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = "."+s[i];
    }
    for (int j = 1; j <= n; j++) {
        for (int i = n; i >= 1; i--) {
            if (s[i][j] == '#') a[i][j] = 0;
            else a[i][j] = a[i+1][j]+1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = n; j >= 1; j--) {
            if (s[i][j] == '#') b[i][j] = 0;
            else b[i][j] = b[i][j+1]+1;
        }
    }
    cout << lol(1,1,n,n) << "\n";
}