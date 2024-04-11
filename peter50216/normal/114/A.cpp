#include<stdio.h>
int main(){
    long long a,b;
    scanf("%I64d%I64d",&a,&b);
    int l=0;
    long long c=a;
    while(c<b){
    c*=a;
    l++;
    }
    if(c==b){
    puts("YES");
    printf("%d\n",l);
    }else puts("NO");
}