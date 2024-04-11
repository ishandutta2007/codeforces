#include <cstdio>

int n,k;
int parity;

int work(int x)
{
    if(k==0){
        if(x==1) return 1;
        if(x==2) return 2; return 1^x&1;
    }
    if(x<=6){
if(x==0) return 0;
if(x==1) return 1;
if(x==2) return 0;
if(x==3) return 1;
if(x==4) return 2;
if(x==5) return 0;
if(x==6) return 2;
    }
if(x&1) return 0;
else if(work(x>>1)==1) return 2;
else return 1;
}

int main()
{
    scanf("%d%d",&n,&k); k&=1;
    int buffer;
    for(;n--;){
        scanf("%d",&buffer);
        //printf("value %d\n",work(buffer));
        parity ^= work(buffer);
    }
    puts(parity ? "Kevin":"Nicky");
    return 0;
}