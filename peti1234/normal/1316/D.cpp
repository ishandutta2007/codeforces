#include <bits/stdc++.h>

using namespace std;
const int c=1002;
string sol[c];
string s;
int n, x[c][c], y[c][c];
bool v[c][c];
bool jo(int a, int b, int c, int d, int e) {
    if (a<0 || a>=n || b<0 || b>=n || x[a][b]!=x[c][d] || y[a][b]!=y[c][d]) return 0;
    char x;
    if (e==1) x='D';
    if (e==2) x='U';
    if (e==3) x='R';
    if (e==4) x='L';
    //cout << a << " " << b << " " << c << " " << d << " " << e << " " << sol[a][b] << endl;
    if (sol[a][b]=='A') {
        sol[a][b]=x;
    }
    return 1;
}
void dfs(int a, int b) {
    //cout << "dfs " << a << " " << b << " " << endl;
    if (v[a][b]) return;
    v[a][b]=true;
    if (jo(a-1, b, a, b, 1)) dfs(a-1, b);
    if (jo(a+1, b, a, b, 2)) dfs(a+1, b);
    if (jo(a, b-1, a, b, 3)) dfs(a, b-1);
    if (jo(a, b+1, a, b, 4)) dfs(a, b+1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=0; i<n; i++) s+='A';
    for (int i=0; i<n; i++) sol[i]=s;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> x[i][j] >> y[i][j];
            x[i][j]--, y[i][j]--;
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (!v[i][j]) {
                if (x[i][j]==-2) {
                    dfs(i, j);
                }
                if (x[i][j]==i && y[i][j]==j) {
                    sol[i][j]='X';
                    dfs(i, j);
                }
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (sol[i][j]=='A') {
                cout << "INVALID\n";
                return 0;
            }
        }
    }
    cout << "VALID\n";
    for (int i=0; i<n; i++) {
        cout << sol[i] << "\n";
    }
    return 0;
}
/*
3
-1 -1 -1 -1 -1 -1
-1 -1 2 2 -1 -1
-1 -1 -1 -1 -1 -1
*/