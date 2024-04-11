#include <bits/stdc++.h>
using namespace std;

typedef pair<int,long long> P;
typedef pair<P,long long> Pi;
long long c[501][501];
const long long INF=1e12;
long long d1[501];
long long d2[501];
long long dist[501];
bool vis[501];

int main() {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n,m;
        scanf("%d %d",&n,&m);
        vector<Pi> edge;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                c[i][j]=INF;
            }
        }
        for(int i=0;i<m;i++) {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            edge.push_back(Pi(P(u,v),w));
            c[u][v]=min(c[u][v],(long long)w);
            c[v][u]=min(c[v][u],(long long)w);
        }
        for(int i=1;i<=n;i++) {
            d1[i]=INF;
            d2[i]=INF;
        }
        d1[1]=0;
        d2[n]=0;
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int now=q.front();
            q.pop();
            for(int i=1;i<=n;i++) {
                if (c[now][i]!=INF&&d1[i]==INF) {
                    d1[i]=d1[now]+1;
                    q.push(i);
                }
            }
        }
        q.push(n);
        while (!q.empty()) {
            int now=q.front();
            q.pop();
            for(int i=1;i<=n;i++) {
                if (c[now][i]!=INF&&d2[i]==INF) {
                    d2[i]=d2[now]+1;
                    q.push(i);
                }
            }
        }
        long long ret=INF;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                //printf("%d %d %lld %lld %lld\n",i,j,c[i][j],d1[i],d2[j]);
                if (i!=j&&c[i][j]!=INF) {
                    ret=min(ret,c[i][j]*(d1[i]+d2[j]+1));
                }
            }
        }
        for(int i=1;i<=n;i++) {
            //printf(".%d %d\n",i,d1[i]+d2[i]+1);
            c[0][i]=d1[i]+d2[i]+1;
            c[i][0]=c[0][i];
            dist[i]=INF;
        }
        dist[0]=0;
        for(int i=0;i<=n;i++) {
            int st;
            long long mn=INF+7;
            for(int j=0;j<=n;j++) {
                if (!vis[j]&&dist[j]<mn) {
                    mn=dist[j];
                    st=j;
                }
            }
            for(int j=0;j<=n;j++) {
                if (c[st][j]>=INF) {
                    continue;
                }
                long long cost;
                if (j==0||st==0) {
                    cost=c[st][j];
                }
                else {
                    cost=1;
                }
                dist[j]=min(dist[j],dist[st]+cost);
            }
            vis[st]=true;
        }
        for(int i=1;i<=n;i++) {
            long long mc=INF;
            for(int j=1;j<=n;j++) {
                mc=min(mc,c[i][j]);
            }
            //printf("%d %lld %d\n",i,mc,dist[i]);
            ret=min(ret,mc*(dist[i]+1));
        }
        printf("%lld\n",ret);
    }
    return 0;
}