#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
const int inf=1000000001;
vector<int>g[N][2];
vector<int>r[N][2];
int dist[N][2];
bool used[N];
int c[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;cin>>n>>m;
    for (int i=1;i<=m;i++){
        int a,b,t;cin>>a>>b>>t;
        g[a][t].push_back(b);
        r[b][t].push_back(a);
    }
    for (int i=1;i<=n;i++){
        dist[i][0]=dist[i][1]=inf;
    }
    dist[n][0]=dist[n][1]=0;
    set<pair<int,int> >st;
    for (int i=1;i<=n;i++){
        st.insert({max(dist[i][0],dist[i][1]),i});
    }
    while (!st.empty()){
        int v=(*st.begin()).second;
        st.erase(st.begin());
        int cur=max(dist[v][0],dist[v][1])+1;
        for (int i=0;i<2;i++){
            for (int to:r[v][i]){
                if (dist[to][i]>cur){
//                    cout<<to<<"
                    st.erase({max(dist[to][0],dist[to][1]),to});
                    dist[to][i]=cur;
                    st.insert({max(dist[to][0],dist[to][1]),to});
                }
            }
        }
    }
    cout<<(max(dist[1][0],dist[1][1])>=inf ? -1 : max(dist[1][0],dist[1][1]))<<endl;
    for (int i=1;i<=n;i++){
        c[i]=(dist[i][1]>dist[i][0]);
        cout<<c[i];
    }
    cout<<endl;

    return 0;
}