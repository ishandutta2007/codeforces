#include<stdio.h>
int in[4000];
int pr[1000],pc=0;
int isp(int a){
    for(int i=2;i<a;i++)
    if(a%i==0)return 0;
    return 1;
}
inline int is2p(int a){
    int i,cc=0;
    for(i=0;i<pc;i++)if(a%pr[i]==0){
    cc++;
    }
    return cc==2;
}
int main(){
    int n,c=0;
    scanf("%d",&n);
    for(int i=2;i<=n;i++)if(isp(i))pr[pc++]=i;
    for(int i=2;i<=n;i++)if(is2p(i))c++;
    printf("%d\n",c);
}