#include <bits/stdc++.h>

using namespace std;
int n, m, k;
int a, b, c, d;
int t[1002][1002];
bool p[1002][1002];
bool v[1002][1002];
queue <pair<int, int> > sz;
void melysegi(int a, int b)
{
    v[a][b]=true;
    if (v[a-1][b]==false && p[a-1][b]==true) {
        melysegi(a-1, b);
    }
    if (v[a+1][b]==false && p[a+1][b]==true) {
        melysegi(a+1, b);
    }
    if (v[a][b-1]==false && p[a][b-1]==true) {
        melysegi(a, b-1);
    }
    if (v[a][b+1]==false && p[a][b+1]==true) {
        melysegi(a, b+1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            t[i][j]=INT_MAX;
            char x;
            cin >> x;
            if (x=='.') {
                p[i][j]=true;
            }
        }
    }
    cin >> a >> b >> c >> d;
    melysegi(a, b);
    if (v[c][d]==false) {
        cout << -1 << endl;
        return 0;
    }
    t[a][b]=0;
    sz.push({a, b});
    while (sz.size()>0) {
        int x=sz.front().first;
        int y=sz.front().second;
        int q=1;
        while (p[x-q][y]==true && t[x-q][y]>t[x][y] && q<=k) {
            if (t[x-q][y]>t[x][y]+1) {
                sz.push({x-q, y});
            }
            t[x-q][y]=t[x][y]+1;
            q++;
        }
        q=1;
        while (p[x+q][y]==true && t[x+q][y]>t[x][y] && q<=k) {
            if (t[x+q][y]>t[x][y]+1) {
                sz.push({x+q, y});
            }
            t[x+q][y]=t[x][y]+1;
            q++;
        }
        q=1;
        while (p[x][y-q]==true && t[x][y-q]>t[x][y] && q<=k) {
            if (t[x][y-q]>t[x][y]+1) {
                sz.push({x, y-q});
            }
            t[x][y-q]=t[x][y]+1;
            q++;
        }
        q=1;
        while (p[x][y+q]==true && t[x][y+q]>t[x][y] && q<=k) {
            if (t[x][y+q]>t[x][y]+1) {
                sz.push({x, y+q});
            }
            t[x][y+q]=t[x][y]+1;
            q++;
        }
        sz.pop();
        if(t[c][d]!=INT_MAX) {
            cout << t[c][d] << endl;
            return 0;
        }
    }
    return 0;
}