#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    scanf("%I64d",&n);
    if(n<=2)return 0*printf("-1");
    if(n&1)
    {
        n>>=1;
        printf("%I64d %I64d",2*n*n+2*n,2*n*n+2*n+1);
    }
    else
    {
        n>>=1;
        printf("%I64d %I64d",n*n-1,n*n+1);
    }
    return 0;
}