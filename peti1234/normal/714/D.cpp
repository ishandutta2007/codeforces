#include <bits/stdc++.h>

using namespace std;
int n, p[5][3];
int t[5], ans;
void f() {
    ans=0;
    if (t[1]>t[3] || t[2]>t[4]) return;
    cout.flush() << "? " << t[1] << " " << t[2] << " " << t[3] << " " << t[4] << "\n";
    cin >> ans;
}
void kker(int a, int b) {
    t[1]=1, t[2]=1, t[3]=n, t[4]=n;
    int x=1, y=n+1;
    while(y-x>1) {
        int z=(x+y)/2;
        t[a]=z, f();
        if (ans>=b) x=z;
        else y=z;
    }
    p[a][b]=x;
}
void nker(int a, int b) {
    t[1]=1, t[2]=1, t[3]=n, t[4]=n;
    int x=0, y=n;
    while(y-x>1) {
        int z=(x+y)/2;
        t[a]=z, f();
        if (ans>=b) y=z;
        else x=z;
    }
    p[a][b]=y;
}
bool ch() {
    int a, b;
    for (int i=1; i<=4; i++) t[i]=p[i][1];
    f(), a=ans;
    for (int i=1; i<=4; i++) t[i]=p[i][2];
    f(), b=ans;
    return (a==1 && b==1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    kker(1, 1), kker(1, 2), kker(2, 1), kker(2, 2), nker(3, 1), nker(3, 2), nker(4, 1), nker(4, 2);
    for (int i=0; i<8; i++) {
        int x=i, y=i;
        for (int i=1; i<=3; i++) {
            if (x%2) swap(p[i][1], p[i][2]);
            x/=2;
        }
        if (ch()) {
            cout << "! ";
            for (int j=1; j<=2; j++) for (int i=1; i<=4; i++) cout << p[i][j] << " ";
            return 0;
        }
        for (int i=1; i<=3; i++) {
            if (y%2) swap(p[i][1], p[i][2]);
            y/=2;
        }
    }
    return 0;
}