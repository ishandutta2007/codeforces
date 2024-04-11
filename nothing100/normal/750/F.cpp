#include<bits/stdc++.h>
#define MAXN 200010
#define inf 1000000000
using namespace std;
int t,n,dep[200],que[200],pre[200],necc[200],ans,edge[200][5],tail,head,fir[200];
void build(int now){
    scanf("%d",&edge[now][0]);
    for (int i=1;i<=edge[now][0];i++){
        scanf("%d",&edge[now][i]);
        if (!necc[edge[now][i]]){
            fir[edge[now][i]]=fir[now]+1;
            que[++tail]=edge[now][i];
            pre[edge[now][i]]=now;
        }
    }
}
void ask(int now){
    necc[now]=1;
    printf("? %d\n",now);
    ans--;
    fflush(stdout);
}
void anss(int now){
    printf("! %d\n",now);
    fflush(stdout);
}
void nclear(int x,int y){
    necc[x]=1;
    for (int i=1;i<=edge[x][0];i++)
    if (edge[x][i]!=y) nclear(edge[x][i],x);
}
void check(int x){
    int h=0;
    for (int i=1;i<=edge[x][0];i++)
    if (dep[edge[x][i]]) h++;
    if (h==2)
    for (int i=1;i<=edge[x][0];i++)
    if (!dep[edge[x][i]]) dep[edge[x][i]]=dep[x]-1;
}
int dfs(int x,int y,int z){
    if (z==0) return 0;
    ask(x);
    build(x);
    if (edge[x][0]==2){
        anss(x);
        return 2;
    }
    if (edge[x][0]==1) return 1;
    for (int i=1;i<=edge[x][0];i++)
    if (edge[x][i]!=y){
        return dfs(edge[x][i],x,z-1);
    }
}
void solve(){
    memset(dep,0,sizeof(dep));
    memset(necc,0,sizeof(necc));
    memset(pre,0,sizeof(pre));
    memset(fir,0,sizeof(fir));
    memset(edge,0,sizeof(edge));
    que[1]=1;
    fir[1]=1;
    tail=1;
    head=0;
    while (head!=tail){
        head++;
        int now=que[head];
            if (!necc[now]){
                if (ans==0){
                    int tmp=now;
                    for (int i=head+1;i<=tail;i++)
                    if (!necc[que[i]]&&fir[que[i]]<fir[tmp]) tmp=que[i];
                    anss(tmp);
                    return;
                }
                else if (n==7&&dep[pre[pre[now]]]==4){
                    int o=dfs(now,pre[now],2);
                    if (o==1) nclear(pre[now],pre[pre[now]]);
                    else if (o==2) return;
                }
                else{
                    ask(now);
                    build(now);
                    if (edge[now][0]==2){
                        anss(now);
                        return;
                    }
                    if (edge[now][0]==1){
                        dep[now]=n;
                        while (pre[now]&&(!dep[pre[now]]||dep[pre[now]]==dep[now]-1)){
                            dep[pre[now]]=dep[now]-1;
                            check(pre[now]);
                            nclear(now,pre[now]);
                            now=pre[now];
                        }
                    }
                }
            }
    }
}
int main(){
    scanf("%d",&t);
    while (t--){
        ans=16;
        scanf("%d",&n);
        solve();
    }
}