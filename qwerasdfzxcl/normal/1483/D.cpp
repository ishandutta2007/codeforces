#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<pair<int, int>> edge;
int weight[606][606];
ll dist[606][606], query[606][606], val[606][606];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (i==j) dist[i][j]=0, query[i][j]=-1e18, val[i][j]=-1e18;
            else dist[i][j]=1e18, query[i][j]=-1e18, val[i][j]=-1e18;
        }
    }
    for (int i=0;i<m;i++){
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        dist[a][b]=w, dist[b][a]=w;
        weight[a][b]=w, weight[b][a]=w;
        edge.push_back(make_pair(a, b));
    }
    for (int mid = 1;mid<=n;mid++){
        for (int s=1;s<=n;s++){
            for (int e=1;e<=n;e++){
                dist[s][e]=min(dist[s][e], dist[s][mid]+dist[mid][e]);
            }
        }
    }
    int q;
    scanf("%d", &q);
    for (int i=0;i<q;i++){
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        query[a][b]=w, query[b][a]=w;
    }
    for (int a=1;a<=n;a++){
        for (int d=1;d<=n;d++){
            for (int c=1;c<=n;c++){
                val[a][d]=max(val[a][d], query[c][d]-dist[c][a]);
            }
        }
    }
    int ans=0;
    for (auto &p:edge){
        for (int d=1;d<=n;d++){
            if (val[p.first][d]-weight[p.first][p.second]-dist[p.second][d]>=0){
                ans++; break;
            }
            if (val[p.second][d]-weight[p.first][p.second]-dist[p.first][d]>=0){
                ans++; break;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}