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
int a[200010],b[200010],c[200010],d[200010];
main(){
    int n=gi(),B=0,C=0,D=0;
    for(int i=1;i<=n;++i){
        a[i]=gi();
        if(a[i]>0)b[++B]=i;
        else if(a[i]==0)c[++C]=i;
        else d[++D]=i;
    }
    if(D&1){
        for(int i=2;i<=D;++i)if(a[d[i]]>a[d[1]])std::swap(d[i],d[1]);
        for(int i=1;i<B;++i)printf("1 %lld %lld\n",b[i],b[i+1]);
        for(int i=1;i<C;++i)printf("1 %lld %lld\n",c[i],c[i+1]);
        for(int i=2;i<D;++i)printf("1 %lld %lld\n",d[i],d[i+1]);
        if(C!=0)printf("1 %lld %lld\n",c[C],d[1]);
        if(D!=1&&B!=0)printf("1 %lld %lld\n",b[B],d[D]);
        if(!(B==0&&C&&D==1))printf("2 %lld\n",d[1]);
    }else{
        for(int i=2;i<=D;++i)if(a[d[i]]>a[d[1]])std::swap(d[i],d[1]);
        for(int i=1;i<B;++i)printf("1 %lld %lld\n",b[i],b[i+1]);
        for(int i=1;i<C;++i)printf("1 %lld %lld\n",c[i],c[i+1]);
        for(int i=1;i<D;++i)printf("1 %lld %lld\n",d[i],d[i+1]);
        if(C!=0&&(B!=0||D!=0))printf("2 %lld\n",c[C]);
        if(D!=0&&B!=0)printf("1 %lld %lld\n",b[B],d[D]);
    }
    return 0;
}