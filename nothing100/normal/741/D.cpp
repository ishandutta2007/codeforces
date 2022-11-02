#include<bits/stdc++.h>
#define MAXN 500010
#define inf 1e+15
using namespace std;
struct edge{
    int point,next,f;
}b[2*MAXN];
int n,g[MAXN],tot,size[MAXN],ans[MAXN],path[1<<22],de[MAXN],bo[1<<22];
void build(int x,int y,int z){
    b[++tot].point=y; b[tot].next=g[x]; b[tot].f=z; g[x]=tot;
    b[++tot].point=x; b[tot].next=g[y]; b[tot].f=z; g[y]=tot;
}
void dfs(int x,int y){
    size[x]++;
    for (int i=g[x];i;i=b[i].next)
    if (b[i].point!=y){
        dfs(b[i].point,x);
        size[x]+=size[b[i].point];
    }
}
void clear(int x,int y,int z){
    bo[z]=0;
    for (int i=g[x];i;i=b[i].next)
    if (b[i].point!=y) clear(b[i].point,x,z^b[i].f);
}
void add(int x,int y,int len,int now,int wh){
    for (int i=0;i<22;i++)
    if (bo[wh^(1<<i)]) ans[now]=max(ans[now],path[wh^(1<<i)]+len+de[now]);
    if (bo[wh]) ans[now]=max(ans[now],path[wh]+len+de[now]);
    for (int i=g[x];i;i=b[i].next)
    if (b[i].point!=y) add(b[i].point,x,len+1,now,wh^b[i].f);
}
void ins(int x,int y,int len,int now,int wh){
    if (bo[wh]) path[wh]=max(len-de[now],path[wh]);
    else{
        bo[wh]=1;
        path[wh]=len-de[now];
    }
    for (int i=g[x];i;i=b[i].next)
    if (b[i].point!=y) ins(b[i].point,x,len+1,now,wh^b[i].f);
}
int redfs(int x,int y,int z){
    int big=0,mx=0,tmp=0;
    for (int i=g[x];i;i=b[i].next)
    if (b[i].point!=y&&size[b[i].point]>mx){
        mx=size[b[i].point];
        big=b[i].point;
        tmp=b[i].f;
    }
    for (int i=g[x];i;i=b[i].next)
    if (b[i].point!=y&&b[i].point!=big) redfs(b[i].point,x,0);
    if (big!=0){
        tmp^=redfs(big,x,1);
        de[x]=de[big]+1;
    }
    for (int i=g[x];i;i=b[i].next)
    if (b[i].point!=y) ans[x]=max(ans[x],ans[b[i].point]);
    if (bo[tmp]) path[tmp]=max(path[tmp],-de[x]);
    else{
        path[tmp]=-de[x];
        bo[tmp]=1;
    }
    for (int i=g[x];i;i=b[i].next)
    if (b[i].point!=y&&b[i].point!=big){
        add(b[i].point,x,1,x,tmp^b[i].f);
        ins(b[i].point,x,1,x,tmp^b[i].f);
    }
    for (int i=0;i<22;i++)
    if (bo[(1<<i)^tmp]) ans[x]=max(ans[x],path[(1<<i)^tmp]+de[x]);
    ans[x]=max(ans[x],path[tmp]+de[x]);
    if (!z) clear(x,y,tmp);
    return tmp;
}
int main(){
    scanf("%d",&n);
    for (int i=2;i<=n;i++){
        int o;
        char p;
        scanf("%d%c%c",&o,&p,&p);
        build(i,o,1<<(p-'a'));
    }
    dfs(1,0);
    redfs(1,0,1);
    for (int i=1;i<=n;i++) printf("%d ",ans[i]);
    printf("\n");
}