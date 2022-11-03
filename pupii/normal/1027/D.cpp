// It is made by XZZ
#include<bits/stdc++.h>
#define int long long
#define il inline
#define rg register
#define vd void
#define sta static
typedef long long ll;
using namespace std;
il int gi(){
    rg int x=0,f=1;rg char ch=getchar();
    while(ch<'0'||ch>'9')f=ch=='-'?-1:f,ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int w[200010],d[200010],dfn[200010],low[200010];
int stk[200010],tp,ins[200010];
int ans=0;
il vd tarjan(int x){
    stk[++tp]=x;
    dfn[x]=low[x]=++dfn[0];ins[x]=1;
    if(dfn[d[x]]){if(ins[d[x]])low[x]=std::min(low[x],dfn[d[x]]);}
    else tarjan(d[x]),low[x]=std::min(low[x],low[d[x]]);
    if(dfn[x]==low[x]){
        if(stk[tp]==x&&d[x]!=x){ins[x]=0;--tp;return;}
        int mn=1e18;
        while(stk[tp+1]!=x){
            mn=std::min(mn,w[stk[tp]]);
            ins[stk[tp]]=0;--tp;
        }
        ans+=mn;
    }
}
main(){
    int n=gi();
    for(int i=1;i<=n;++i)w[i]=gi();
    for(int i=1;i<=n;++i)d[i]=gi();
    for(int i=1;i<=n;++i){
        if(dfn[i])continue;
        tp=0;
        tarjan(i);
    }
    printf("%lld\n",ans);
    return 0;
}