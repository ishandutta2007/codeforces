#include <bits/stdc++.h>

using namespace std;
const int c=1002;
int n, m, st, stx, sty, tav[c][c], dx[]={1, 0, 0, -1}, dy[]={0, -1, 1, 0};
bool jo[c][c], v[c][c];
queue<pair<int, int> > q;
string sol;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> st;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            char c; cin >> c;
            if (c!='*') {
                jo[i][j]=1;
            }
            if (c=='X') {
                stx=i, sty=j;
                q.push({i, j});
                v[i][j]=true;
            }
        }
    }
    while(q.size()>0) {
        int a=q.front().first, b=q.front().second;
        q.pop();
        if (jo[a][b]) {
            for (int i=0; i<4; i++) {
                int x=a+dx[i], y=b+dy[i];
                if (!v[x][y]) {
                    v[x][y]=1;
                    tav[x][y]=tav[a][b]+1;
                    q.push({x, y});
                }
            }
        }
    }
    for (int i=1; i<=st; i++) {
        bool s=0;
        for (int j=0; j<4; j++) {
            int x=stx+dx[j], y=sty+dy[j];
            if (!s && jo[x][y] && tav[x][y]<=st-i) {
                s=1;
                if (j==0) sol+='D';
                if (j==1) sol+='L';
                if (j==2) sol+='R';
                if (j==3) sol+='U';
                stx=x, sty=y;
            }
        }
    }
    if (sol.size()!=st) {
        cout << "IMPOSSIBLE" << "\n";
    } else {
        cout << sol << "\n";
    }
    return 0;
}