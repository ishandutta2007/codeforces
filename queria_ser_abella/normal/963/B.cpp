#include <bits/stdc++.h>
#define maxn 300300
using namespace std;
#define pb push_back
#define pii pair<int,int>
#define debug 
#define ll long long

vector<int> ans;
int foi[maxn];
vector<int> L[maxn];
int p[maxn];

void dfs(int x,int p=0,int f=0){
    
    if(f){
        if(foi[x])
            return;
        ans.pb(x);
        foi[x] = 1;
        for(int i=0;i<L[x].size();i++)
            if(L[x][i] != p) dfs(L[x][i],x,1);
        return;
    }
    
    int dg = 0 ;
    if(x != p) dg++;
    for(int i=0;i<L[x].size();i++){
        if(L[x][i] == p) continue;
        dfs(L[x][i],x,0);
        if(!foi[L[x][i]])
            dg++;
    }
    
    if(dg%2 == 0){
        dfs(x,p,1);
    }
}

main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",p+i), p[i]--;
        if(p[i] == -1)
            continue;
        L[p[i]].pb(i);
        L[i].pb(p[i]);
    }
    dfs(0);
    if(ans.size() < n)
        printf("NO\n");
    else {
        printf("YES\n");
        for(int i=0;i<n;i++)
            printf("%d ",ans[i]+1);
    }
        
    }