#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,m,a,b;
    scanf("%d%d%d%d",&n,&m,&a,&b);
    int res=0x3f3f3f3f;
    for(int i=0;i<=1000;i++)
        res=min(res,max(0,n-i*m)*a+i*b);
    printf("%d\n",res);
    return 0;
}