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
int a[10001];
main(){
    int n=gi(),m=gi(),mx=0,mx2=0;
    for(int i=1;i<=n;++i)a[i]=gi(),mx=std::max(mx,a[i]);
    mx+=m;
    while(m--){
        int p=1;
        for(int i=2;i<=n;++i)if(a[i]<a[p])p=i;
        ++a[p];
    }
    for(int i=1;i<=n;++i)mx2=std::max(mx2,a[i]);
    printf("%lld %lld\n",mx2,mx);
    return 0;
}