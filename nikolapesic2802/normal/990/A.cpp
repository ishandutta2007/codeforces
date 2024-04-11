#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,m,a,b;
    scanf("%I64d %I64d %I64d %I64d",&n,&m,&a,&b);
    long long x=n%m;
    long long v1=x*b;
    long long v2=(m-x)*a;
    printf("%I64d",min(v1,v2));
    return 0;
}