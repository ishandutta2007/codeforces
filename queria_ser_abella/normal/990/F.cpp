#include <bits/stdc++.h>
#define ll long long
#define maxn 200200
#define pii pair<int,int>
#define pb push_back
#define left ifushf
using namespace std;

int val[maxn];
int ans[maxn];
int foi[maxn];

vector<pii> L[maxn];

int dfs(int v,int p,int edge){
    
    foi[v] = 1;
    int f = L[v].size();
    if(p != v) f--;
    
    if(v == p && f == 0){
        if(val[v] == 0)
            return 0;
        printf("Impossible\n");
        exit(0);
        return 0;
        
    }
    
    if(f == 0){
        if(edge > 0)
            ans[edge] = val[v];
        else
            ans[-edge] = -val[v];
        return val[v];
    }
    
    int s = 0;
    for(int i=0;i<(int)L[v].size();i++){
        if(L[v][i].first == p || foi[L[v][i].first]) continue;
        s += dfs(L[v][i].first,v,L[v][i].second);
    }
    
    if(edge == 0){
        if(val[v] + s != 0){
            printf("Impossible\n");
            exit(0);
        }
        return 0;
    }
    
    if(edge > 0)
        ans[edge] = (val[v]+s);
    else
        ans[-edge] = -(val[v]+s);
    return (val[v]+s);
    
}

int main(){
    int n,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",val+i);
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%d%d",&a,&b), a--, b--;
        L[a].pb(pii(b,i));
        L[b].pb(pii(a,-i));
    }
    for(int i=0;i<n;i++)
        if(!foi[i]){
            dfs(i,i,0);
        }
    printf("Possible\n");
    for(int i=1;i<=m;i++)
        printf("%d\n",ans[i]);
}