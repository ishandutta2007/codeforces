#include <bits/stdc++.h>

using namespace std;
int n, m, db;
char c;
bool v[1002][1002], f[1002][1002], jo, p, r, us, uo;
bool x(int a, int b) {
    return (v[a][b] && !f[a][b]);
}
void dfs(int a, int b) {
    f[a][b]=true;
    if (x(a, b-1)) dfs(a, b-1);
    if (x(a, b+1)) dfs(a, b+1);
    if (x(a-1, b)) dfs(a-1, b);
    if (x(a+1, b)) dfs(a+1, b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> c;
            if (c=='#') v[i][j]=true;
        }
    }
    for (int i=1; i<=n; i++) {
        p=0, r=0;
        for (int j=1; j<=m; j++) {
            if (v[i][j] && !p) p=true;
            if (!v[i][j] && p) r=true;
            if (v[i][j] && r) jo=true;
        }
        if (!p) us=true;
    }
    for (int j=1; j<=m; j++) {
        p=0, r=0;
        for (int i=1; i<=n; i++) {
            if (v[i][j] && !p) p=true;
            if (!v[i][j] && p) r=true;
            if (v[i][j] && r) jo=true;
        }
        if (!p) uo=true;
    }
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) if (v[i][j] && !f[i][j]) dfs(i, j), db++;
    if (jo || (us!=uo)) cout << -1 << "\n";
    else cout << db << "\n";
    return 0;
}