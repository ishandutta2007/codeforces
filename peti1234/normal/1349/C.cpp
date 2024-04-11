#include <bits/stdc++.h>

using namespace std;
const int c=1002;
int t[c][c], n, m, w;
bool s[c][c], v[c][c];
queue<pair<pair<int, int>, int> > q;
void pr(int a, int b, int c) {
    if (a>=1 && a<=n && b>=1 && b<=m && !v[a][b]) q.push({{a, b}, c+1});
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> w;
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) {
        char c; cin >> c;
        if (c=='1') s[i][j]=1;
    }
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) {
        int a=s[i][j], p=0;
        if (i>1 && a==s[i-1][j]) p++;
        if (i<n && a==s[i+1][j]) p++;
        if (j>1 && a==s[i][j-1]) p++;
        if (j<m && a==s[i][j+1]) p++;
        if (p) q.push({{i, j}, 0});
    }
    while(q.size()>0) {
        int i=q.front().first.first, j=q.front().first.second, d=q.front().second;
        q.pop();
        if (i>=1 && i<=n && j>=1 && j<=m && !v[i][j]) {
            v[i][j]=1, t[i][j]=d;
            pr(i-1, j, d), pr(i+1, j, d), pr(i, j-1, d), pr(i, j+1, d);
        }
    }
    /*for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) cout << t[i][j] << " ";
        cout << endl;
    }*/
    for (int i=1; i<=w; i++) {
        int a, b;
        long long c, d;
        cin >> a >> b >> c;
        d=t[a][b];
        if (!v[a][b] || c<=d) cout << s[a][b];
        else if ((c-d)%2==0) cout << s[a][b];
        else cout << !s[a][b];
        cout << "\n";
    }
    return 0;
}