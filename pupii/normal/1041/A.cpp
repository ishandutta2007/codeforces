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
ll a[1001];
main(){
    int n=gi();
    for(int i=1;i<=n;++i)a[i]=gi();
    std::sort(a+1,a+n+1);
    int ans=0;
    for(int i=1;i<n;++i)ans+=a[i+1]-a[i]-1;
    printf("%lld\n",ans);
    return 0;
}