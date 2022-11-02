#include <bits/stdc++.h>
#define pii pair<ll,ll>
#define pb push_back
#define maxn 300300
#define ll long long
#define debug 
using namespace std;

int foic[maxn];
int foir[maxn];

vector<int> L[maxn];
int vis[maxn];

void dfs(int x){
    vis[x] = 1;
    for(int i=0;i<L[x].size();i++)
        if(!vis[L[x][i]])
            dfs(L[x][i]);
}


int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    if(k == 0){
        printf("%d\n",n+m-1);
        return 0;
    }
    int fc = 0, fr = 0;
    for(int i=0;i<k;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        if(foic[x]){
            //debug("")
            L[y].pb(foic[x]);
            L[foic[x]].pb(y);
        }
        foic[x] = y;
        foir[y] = x;
        
    }
    
    for(int i=1;i<=n;i++)
        if(!foic[i]) fc++;
    for(int i=1;i<=m;i++){
        debug("%d ",foir[i]);
        if(!foir[i]) fr++;
    }
    debug("!%d %d\n",fc,fr);
    int ans = fc+fr;
    //if(fc >= 1 && fr >= 1) ans--;
    int f = 0;
    for(int i=1;i<=m;i++)
        if(foir[i] && !vis[i]){
            ans++;
            f++;
            if(f == 1) ans--;
            debug("dfs %d\n",i);
            dfs(i);
        }
    printf("%d\n",ans);
    
}