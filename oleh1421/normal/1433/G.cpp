#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=2010;
vector<pair<int,int> >g[N];
int a[N];
int b[N];
int dist[N][N];
const int inf=1000000001;
int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    int n,m,k;cin>>n>>m>>k;
    vector<pair<int,int> >edges;
    for (int i=1;i<=m;i++){
        int x,y,w;cin>>x>>y>>w;
        g[x].push_back({y,w});
        g[y].push_back({x,w});
        edges.push_back({x,y});
    }
    for (int i=1;i<=k;i++) cin>>a[i]>>b[i];
    for (int S=1;S<=n;S++){
        for (int i=1;i<=n;i++) dist[S][i]=inf;
        dist[S][S]=0;
        set<pair<int,int> >st;
        for (int i=1;i<=n;i++){
            st.insert({dist[S][i],i});
        }
        while (!st.empty()){
            int v=(*st.begin()).second;
//            cout<<S<<" "<<v<<endl;
            st.erase(st.begin());
            for (auto cur:g[v]){
                int to=cur.first,w=cur.second;
                if (dist[S][to]>dist[S][v]+w){
                    st.erase({dist[S][to],to});
                    dist[S][to]=dist[S][v]+w;
                    st.insert({dist[S][to],to});
                }
            }
        }

    }
    int res=inf;
    for (auto cur:edges){
        int sum=0;
        for (int i=1;i<=k;i++){
            sum+=min({dist[a[i]][b[i]],dist[a[i]][cur.first]+dist[cur.second][b[i]],dist[b[i]][cur.first]+dist[cur.second][a[i]]});
        }
        res=min(res,sum);
    }
    cout<<res<<endl;
    return 0;
}