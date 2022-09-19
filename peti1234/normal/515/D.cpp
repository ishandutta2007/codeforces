#include <bits/stdc++.h>

using namespace std;
const int c=2002;
int ans[c][c], n, m, r;
queue<pair<int, int> > q;
bool jo(int a, int b) {
    if (ans[a][b]) return 0;
    int db=0;
    if (!ans[a-1][b]) db++;
    if (!ans[a][b-1]) db++;
    if (!ans[a+1][b]) db++;
    if (!ans[a][b+1]) db++;
    return (db==1);
}
void ker(int a, int b) {
    if (jo(a-1, b)) q.push({a-1, b});
    if (jo(a, b-1)) q.push({a, b-1});
    if (jo(a+1, b)) q.push({a+1, b});
    if (jo(a, b+1)) q.push({a, b+1});
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) {
        char c; cin >> c;
        if (c=='*') ans[i][j]=5;
    }
    for (int i=1; i<=n; i++) ans[i][0]=5, ans[i][m+1]=5;
    for (int i=1; i<=m; i++) ans[0][i]=5, ans[n+1][i]=5;
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) if (jo(i, j)) q.push({i, j});
    while(q.size()>0) {
        int a=q.front().first, b=q.front().second;
        q.pop();
        if (!ans[a][b]) {
            ker(a, b);
            if (!ans[a-1][b]) ans[a][b]=1, ans[a-1][b]=3, ker(a-1, b);
            if (!ans[a][b-1]) ans[a][b]=2, ans[a][b-1]=4, ker(a, b-1);
            if (!ans[a+1][b]) ans[a][b]=3, ans[a+1][b]=1, ker(a+1, b);
            if (!ans[a][b+1]) ans[a][b]=4, ans[a][b+1]=2, ker(a, b+1);
        }
    }
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) r+=(!ans[i][j]);
    if (r) cout << "Not unique\n";
    else {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (ans[i][j]==1) cout << 'v';
                if (ans[i][j]==2) cout << '>';
                if (ans[i][j]==3) cout << '^';
                if (ans[i][j]==4) cout << '<';
                if (ans[i][j]==5) cout << '*';
            }
            cout << "\n";
        }
    }
    return 0;
}