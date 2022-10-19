#include<bits/stdc++.h>
using namespace std;

const int maxn=200007;
int n,m,k;
int d[maxn],p[maxn];
bool vis[maxn];
vector<int> vec[maxn],rev[maxn];
void bfs(int u){
    memset(vis,0,sizeof(vis));
    queue<int> q;
    while (q.size()) q.pop();
    q.push(u);
    for (int i=1;i<=n;++i) d[i]=1e9;
    vis[u]=1;
    d[u]=0;
    while (q.size()){
        int x=q.front();
        q.pop();
        for (auto c:vec[x]){
            if (vis[c]) continue;
            vis[c]=1;
            d[c]=d[x]+1;
            q.push(c);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;++i){
        int u,v;
        cin>>u>>v;
        vec[v].push_back(u);
        rev[u].push_back(v);
    }
    cin>>k;
    for (int i=1;i<=k;++i){
        cin>>p[i];
    }
    bfs(p[k]);
    int mn=0,mx=0;
    for (int i=1;i<k;++i){
        for (auto c:rev[p[i]]){
            if (d[c]<d[p[i]]&&c!=p[i+1]){
                mx++;
                break;
            }
        }
        if (d[p[i]]<=d[p[i+1]]) mn++; 
    }
    cout<<mn<<" "<<mx;
    return 0;
}