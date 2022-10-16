#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    long long n,k,i,j,upp,low,outer=0,inner=0;
    cin>>n>>k;
    upp=n*(n-1)/2;
    if(k>upp)
    {
        printf("Impossible");
        return 0;
    }
    if(k<n)
    {
        for(i=1;i<=n-k-1;i++)
            printf("()"); //wai mian
        printf("(");
        for(i=1;i<=k;i++)
            printf("()");
        printf(")");
        return 0;
    }
    while(1)
    {
        if(k<n) break;
        low=(n-1)*(n-2)/2;
        if(k >= low)
        {
            k=k-(n-1);
            n=n-1;
            printf("(");
            inner++; // 
        }
        else
        {
            outer++;
            printf("()");
            n=n-1;  // 
        }

    }


//    for(i=1;i<=outer;i++)
//        printf("()"); //

//    for(i=1;i<=inner+1;i++)
//        printf("(");
//
//    for(i=1;i<=k;i++)
//        printf("()");

    for(i=1;i<=n-k-1;i++)
        printf("()"); //
    printf("(");
    for(i=1;i<=k;i++)
        printf("()");
    printf(")");

    for(i=1;i<=inner;i++)
        printf(")");

    return 0;
}