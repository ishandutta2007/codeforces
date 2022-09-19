#include <bits/stdc++.h>

using namespace std;
const int c=402;
long long sum, mod=998244353;
int n, m, dist[c][c], utdb;
vector<int> sz[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i!=j) {
                dist[i][j]=c;
            }
        }
    }
    for (int i=1; i<=m; i++) {
        int a, b; cin >> a >> b;
        dist[a][b]=dist[b][a]=1;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            utdb=0, sum=1;
            for (int k=1; k<=n; k++) {
                if (dist[i][k]+dist[k][j]==dist[i][j]) {
                    utdb++;
                } else {
                    int cnt=0;
                    for (int s:sz[k]) {
                        if (dist[i][s]<dist[i][k] && dist[j][s]<dist[j][k]) {
                            cnt++;
                        }
                    }
                    sum*=cnt;
                    if (sum>mod) {
                        sum%=mod;
                    }
                }
            }
            if (utdb>dist[i][j]+1) {
                sum=0;
            }
            cout << sum << " ";
        }
        cout << "\n";
    }
    return 0;
}