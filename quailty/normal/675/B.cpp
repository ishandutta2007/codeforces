#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,a,b,c,d;
    scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
    int res=0;
    for(int i=1;i<=n;i++)
    {
        int k[4]={i,i+b-c,i+a+b-c-d,i+a-d};
        bool isok=1;
        for(int j=0;j<4;j++)
            if(k[j]<1 || k[j]>n)isok=0;
        res+=isok;
    }
    return 0*printf("%I64d",1LL*res*n);
}