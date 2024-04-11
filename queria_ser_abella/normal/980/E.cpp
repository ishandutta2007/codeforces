#include <bits/stdc++.h>
#define maxn 1001000
using namespace std;
#define pb push_back
#define pii pair<int,int>
#define pip pair<ll,pii>
#define debug 
#define ll long long

int add[maxn];
int pai[maxn];
vector<int> L[maxn];
int dp[22][maxn];

void dfs(int v,int p=0){
    pai[v] = p;
    dp[0][v] = p;
    for(int i=1;i<22;i++)
        dp[i][v] = dp[i-1][dp[i-1][v]];
    for(int i=0;i<L[v].size();i++)
        if(L[v][i] != p)
            dfs(L[v][i],v);
}

int lift(int x,int k){
    for(int i=21;i>=0;i--)
        if(k & (1<<i))
            x = dp[i][x];
    return x;
}

main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b), a--,  b--;
        L[a].pb(b);
        L[b].pb(a);
    }
    dfs(n-1,n-1);
    int has = n-k;
    for(int i=n-1;i>=0;i--){
       if(add[i])
           continue;
       int u = lift(i,has);
       if(u != n-1 && !add[u]) continue;
       int vx = i;
       while(!add[vx]){
           add[vx] = 1;
          // printf("i %d add %d\n",i+1,vx+1);
           has--;
           vx = pai[vx];
       }
    }
    
    for(int i=0;i<n;i++)
        if(!add[i])
            printf("%d ",i+1);
    
}