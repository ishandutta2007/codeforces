#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int c[2],res=0;
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        if(a==1)c[0]=i;
        if(a==n)c[1]=i;
    }
    for(int i=0;i<2;i++)
    {
        res=max(res,abs(1-c[i]));
        res=max(res,abs(n-c[i]));
    }
    printf("%d\n",res);
    return 0;
}