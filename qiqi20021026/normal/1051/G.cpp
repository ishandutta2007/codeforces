#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define N 420000
#define M 200000LL

LL n,x,y,ans,tot,sum[N*30],num[N*30],ls[N*30],rs[N*30],ctb[N*30],len[N],rt[N];
set<LL> se;

inline void upd(LL x){
    num[x]=num[ls[x]]+num[rs[x]];
    sum[x]=sum[ls[x]]+sum[rs[x]];
    ctb[x]=ctb[ls[x]]+ctb[rs[x]]+sum[ls[x]]*num[rs[x]];
}
void ins(LL &x,LL l,LL r,LL t){
    if (!x) x=++tot;
    if (l==r){++num[x]; sum[x]+=t; return;}
    LL mid=(l+r)>>1;
    if (t<=mid) ins(ls[x],l,mid,t);
    else ins(rs[x],mid+1,r,t);
    upd(x);
}

LL merge(LL x,LL y,LL l,LL r){
    if (!x||!y) return x|y;
    LL mid=(l+r)>>1;
    ls[x]=merge(ls[x],ls[y],l,mid);
    rs[x]=merge(rs[x],rs[y],mid+1,r);
    upd(x);
    return x;
}

void comb(LL x){
    auto i=se.upper_bound(x);
    if (i==se.end()) return;
    LL t=*i;
    if (!len[t]||x+len[x]-1<t-1) return;
    ans-=sum[rt[x]]*x+ctb[rt[x]]+sum[rt[t]]*t+ctb[rt[t]];
    rt[x]=merge(rt[x],rt[t],1,M);
    ans+=sum[rt[x]]*x+ctb[rt[x]];
    rt[t]=0; len[x]+=len[t]; len[t]=0;
    se.erase(t);
    i=se.upper_bound(x);
    if (i==se.end()) return;
    t=*i;
    if (!len[t]||x+len[x]-1<t-1) return;
    comb(x);
}

int main(){
    scanf("%lld",&n);
    for (LL i=1;i<=n;++i){
        scanf("%lld%lld",&x,&y);
        ans-=x*y;
        ans-=sum[rt[x]]*x+ctb[rt[x]];
        ins(rt[x],1,M,y);
        ans+=sum[rt[x]]*x+ctb[rt[x]];
        se.insert(x); ++len[x];
        comb(x);
        auto t=se.lower_bound(x);
        if (t!=se.begin()) comb(*(--t));
        printf("%lld\n",ans);
    }

    return 0;
}