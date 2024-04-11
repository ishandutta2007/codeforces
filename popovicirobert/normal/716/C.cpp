#include <cstdio>
int main(){
    long long i;
    int n;
    long long a,x;
    scanf("%d" ,&n);
    a=2;
    for(i=1;i<=n;i++){
       printf("%I64d\n" ,(i*(i+1)*(i+1))-a/i);
       a=i*(i+1);
    }
    return 0;
}