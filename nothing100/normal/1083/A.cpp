#include<bits/stdc++.h>
#define mp make_pair
#define LL long long
using namespace std;
int n,w[300030];
LL ans;
vector<pair<int,int> > edge[300030];
LL dfs(int x,int y){
    LL res=0;
    for (int i=0;i<edge[x].size();i++)
    if (edge[x][i].first!=y){
        LL tmp=dfs(edge[x][i].first,x)-edge[x][i].second;
        ans=max(ans,tmp+res+w[x]);
        res=max(tmp,res);
    }
    ans=max(ans,res+w[x]);
    return max(res+w[x],1LL*w[x]);
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&w[i]);
    for (int i=1;i<n;i++){
        int o,p,t;
        scanf("%d%d%d",&o,&p,&t);
        edge[o].push_back(mp(p,t));
        edge[p].push_back(mp(o,t));
    }
    dfs(1,0);
    printf("%lld\n",ans);
}