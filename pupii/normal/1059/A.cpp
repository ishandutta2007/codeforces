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
int t[100001],l[100001];
main(){
    int n=gi(),T=gi(),a=gi(),ans=0;
    for(int i=1;i<=n;++i)t[i]=gi(),l[i]=gi();
    for(int i=2;i<=n;++i)ans+=(t[i]-t[i-1]-l[i-1])/a;
    ans+=t[1]/a;
    ans+=(T-t[n]-l[n])/a;
    printf("%lld\n",ans);
    return 0;
}