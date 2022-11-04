#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int fp(int a,int k,int m)
{
    a%=m;
    int res=1;
    while(k)
    {
        if(k&1)res=res*a%m;
        a=a*a%m;
        k>>=1;
    }
    return res;
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",fp(1378,n,10));
    return 0;
}