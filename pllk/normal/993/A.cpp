#include <iostream>
#include <cstdlib>

using namespace std;

int miny = 1000, maxy = -1000;
int minx = 1000, maxx = -1000;
int uy[10], ux[10];
bool zz;
int lol1 = 1000, lol2 = -1000;

void lol(int y1, int x1, int y2, int x2) {
    int dy = (y2 > y1) ? 1 : -1;
    int dx = (x2 > x1) ? 1 : -1;
    while (true) {
        if (miny <= y1 && y1 <= maxy && minx <= x1 && x1 <= maxx) {
            cout << "YES\n";
            exit(0);
        }
        if (y1 == maxy) {
            zz = true;
            lol1 = min(lol1,x1);
            lol2 = max(lol2,x1);
        }
        if (y1 == y2 && x1 == x2) return;
        y1 += dy;
        x1 += dx;
    }
}

int main() {
    for (int i = 0; i < 4; i++) {
        int y, x;
        cin >> y >> x;
        miny = min(miny,y);
        maxy = max(maxy,y);
        minx = min(minx,x);
        maxx = max(maxx,x);
    }
    for (int i = 0; i < 4; i++) {
        cin >> uy[i] >> ux[i];
    }
    lol(uy[0],ux[0],uy[1],ux[1]);
    lol(uy[1],ux[1],uy[2],ux[2]);
    lol(uy[2],ux[2],uy[3],ux[3]);
    lol(uy[3],ux[3],uy[0],ux[0]);
    if (zz && lol1 <= minx && lol2 >= maxx) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}