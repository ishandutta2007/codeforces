#include <cstdio>
#include <algorithm>

int p,k;

int gcd(int a,int b){ return b?gcd(b,a%b):a; }

int M=(int(1e9))+7;

int pow_mod=M;

int pd[10010], tmp;

int pow(int a,int b)
{
    if(b==0) return 1;
    int ret=pow(a,b>>1);
    ret=(ret*1ll*ret)%pow_mod;
    if(b&1) ret=(ret*1ll*a)%pow_mod;
    return ret;
}

int main()
{
    scanf("%d%d",&p,&k);
    if(k==0){
        printf("%d\n",pow(p,p-1));
        return 0;
    }
    if(k==1){
        printf("%d\n",pow(p,p));
        return 0;
    }
    int asdf = p-1;
    int i;
    for(i=1;i*i<=asdf;++i){
        if(asdf%i == 0){
            pd[tmp++]=i;
            if(i!=asdf/i) pd[tmp++]=asdf/i;
        }
    }
    std::sort(pd,pd+tmp);
    pow_mod = p;
    for(i=0;i<tmp;++i) if(pow(k,pd[i])==1) break;
    pow_mod = (int(1e9))+7;
    printf("%d\n",pow(p,(p-1)/pd[i]));
    return 0;
}