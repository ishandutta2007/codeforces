#include<stdio.h>
inline bool isp(int a){
    if(a<=1)return 0;
    for(int i=2;i*i<=a;i++)if(a%i==0)return 0;
    return 1;
}
int pr[2000],pc;
int cnt[2000];
int main(){
    int n,k,i,j;
    scanf("%d%d",&n,&k);
    for(i=2;i<=n;i++)if(isp(i))pr[pc++]=i;
    for(i=0;i<pc-1;i++)cnt[1+pr[i]+pr[i+1]]=1;
    for(i=0;i<=n;i++)if(isp(i)&&cnt[i])k--;
    puts(k<=0?"YES":"NO");
}