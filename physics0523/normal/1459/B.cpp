#include<stdio.h>

long long A241496(long long n){
    long long prt;
    if(n%2){prt=-1;}else{prt=1;}
    long long res = 1 + (3*n*(n+4) + 2 - prt*(n*(n+4)+2))/8;
    return res;
}

int main(){
    long long n;
    scanf("%lld",&n);
    printf("%lld\n",A241496(n));
    return 0;
}