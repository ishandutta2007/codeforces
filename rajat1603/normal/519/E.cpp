#include<bits/stdc++.h>
using namespace std;
const int N = 100001;
const int LN = 17;
list<int> v[N];
int dp[LN][N];
int subtree[N];
int depth[N];
int logtable[N];
int n,q;
void dfs(int node,int parent){
    subtree[node]=1;
    dp[0][node]=parent;
    for(list<int>::iterator it = v[node].begin();it!=v[node].end();++it){
        if(*it!=parent){
            depth[*it]=depth[node]+1;
            dfs(*it,node);
            subtree[node]+=subtree[*it];
        }
    }
}
int up(int downnode,int dist){
    while(dist){
        downnode = dp[logtable[dist&-dist]][downnode];
        dist&=dist-1;
    }
    return downnode;
}
int lca(int a,int b){
    int dif = depth[a]-depth[b];
    a = up(a,dif);
    if(a==b){
        return a;
    }
    for(int i=LN-1;i>=0;--i){
        if(dp[i][a]!=dp[i][b]){
            a = dp[i][a];
            b = dp[i][b];
        }
    }
    return dp[0][a];
}
int solve(int a,int b){
    if(a==b){
        return n;
    }
    if(depth[a]<depth[b]){
        swap(a,b);
    }
    int lc = lca(a,b);
    int dist = depth[a] + depth[b] - (depth[lc]<<1);
    if(dist&1){
        return 0;
    }
    if(depth[a] - depth[lc] == depth[b] - depth[lc] ){
        int A = up(a,depth[a] - depth[lc] - 1 );
        int B = up(b,depth[b] - depth[lc] - 1 );
        return n - subtree[A] - subtree[B];
    }
    int x = up(a,(dist>>1)-1);
    int y = dp[0][x];
    return subtree[y] - subtree[x];
}
int main(){
    scanf("%d",&n);
    logtable[0]=-1;
    for(int i=1;i<n;++i){
        int a,b;
        scanf("%d %d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
        logtable[i]=logtable[i-1];
        if((i&-i)==i){
            logtable[i]++;
        }
    }
    logtable[n]=logtable[n-1]+(n&-n)==n;
    memset(dp,-1,sizeof(int)*LN*N);
    depth[1]=0;
    dfs(1,-1);
    scanf("%d",&q);
    for(int i=1;i<LN;++i){
        for(int j=1;j<=n;++j){
            if(dp[i-1][j]!=-1){
                dp[i][j]=dp[i-1][dp[i-1][j]];
            }
        }
    }
    while(q--){
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%d\n",solve(a,b));
    }
}