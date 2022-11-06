#include <cstdio>
#include <algorithm>

long long pow(int base,int to){
    if(to==0) return 1;
    if(to==1) return base;
    long long ret = pow(base,to/2);
    ret*=ret;
    if(to%2) ret*=base;
    return ret;
}

int digsum(int x){
    int ret = 0;
    while(x){
        ret+=x%10;
        x/=10;
    }
    return ret;
}

int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int i;
    int an=0;
    long long temp, ans[81];
    for(i=1;i<=81;i++){
        temp = pow(i,a)*b+1LL*c;
        if(temp>0 && temp<1000000000){
            if(i == digsum(temp)){
                ans[an]=temp;
                an++;
            }
        }
    }
    std::sort(ans,ans+an);
    printf("%d\n",an);
    for(i=0;i<an;i++) printf("%I64d ",ans[i]);
    putchar(10);
    return 0;
}