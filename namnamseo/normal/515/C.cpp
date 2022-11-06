#include <cstdio>

int cnt[10];
int ans[4];
int fact[10];
int prime[4]={2,3,5,7};

int main()
{
    int i, j;
    scanf("%d",&j);
    int k,cur;
    fact[0]=1;
    for(i=1;i<10;++i) fact[i]=fact[i-1]*i;
    for(;j--;){
        scanf("%1d",&i);
        cur=fact[i];
        for(i=3;0<=i;--i){
            while(!(cur%fact[prime[i]])){
                cur/=fact[prime[i]];
                ++ans[i];
            }
        }
    }
    for(j=3;0<=j;--j){
        for(;ans[j]--;) putchar(48+prime[j]);
    }
    return 0;
}