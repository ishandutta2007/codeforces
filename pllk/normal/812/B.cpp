#include <iostream>

using namespace std;

int n, m;
string s[20];
int a[20], b[20];
int p = 999999999;
int z;

void lol(int y, int x, int c) {
    if (y == z) {
        if (x == 0) {
            if (b[z]) c += b[z];
        } else {
            if (a[z]) c += (m-1-a[z]);
        }
        p = min(p,c);
        return;
    }
    if (x == 0) {
        if (b[y]) lol(y-1,0,c+b[y]*2+1);
        else lol(y-1,0,c+1);
        lol(y-1,m-1,c+m);
    } else {
        if (a[y]) lol(y-1,m-1,c+(m-1-a[y])*2+1);
        else lol(y-1,m-1,c+1);
        lol(y-1,0,c+m);
    }
}

int main() {
    cin >> n >> m;
    m += 2;
    z = n-1;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '1') {a[i] = j; break;}
        }
        for (int j = m-1; j >= 0; j--) {
            if (s[i][j] == '1') {b[i] = j; break;}
        }
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '1' && z == n-1) z = i;
        }
    }
    lol(n-1,0,0);
    cout << p << "\n";
}