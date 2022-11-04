#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long long n,m,a;
    scanf("%I64d%I64d%I64d",&n,&m,&a);
    long long res=((n+a-1)/a)*((m+a-1)/a);
    printf("%I64d\n",res);
    return 0;
}