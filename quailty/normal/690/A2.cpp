#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;
ll n;
int main()
{
    scanf("%I64d",&n);
    if(n==2||(n&1)) printf("%I64d\n",(n-1)/2);
    else{
        n/=2;
        ll now=4;
        while(now<=n) now*=2;
        printf("%I64d\n",n-now/2);
    }
    return 0;
}