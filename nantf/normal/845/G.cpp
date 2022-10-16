#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct edge{
    int to,nxt;
    ll w;
}e[200020];
struct linear_base{
    ll d[64];
    void insert(ll x){
        for(int i=62;~i;i--)
            if(x&(1ll<<i)){
                if(!d[i]){
                    d[i]=x;return;
                }
                x^=d[i];
            }
    }
    ll query(ll x){
        for(int i=62;~i;i--) if(x&(1ll<<i)) x^=d[i];
        return x;
    }
}AONYAPAEEMIA;
int n,m,el,head[200020];
ll val[200020];
bool vis[200020];
inline void add(int u,int v,ll w){
    e[++el]=(edge){v,head[u],w};
    head[u]=el;
}
void dfs(int u,int f){
    vis[u]=true;
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].to;
        if(v==f) continue;
        if(vis[v]){
            AONYAPAEEMIA.insert(val[u]^val[v]^e[i].w);continue;
        }
        val[v]=val[u]^e[i].w;
        dfs(v,u);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v;
        ll w;
        scanf("%d%d%lld",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }
    dfs(1,0);
    printf("%lld\n",AONYAPAEEMIA.query(val[n]));
}
// orz CDW IOI AK