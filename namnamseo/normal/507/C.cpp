#include <cstdio>

bool bin[60];

int main()
{
    int n;
    long long tg;
    scanf("%d%I64d",&n,&tg);
    --tg;
    int i;
    for(i=0;i<n;++i) bin[n-i-1]=(1&(tg>>i));
    long long ans=0;
    for(i=0;i<n;++i) {
        if((i==0 && bin[0]==1) || (i>0 && bin[i-1]==bin[i])){
            ans+=(1LL<<(n-i))-1;
        }
        ++ans;
    }
    printf("%I64d\n",ans);
    return 0;
}