#include <cstdio>

int main(){
    int n;
    scanf("%d" ,&n);
    if(n==1)
       printf("-1");
    else
    printf("%d %d %d" ,n,n+1,n*(n+1));
    return 0;
}