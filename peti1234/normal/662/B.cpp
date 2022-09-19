#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int n, m, pos, si[c][2], ki[c][2], v[c][2], db[2];
int holvan(int a, int b) {
    if (!ki[a][b]) {
        return a;
    }
    return ki[a][b]=(holvan(ki[a][b], b));
}
int unio(int a, int b, int c) {
    a=holvan(a, c), b=holvan(b, c);
    if (a!=b) {
        si[a][c]+=si[b][c], si[b][c]=0;
        ki[b][c]=a;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        si[i][0]=si[i][1]=1;
    }
    for (int i=1; i<=m; i++) {
        int a, b, s;
        char c;
        cin >> a >> b >> c;
        s=(c=='R');
        unio(a, b, s), unio(a+n, b+n, s);
        unio(a, b+n, !s), unio(a+n, b, !s);
    }
    for (int j=0; j<2; j++) {
        for (int i=1; i<=n; i++) {
            int x=holvan(i, j), y=holvan(i+n, j);
            if (x==y) {
                db[j]=c;
            }
            if (!v[y][j] && si[x][j]<=si[y][j]) {
                v[x][j]=1;
            }
        }
        for (int i=1; i<=n; i++) {
            v[i][j]=v[holvan(i, j)][j];
            db[j]+=v[i][j];
        }
    }
    if (db[1]<db[0]) {
        pos=1;
    }
    if (db[pos]>=c) {
        cout << -1 << "\n";
        return 0;
    }
    cout << db[pos] << "\n";
    for (int i=1; i<=n; i++) {
        if (v[i][pos]) {
            cout << i << " ";
        }
    }
    cout << "\n";
    return 0;
}