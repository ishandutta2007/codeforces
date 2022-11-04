#include <stdio.h>
#include <stdlib.h>
int main(){
    long long n;
    scanf("%I64d" ,&n);
    n-=2;
    printf("%I64d" ,n*n);
    return 0;
}