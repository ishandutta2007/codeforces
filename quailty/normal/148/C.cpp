#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    if(b>0)
    {
        for(int i=0;i<=b;i++)
            printf("%d ",1<<i);
        for(int i=b+1;i<=a+b;i++)
            printf("%d ",(1<<b)+(i-b));
        for(int i=a+b+1;i<n;i++)
            printf("1 ");
    }
    else if(a>0)
    {
        if(n-a==1)printf("-1");
        else
        {
            printf("1 ");
            for(int i=1;i<=a+1;i++)
                printf("%d ",i);
            for(int i=a+2;i<n;i++)
                printf("1 ");
        }
    }
    else
    {
        for(int i=0;i<n;i++)
            printf("1 ");
    }
    return 0;
}