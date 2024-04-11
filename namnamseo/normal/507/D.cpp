#include <cstdio>

int n,k,m;

int table[1010][101][2];

int modder;

int pow10(int x){
    if(x==0) return 1;
    if(x==1) return 10%modder;
    int ret=pow10(x/2);
    ret = ((1LL*ret)*ret)%modder;
    if(x&1){
        ret=((1LL*ret)*10)%modder;
    }
    return ret;
}

int pow10(int x,int a){
    modder=a;
    return pow10(x);
}

int dyn(int leftdig,int rem,bool allzero){
    if(rem==0 && !allzero) {
        if(leftdig) return (1LL*9*pow10(leftdig-1,m))%m;
        else return 1;
    }
    if(leftdig==0) return 0;
    int i;
    int& ret=table[leftdig][rem][allzero];
    if(ret!=-1) return ret;
    ret=0;
    for(i=0;i<10;++i){
        ret+=dyn(leftdig-1,(1LL*rem+i*pow10(n-leftdig,k))%k,allzero && i==0);
        ret%=m;
    }
    return ret;
}

int main()
{
    scanf("%d%d%d",&n,&k,&m);
    int i,j;
    for(i=0;i<=1000;++i) for(j=0;j<100;++j)
        table[i][j][0]=-1,
        table[i][j][1]=-1;
    printf("%d\n",dyn(n,0,1));
    return 0;
}