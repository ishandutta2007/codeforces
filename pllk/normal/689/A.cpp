#include <iostream>

using namespace std;

int n;
int yy[128];
int xx[128];

void lol(int k, int y, int x) {
    yy[k+'0'] = y;
    xx[k+'0'] = x;
}

int dy[111];
int dx[111];

int cc;

void haku(int z, int k) {
    if (k == n) {
        cc++;
        return;
    }
    for (int i = '0'; i <= '9'; i++) {
        int uy = yy[i]-yy[z];
        int ux = xx[i]-xx[z];
        if (dy[k] != uy || dx[k] != ux) continue;
        haku(i,k+1);
    }
}

int main() {
    lol(1,1,1);
    lol(2,1,2);
    lol(3,1,3);
    lol(4,2,1);
    lol(5,2,2);
    lol(6,2,3);
    lol(7,3,1);
    lol(8,3,2);
    lol(9,3,3);
    lol(0,4,2);
    cin >> n;
    string s;
    cin >> s;
    for (int i = 1; i <= n-1; i++) {
        dy[i] = yy[s[i]]-yy[s[i-1]];
        dx[i] = xx[s[i]]-xx[s[i-1]];
    }
    for (int i = '0'; i <= '9'; i++) {
        haku(i,1);
    }
    if (cc == 1) cout << "YES\n";
    else cout << "NO\n";
}