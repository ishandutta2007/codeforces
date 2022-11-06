#include <cstdio>
#include <algorithm>

int data[100010];

long long c2(int x){
    return (1LL*x*(x-1))/2;
}

int main()
{
    int n;
    int d;
    scanf("%d%d",&n,&d);
    int i;
    long long ans=0;
    if(n<=2) puts("0");
    else {
        for(i=0;i<n;++i) scanf("%d",data+i);
        int pos;
        for(i=0;i<n;++i){
            pos = std::upper_bound(data,data+n,data[i]+d)-1-data;
            if(i+2<=pos) ans+=c2(pos-i);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}