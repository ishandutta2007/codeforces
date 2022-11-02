#include<stdio.h>
inline int chk(int a){
    if(a>=10)return 10;
    return a;
}
int main(){
    int n;
    scanf("%d",&n);
    int a=0;
    n-=10;
    for(int i=1;i<=13;i++)if(chk(i)==n||(i==1&&n==11))a+=(i==12?3:4);
    printf("%d\n",a);
}