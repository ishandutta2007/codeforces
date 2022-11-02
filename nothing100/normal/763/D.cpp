#include<bits/stdc++.h>
#define mo 1000000007
#define ws 100003
#define cws 443036712
#define LL long long
#define MAXN 100010
using namespace std;
vector<int> edge[MAXN];
int n,siz[MAXN],tot,ans,anss;
map<LL,int>ex;
LL hab[MAXN],haa[MAXN],cf[MAXN],ny[MAXN];
int cmp(int x,int y){
    return hab[x]<hab[y];
}
void dfs1(int x,int y){
    hab[x]=mo;
    for (int i=0;i<edge[x].size();i++)
    if (edge[x][i]!=y) dfs1(edge[x][i],x);
    sort(edge[x].begin(),edge[x].end(),cmp);
    for (int i=0;i<edge[x].size();i++){
        hab[x]=(hab[x]+hab[edge[x][i]]*cf[siz[x]])%mo;
        siz[x]+=siz[edge[x][i]];
    }
    hab[x]=(hab[x]+cf[siz[x]]*(siz[x]+1))%mo;
    tot+=(ex[hab[x]]==0);
    ex[hab[x]]++;
    siz[x]++;
    return;
}
void dfs2(int x,int y,LL z){
    if (z!=mo){
        tot+=(ex[z]==0);
        ex[z]++;
    }
    ex[hab[x]]--;
    tot-=(ex[hab[x]]==0);
    int bo=0,now=0;
    for (int i=0;i<edge[x].size();i++)
    if (edge[x][i]!=y){
        if (!bo&&z<hab[edge[x][i]]){
            bo=1;
            haa[x]=(haa[x]+z*cf[now])%mo;
            now+=(n-siz[x]);
        }
        haa[x]=(haa[x]+hab[edge[x][i]]*cf[now])%mo;
        now+=siz[edge[x][i]];
    }
    if (!bo){
        bo=1;
        haa[x]=(haa[x]+z*cf[now])%mo;
        now+=(n-siz[x]);
    }
    haa[x]=(haa[x]+n*cf[now])%mo;
    now++;
    tot+=(ex[haa[x]]==0);
    ex[haa[x]]++;
    if (tot>ans){
        ans=tot;
        anss=x;
    }
    LL num=(haa[x]-n*cf[n-1])%mo,tmp=0;
    now=bo=0;
    for (int i=0;i<edge[x].size();i++)
    if (edge[x][i]!=y){
        ex[haa[x]]--;
        tot-=(ex[haa[x]]==0);
        if (!bo&&z<hab[edge[x][i]]){
            num=(num-z*cf[now])%mo;
            tmp=(tmp+z*cf[now])%mo;
            now+=n-siz[x];
            bo=1;
        }
        num=(num-hab[edge[x][i]]*cf[now])%mo;
        dfs2(edge[x][i],x,((num*ny[siz[edge[x][i]]]+tmp+(n-siz[edge[x][i]])*cf[n-siz[edge[x][i]]-1])%mo+mo)%mo);
        tmp=(tmp+hab[edge[x][i]]*cf[now])%mo;
        now+=siz[edge[x][i]];
        tot+=(ex[haa[x]]==0);
        ex[haa[x]]++;
    }
    if (z!=mo){
        ex[z]--;
        tot-=(ex[z]==0);
    }
    tot+=(ex[hab[x]]==0);
    ex[hab[x]]++;
    ex[haa[x]]--;
    tot-=(ex[haa[x]]==0);
}
int main(){
    scanf("%d",&n);
    cf[0]=1;
    ny[0]=1;
    for (int i=1;i<=n;i++) cf[i]=(cf[i-1]*ws)%mo;
    for (int i=1;i<=n;i++) ny[i]=(ny[i-1]*cws)%mo;
    for (int i=1;i<n;i++){
        int o,p;
        scanf("%d%d",&o,&p);
        edge[o].push_back(p);
        edge[p].push_back(o);
    }
    dfs1(1,0);
    dfs2(1,0,mo);
    printf("%d\n",anss);
}