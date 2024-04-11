#include <bits/stdc++.h>

using namespace std;
const int c=52;
bool jo[c][c], bl[c][c], v[c][c];
int n, m, w;
void dfs(int a, int b) {
    if (bl[a][b] || a<1 || a>n || b<1 || b>m || v[a][b]) return;
    v[a][b]=true;
    dfs(a-1, b), dfs(a+1, b), dfs(a, b-1), dfs(a, b+1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> m;
        for (int i=0; i<c; i++) for (int j=0; j<c; j++) jo[i][j]=0, bl[i][j]=0, v[i][j]=0;
        for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) {
            char c; cin >> c;
            if (c=='G') jo[i][j]=1;
            if (c=='#') bl[i][j]=1;
            if (c=='B') bl[i-1][j]=1, bl[i+1][j]=1, bl[i][j-1]=1, bl[i][j+1]=1;
        }
        dfs(n, m);
        bool p=1;
        for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) if (jo[i][j] && !v[i][j]) p=0;
        if (p) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}