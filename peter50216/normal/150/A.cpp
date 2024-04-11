#include<stdio.h>
bool np[4000001];
long long pr[1000001];
int pc;
inline void init(){
    long long i,j;
    for(i=2;i<=4000000;i++)if(!np[i]){
        pr[pc++]=i;
        for(j=i*i;j<=4000000;j+=i)np[j]=1;
    }
}
int main(){
    init();
    long long n;
    scanf("%I64d",&n);
    int i,c=0;
    long long x=1;
    for(i=0;i<pc&&pr[i]*pr[i]<=n;i++){
        while(n%pr[i]==0){
            n/=pr[i];
            if(c<2)x*=pr[i];
            c++;
        }
    }
    if(n>1){
        if(c<2)x*=pr[i];
        c++;
    }
    if(c==0||c==1){
        puts("1\n0");
    }else if(c==2)puts("2");
    else{
        printf("1\n%I64d\n",x);
    }
}