#include <iostream>

using namespace std;

int t[1111][1111];

void lol(int a, int b, int c, int d, int k, int x) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            t[c+i][d+j] = t[a+i][b+j]*x;
        }
    }
}

int main() {
    int k;
    cin >> k;
    if (k == 0) {cout << "+\n"; return 0;}
    int n = 1<<k;
    t[1][1] = 1;
    t[1][2] = 1;
    t[2][1] = 1;
    t[2][2] = -1;
    for (int i = 1; i < k; i++) {
        lol(1,1,1,1+(1<<i),(1<<i),1);
        lol(1,1,1+(1<<i),1,(1<<i),1);
        lol(1,1,1+(1<<i),1+(1<<i),(1<<i),-1);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (t[i][j] == 1) cout << "+";
            else cout << "*";
        }
        cout << "\n";
    }
}