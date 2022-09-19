#include <bits/stdc++.h>

using namespace std;
const int c=2005;
int n, t[c][c], ki[c];
int holvan(int a) {
    return (ki[a] ? ki[a]=holvan(ki[a]) : a);
}
void unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a!=b) {
        ki[a]=b;
    }
}
int solve() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> t[i][j];
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            int x=t[i][j], y=t[j][i];
            if (x==y) continue;
            if (x<y) {
                if (holvan(i)!=holvan(j+n)) {
                    unio(i, j);
                    unio(i+n, j+n);
                }
            }
            if (y<x) {
                if (holvan(i)!=holvan(j)) {
                    unio(i, j+n);
                    unio(i+n, j);
                }
            }
        }
    }
    for (int i=1; i<=n; i++) {
        if (holvan(i)!=holvan(1) && holvan(i+n)!=holvan(1)) {
            unio(1, i);
            unio(1+n, i+n);
        }
    }
    for (int i=1; i<=n; i++) {
        if (holvan(i)==holvan(1)) {
            for (int j=1; j<=n; j++) {
                swap(t[i][j], t[j][i]);
            }
        }
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cout << t[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            t[i][j]=0;
        }
    }
    for (int i=1; i<=2*n; i++) {
        ki[i]=0;
    }
}
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}
/*
1
3
1 2 2
2 1 1
1 2 1
*/