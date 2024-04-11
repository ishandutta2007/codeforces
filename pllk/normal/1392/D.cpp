#include <iostream>

using namespace std;

#define INF 999999999

int d[202020][4];
int n;
string s, u;

int check(int z) {
    u = s;
    int a = 0;
    if (z == 0 || z == 1) {
        if (u[1] != 'L') {u[1] = 'L'; a++;}
    }
    if (z == 2 || z == 3) {
        if (u[1] != 'R') {u[1] = 'R'; a++;}
    }
    if (z == 0 || z == 2) {
        if (u[2] != 'L') {u[2] = 'L'; a++;}
    }
    if (z == 1 || z == 3) {
        if (u[2] != 'R') {u[2] = 'R'; a++;}
    }
    d[2][0] = INF;
    d[2][1] = INF;
    d[2][2] = INF;
    d[2][3] = INF;
    d[2][z] = a;
    for (int i = 3; i <= n; i++) {
        for (int k = 0; k < 4; k++) {
            int b = 0;
            if ((k == 0 || k == 2) && u[i] == 'R') b = 1;
            if ((k == 1 || k == 3) && u[i] == 'L') b = 1;
            int f = INF;
            if (k == 0) f = b+d[i-1][2];
            if (k == 1) f = b+min(d[i-1][0],d[i-1][2]);
            if (k == 2) f = b+min(d[i-1][1],d[i-1][3]);
            if (k == 3) f = b+d[i-1][1];
            d[i][k] = f;
        }
    }
    int p = INF;
    if (u[1] != 'L') p = min(p,d[n][0]);
    if (u[1] != 'R' || u[2] != 'R') p = min(p,d[n][1]);
    if (u[1] != 'L' || u[2] != 'L') p = min(p,d[n][2]);
    if (u[1] != 'R') p = min(p,d[n][3]);
    return p;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> s;
        s = "#"+s;
        int p = INF;
        for (int i = 0; i < 4; i++) p = min(p,check(i));
        cout << p << "\n";
    }
}