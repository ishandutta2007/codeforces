#include <bits/stdc++.h>

using namespace std;
const int c=505;
int w, n, k, le[c][c], bal[c][c], dist[c][c];
queue<pair<int, int> > q;
void add(int a, int b, int c, int d) {
    if (a>c) swap(a, c);
    if (b>d) swap(b, d);
    if (a<c) le[a][b]++;
    if (b<d) bal[a][b]++;
}
void pb(int a, int b, int c) {
    if (dist[a][b]>c) {
        dist[a][b]=c;
        q.push({a, b});
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> k >> n;
        for (int i=1; i<=k; i++) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            add(a, b, c, d);
            add(n+1-a, n+1-b, n+1-c, n+1-d);
        }
        for (int i=0; i<=n+1; i++) {
            for (int j=1; j<=n+1; j++) {
                dist[i][j]=1e7;
            }
        }
        int ans=1e7;
        dist[n/2][n/2]=0;
        q.push({n/2, n/2});
        while (q.size()>0) {
            int a=q.front().first, b=q.front().second;
            q.pop();
            int d=dist[a][b];
            if (a==0 || a==n || b==0 || b==n) {
                ans=min(ans, d);
            } else {
                pb(a, b-1, d+le[a][b]);
                pb(a-1, b, d+bal[a][b]);
                pb(a, b+1, d+le[a][b+1]);
                pb(a+1, b, d+bal[a+1][b]);
            }
        }
        cout << k-ans << "\n";

        for (int i=0; i<=n+1; i++) {
            for (int j=0; j<=n+1; j++) {
                le[i][j]=0, bal[i][j]=0, dist[i][j]=0;
            }
        }
    }
    return 0;
}
/*
1
2 4
2 2 2 3
2 2 3 2
*/