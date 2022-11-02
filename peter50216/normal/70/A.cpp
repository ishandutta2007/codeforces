#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    if(n==0){
    puts("1");
    return 0;
    }
    n--;
    int a=1;
    while(n--){
    a=(a*3)%(1000003);
    }
    printf("%d\n",a);
}