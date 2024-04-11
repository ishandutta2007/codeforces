#include <bits/stdc++.h>

using namespace std;
int a, b, c, d;
int t[51][51];
int main()
{
    cin >> a >> b >> c >> d;
    cout << 50 << " " << 50 << endl;
    for (int i=1; i<=50; i++) {
        for (int j=1; j<=50; j++) {
            t[i][j]=(i>25)*2+(j>25)+1;
        }
    }
    a--, b--, c--, d--;
    int x=26, y=26;
    for (int i=1; i<=a; i++) {
        t[x][y]=1;
        if (y!=50) {
            y+=2;
        } else {
            x+=2;
            y=26;
        }
    }
    x=1, y=1;
    for (int i=1; i<=d; i++) {
        t[x][y]=4;
        if (y!=25) {
            y+=2;
        } else {
            x+=2;
            y=1;
        }
    }
    x=26, y=1;
    for (int i=1; i<=b; i++) {
        t[x][y]=2;
        if (y!=25) {
            y+=2;
        } else {
            x+=2;
            y=1;
        }
    }
    x=1, y=26;
    for (int i=1; i<=c; i++) {
        t[x][y]=3;
        if (y!=50) {
            y+=2;
        } else {
            x+=2;
            y=26;
        }
    }
    for (int i=1; i<=50; i++) {
        for (int j=1; j<=50; j++) {
            if (t[i][j]==1) {
                cout << 'A';
            }
            if (t[i][j]==2) {
                cout << 'B';
            }
            if (t[i][j]==3) {
                cout << 'C';
            }
            if (t[i][j]==4) {
                cout << 'D';
            }
        }
        cout <<endl;
    }
    return 0;
}