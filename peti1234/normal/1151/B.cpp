#include <bits/stdc++.h>

using namespace std;
int n, m, a;
int p;
int x, y;
int t[501][501];
int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            int b;
            cin >> b;
            if (j==1) {
                a^=b;
            }
            if (j!=1 && p!=b && x==0) {
                x=i, y=j;
            }
            p=b;
        }
    }
    if (a==0 && x==0) {
        cout << "NIE" << endl;
        return 0;
    }
    cout << "TAK" << endl;
    if (a!=0) {
        x=0;
    }
    for (int i=1; i<=n; i++) {
        if (i!=x) {
            cout << 1 << " ";
        } else {
            cout << y << " ";
        }
    }
    cout << endl;
    return 0;
}