#include <cstdio>
#include <cmath>
int main(){
    int n;
    scanf("%d", &n);
    printf("2\n");
    long long mul1=1, mul2;
    for(int i=2; i<=n; i++){
        mul2=mul1;
        long long inc=i-mul2%i;
        mul2+=inc;
        printf("%I64d\n", mul2*mul2*i+(2*mul2*mul2-mul1)+(mul2*mul2)/i);
        mul1=mul2;
    }
    return 0;
}