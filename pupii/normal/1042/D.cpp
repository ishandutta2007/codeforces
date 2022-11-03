#include<bits/stdc++.h>
#define il inline
#define vd void
#define int long long
#define ll long long
il int gi(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int a[200010];
int A[200010];
int G[400010],m,cnt;
std::set<int>S;
int t[400010];
il vd update(int x){while(x<=m)++t[x],x+=x&-x;}
il int query(int x){
    int ret=0;
    while(x)ret+=t[x],x-=x&-x;
    return ret;
}
main(){
    int n=gi(),t=gi(),ans=0;
    for(int i=1;i<=n;++i)a[i]=gi(),A[i]=A[i-1]+a[i];
    for(int i=1;i<=n;++i)G[++cnt]=A[i];
    G[++cnt]=0;
    std::sort(G+1,G+cnt+1);m=std::unique(G+1,G+cnt+1)-G-1;
    for(int i=1;i<=m;++i)if(G[i]==0)update(i);
    for(int i=1;i<=n;++i)A[i]=std::lower_bound(G+1,G+cnt+1,A[i])-G;
    for(int i=1;i<=n;++i){
        int p=std::upper_bound(G+1,G+cnt+1,G[A[i]]-t)-G-1;
        ans+=i-query(p);
        update(A[i]);
    }
    printf("%lld\n",ans);
    return 0;
}