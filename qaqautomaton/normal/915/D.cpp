#include<bits/stdc++.h>
using namespace std;
int to[102424],lst[102424],beg[512],e;
void add(int u,int v){
    to[++e]=v;
    lst[e]=beg[u];
    beg[u]=e;
}
int dfn[512],low[512],t;
int ins[512],stk[512],top,cc;
int col[512];
void chkmin(int &a,int b){
    if(a>b)a=b;
}
void dfs(int x){
    dfn[x]=low[x]=++t;
    ins[x]=1;
    stk[++top]=x;
    for(int i=beg[x];i;i=lst[i])
    if(!dfn[to[i]]){
        dfs(to[i]);
        chkmin(low[x],low[to[i]]);
    }
    else if(ins[to[i]])chkmin(low[x],dfn[to[i]]);
    if(dfn[x]==low[x]){
        if(stk[top]!=x){
            if(++cc>1){
                printf("NO\n");
                exit(0);
            }
            while(stk[top+1]!=x){
                col[stk[top]]=1;
                ins[stk[top]]=0;
                --top;
            }
        }
        else{ins[x]=0;--top;}
    }
}
int gra[512][512],vis[512];
int n,m,u,v;
int dfss(int x){
    stk[++top]=x;
    vis[x]=1;
    for(int i=1;i<=n;++i)if(col[i]&&gra[x][i]){
        if(vis[i]==0){
            if(dfss(i))return 1;
        }
        else if(vis[i]==1)return 1;
    }
    vis[x]=2;
    --top;
    return 0;
}
int ddfs(int x){
    vis[x]=1;
    for(int i=1;i<=n;++i)if(col[i]&&gra[x][i]){
        if(vis[i]==0){
            if(ddfs(i))return 1;
        }
        else if(vis[i]==1){cc=1;return 1;}
    }
    vis[x]=2;
    return 0;
}

int main(){
    scanf("%d%d",&n,&m);
    while(m){
        scanf("%d%d",&u,&v);
        add(u,v);
        gra[u][v]=1;
        --m;
    }
    for(int i=1;i<=n;++i)if(!dfn[i])dfs(i);
    //printf("%d\n",cc);
    if(!cc)printf("YES\n");
    else{
        int i=1;
        top=0;
        while(!col[i])++i;
        dfss(i);
        int nx;
        //printf("%d\n",top);
        for(i=1;i<=top;++i){
          //  printf("%d%c",stk[i],i==top?'\n':' ');
            nx=i%top+1;
            gra[stk[i]][stk[nx]]=0;
            for(int j=1;j<=n;++j)vis[j]=0;
            cc=0;
            for(int j=1;j<=n&&!cc;++j)if(col[j]&&!vis[j]){
                ddfs(j);
            }
            if(!cc){
                printf("YES\n");
                return 0;
            }
            gra[stk[i]][stk[nx]]=1;
        }
        printf("NO\n");
    }        
	return 0;
}