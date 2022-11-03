#include<bits/stdc++.h>
#define il inline
#define vd void
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
int pr[1000000],a[15000001],yes[15000001];
int d[15000001],dd[15000001];
int ans[1000000];
main(){
    int n=gi(),g=0;
    for(int i=1;i<=n;++i)a[i]=gi(),g=std::__gcd(g,a[i]);
    for(int i=1;i<=n;++i)a[i]/=g;
    for(int i=2;i<=15000000;++i){
        if(!yes[i])pr[++pr[0]]=i,d[i]=pr[0],dd[i]=i;
        for(int j=1;j<=pr[0]&&1ll*i*pr[j]<=15000000;++j){
            yes[i*pr[j]]=1;
            d[i*pr[j]]=j;dd[i*pr[j]]=dd[i]*pr[j];
            if(i%pr[j]==0){dd[i*pr[j]]=dd[i];break;}
        }
    }
    dd[1]=1;
    int Ans=0;
    for(int i=1;i<=n;++i){
        a[i]=dd[a[i]];
        while(a[i]!=1)++ans[d[a[i]]],a[i]/=pr[d[a[i]]];
    }
    for(int i=1;i<=pr[0];++i)Ans=std::max(Ans,ans[i]);
    Ans=n-Ans;
    if(Ans==n)Ans=-1;
    printf("%d\n",Ans);
    return 0;
}