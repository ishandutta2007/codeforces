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
int p[100010],c[100010],f[100010][8];
main(){
    int n=gi();
    for(int i=1;i<=n;++i){
        p[i]=gi();
        char o[5];scanf("%s",o+1);
        int l=strlen(o+1);
        for(int j=1;j<=l;++j)c[i]|=1<<(o[j]-'A');
    }
    memset(f,63,sizeof f);
    f[1][0]=0;
    for(int i=1;i<=n;++i)
        for(int j=0;j<8;++j)
            f[i+1][j]=std::min(f[i+1][j],f[i][j]),
            f[i+1][j|c[i]]=std::min(f[i+1][j|c[i]],f[i][j]+p[i]);
    if(f[n+1][7]==f[0][0])f[n+1][7]=-1;
    printf("%lld\n",f[n+1][7]);
    return 0;
}