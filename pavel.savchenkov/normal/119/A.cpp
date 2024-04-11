#include <iostream>
#include <stdio.h>

using namespace std;

long gcd (long m, long n){
        return (n==0)?m:gcd(n,m%n);
    }

int main()
{
    int a,b,n,he,n2;
    int res=0;
    scanf("%d%d%d", &a, &b, &n);
    while (true) {
        if (res==0) 
            n-=gcd(a,n);
            else 
                n-=gcd(b,n);
        res=1-res;
        if (n<0) break;
    }

    printf("%d",res);
    return 0;
}