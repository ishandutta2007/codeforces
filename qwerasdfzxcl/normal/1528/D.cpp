#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
struct Edge{
    int s, e, t;
    Edge(){}
    Edge(int _s, int _e, int _t): s(_s), e(_e), t(_t) {}
    bool operator<(const Edge &E) const{
        return e<E.e;
    }
};
vector<Edge> e[606];
int dist[606][606], ans[606][606];
bool visited[606][606];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i=0;i<m;i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        e[a].push_back(Edge(a, b, c));
    }
    for (int i=0;i<n;i++){
        sort(e[i].begin(), e[i].end());
        int pt = 0, b = 2e9;
        for (int j=0;j<(int)e[i].size();j++){
            b = min(b, e[i][j].t+n-e[i][j].e);
        }
        for (int j=0;j<n;j++){
            if (pt<(int)e[i].size() && e[i][pt].e==j){
                b = min(b, e[i][pt].t);
                pt++;
            }
            dist[i][j] = b;
            b++;
        }
    }
    /*printf("\n");
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++) printf("%d ", dist[i][j]);
        printf("\n");
    }
    printf("\n");*/
    for (int s=0;s<n;s++){
        fill(ans[s], ans[s]+n, 2e9);
        ans[s][s] = 0;
        for (int z=0;z<n;z++){
            int val = 2e9, v = -1;
            for (int i=0;i<n;i++) if (!visited[s][i] && ans[s][i]<val) val = ans[s][i], v = i;
            visited[s][v] = 1;
            for (int i=0;i<n;i++) if (!visited[s][i]) {
                ans[s][i] = min(ans[s][i], ans[s][v]+dist[v][(n+i-(ans[s][v]%n))%n]);
            }
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++) printf("%d ", ans[i][j]);
        printf("\n");
    }
    return 0;
}