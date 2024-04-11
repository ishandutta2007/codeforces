#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define getchar_unlocked getchar //for codeforces
using namespace std;
inline int scan(){
    char c = getchar_unlocked();
    int x = 0;
    while(c<'0'||c>'9'){
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+c-'0';
        c=getchar_unlocked();
    }
    return x;
}
const int N = 110001;
const int LN = 18;
list<int> v[N];
vector<int> level[N];
int dp[LN][N];
int start[N];
int finish[N];
int logtable[N];
int depth[N];
int timer=0;
int n,q;
void dfs(int node,int lvl,int parent){
    start[node]=++timer;
    list<int>::iterator it;
    level[lvl].pb(start[node]);
    dp[0][node]=parent;
    for(it=v[node].begin();it!=v[node].end();++it){
       dfs(*it,lvl+1,node);
    }
    depth[node]=lvl;
    finish[node]=timer;
}
void init(){
    for(int i=1;i<LN;++i){
        for(int j=1;j<=n;++j){
            if(dp[i-1][j]!=-1){
                dp[i][j]=dp[i-1][dp[i-1][j]];
            }
        }
    }
}
int ancestor(int node,int k){
    while(k){
        if(node==-1){
            return -1;
        }
        node = dp[logtable[k&-k]][node];
        k&=k-1;
    }
    return node;
}
int solve(int node,int dist){
    if(node<=0){
        return 1;
    }
    if(dist+depth[node]>=n){
        return 1;
    }
    return upper_bound(level[dist+depth[node]].begin(),level[dist+depth[node]].end(),finish[node])-lower_bound(level[dist+depth[node]].begin(),level[dist+depth[node]].end(),start[node]);
}
int main(){
    n=scan();
    logtable[0]=-1;
    for(int i=1;i<=n;++i){
        int parent=scan();
        v[parent].pb(i);
        for(int j=0;j<LN;++j){
            dp[j][i]=-1;
        }
        logtable[i]=logtable[i-1];
        if((i&-i)==i){
            logtable[i]++;
        }
    }
    dfs(0,1,-1);
    init();
    int q=scan();
    for(int i=1;i<=n;++i){
        sort(level[i].begin(),level[i].end());
    }
    while(q--){
        int node=scan(),k=scan();
        int anc = ancestor(node,k);
        printf("%d ",solve(anc,k)-1);
    }
}