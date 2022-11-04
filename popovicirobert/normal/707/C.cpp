#include <cstdio>

int main(){
    long long a,p2;
    scanf("%I64d" ,&a);
    if(a==1||a==2)
      printf("-1");
    else
     if(a%2==1)
       printf("%I64d %I64d" ,(a*a-1)/2,(a*a-1)/2+1);
      else
         printf("%I64d %I64d" ,(a*a)/4-1,(a*a)/4+1);
    return 0;
}