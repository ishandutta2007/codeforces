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
int vis[101000];
int low[101000],h[101000];
int pts[101000],ptc;
int sccid[101000],scc=0;
vector<int> tre[101000];
inline void dfs(int np,int p,int hh){
    vis[np]=1;
    h[np]=hh;
    low[np]=hh;
    pts[ptc++]=np;
    int i;
    for(i=0;i<ed[np].size();i++){
        int y=ed[np][i];
        if(y==p)continue;
        if(vis[y]){
            low[np]=min(low[np],h[y]);
        }else{
            dfs(y,np,hh+1);
            low[np]=min(low[np],low[y]);
        }
    }
    //printf("low[%d]=%d h=%d\n",np+1,low[np],h[np]);
    if(low[np]==hh){
        //puts("!");
        while(pts[ptc-1]!=np){
            //printf("%d ",pts[ptc-1]);
            sccid[pts[ptc-1]]=scc;
            ptc--;
        }
        //printf("%d\n",np);
        ptc--;
        sccid[np]=scc;
        scc++;
    }
}
int dfso[201000],dc=0;
int et[101000];
int ht[101000];
inline void dfs2(int np,int p,int h){
    //printf("np=%d %d\n",np,p);
    ht[np]=h;
    int i;
    et[np]=dc;
    dfso[dc++]=np;
    for(i=0;i<tre[np].size();i++){
        int y=tre[np][i];
        if(y!=p){
            dfs2(y,np,h+1);
            dfso[dc++]=np;
        }
    }
}
int rmq[20][201000];
int logt[201000];
inline int rmqf(int a,int b){
    if(a>b)swap(a,b);
    int k=logt[b-a+1];
    int x=rmq[k][a],y=rmq[k][b-(1<<k)+1];
    if(ht[x]<ht[y])return x;
    else return y;
}
int main(){
    int n,m,i,j;
    logt[1]=0;
    for(i=2;i<201000;i++)logt[i]=logt[i/2]+1;
    scanf("%d%d",&n,&m);
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        a--;b--;
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    dfs(0,-1,1);
    for(i=0;i<n;i++){
        //printf("%d %d\n",i,sccid[i]);
        for(j=0;j<ed[i].size();j++){
            int y=ed[i][j];
            if(sccid[i]!=sccid[y]){
                tre[sccid[i]].push_back(sccid[y]);
                //printf("%d->%d\n",sccid[i],sccid[y]);
            }
        }
    }
    dfs2(0,-1,0);
    for(i=0;i<dc;i++)rmq[0][i]=dfso[i];
    for(i=1;(1<<i)<=dc;i++){
        for(j=0;j+(1<<i)<=dc;j++){
            int a=rmq[i-1][j],b=rmq[i-1][j+(1<<(i-1))];
            if(ht[a]>ht[b])rmq[i][j]=b;
            else rmq[i][j]=a;
        }
    }
    int k;
    scanf("%d",&k);
    while(k--){
        int a,b;
        scanf("%d%d",&a,&b);
        a--;b--;
        a=sccid[a];b=sccid[b];
        int c=rmqf(et[a],et[b]);
        printf("%d\n",ht[a]+ht[b]-2*ht[c]);
    }
}