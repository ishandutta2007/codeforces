#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<time.h>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> ed[101000];
vector<int> bed[101000];
int val[101000];
int vis[101000];
inline void dfs(int np){
    if(vis[np]&1)return;
    vis[np]|=1;
    int i;
    for(i=0;i<ed[np].size();i++){
        int y=ed[np][i];
        dfs(y);
    }
}
inline void dfs2(int np){
    if(vis[np]&2)return;
    vis[np]|=2;
    if(val[np]==1)return;
    int i;
    for(i=0;i<bed[np].size();i++){
        int y=bed[np][i];
        dfs2(y);
    }
}
int main(){
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%d",&val[i]);
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        a--;b--;
        ed[a].push_back(b);
        bed[b].push_back(a);
    }
    for(i=0;i<n;i++)if(val[i]==1&&!(vis[i]&1)){
        dfs(i);
    }
    for(i=0;i<n;i++)if(val[i]==2&&!(vis[i]&2)){
        dfs2(i);
    }
    for(i=0;i<n;i++)printf("%d\n",vis[i]==3?1:0);
}