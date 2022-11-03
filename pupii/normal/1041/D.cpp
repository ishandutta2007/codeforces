#include<bits/stdc++.h>
#define il inline
#define vd void
#define int long long
#define ll long long
il int gi(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int a[200010],b[200010],c[200010];
il int check(int l,int r){return c[r]-c[l];}
main(){
    int n=gi(),h=gi();
    for(int i=1;i<=n;++i)a[i]=gi(),b[i]=gi();
    for(int i=2;i<=n;++i)c[i]=c[i-1]+a[i]-b[i-1];
    c[n+1]=2e9;
    int ans=0;
    for(int i=1;i<=n;++i){
        int l=i,r=n+1,mid;
        while(l<r){
            mid=(l+r)>>1;
            if(check(i,mid)<h)l=mid+1;
            else r=mid;
        }
        ans=std::max(ans,b[l-1]-a[i]+h-check(i,l-1));
    }
    printf("%lld\n",ans);
    return 0;
}