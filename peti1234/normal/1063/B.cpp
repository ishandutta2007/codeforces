#include <bits/stdc++.h>

using namespace std;
int n, m;
int a, b;
int q, r;
bool v[2001][2001];
int t[2001][2001];
priority_queue<pair<int, pair<int, int> > > p;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> a >> b >> q >> r;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            char c;
            cin >> c;
            if (c=='*') {
                v[i][j]=true;
            }
            t[i][j]=-1;
        }
    }
    p.push({0, {a, b}});
    while(p.size()>0) {
        int j=p.top().first;
        int x=p.top().second.first;
        int y=p.top().second.second;
        p.pop();
        if (!v[x][y]) {
            v[x][y]=true;
            t[x][y]=-j;
            if (x!=1 && !v[x-1][y]) {
                p.push({j, {x-1, y}});
            }
            if (x!=n && !v[x+1][y]) {
                p.push({j,{x+1, y}});
            }
            if (y!=1 && !v[x][y-1]) {
                p.push({j, {x, y-1}});
            }
            if (y!=m && !v[x][y+1]) {
                p.push({j-1, {x, y+1}});
            }
        }
    }
    int c=0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            //cout << t[i][j] << " ";
            //cout << b << " " << t[i][j] << " " <<  j << " " << q << endl;
            if (t[i][j]!=-1 && t[i][j]<=r && b+t[i][j]-j<=q) {
                c++;
            }
        }
        //cout << endl;
    }
    cout << c << endl;
    return 0;
}