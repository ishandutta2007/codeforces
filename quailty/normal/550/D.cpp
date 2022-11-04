#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int k;
    scanf("%d",&k);
    if(k%2==0)printf("NO\n");
    else
    {
        printf("YES\n");
        printf("%d %d\n",2*(2*k-1),k*(2*k-1));
        printf("%d %d\n",1,2*k);
        for(int i=1;i<=k-1;i++)
        {
            for(int j=k;j<=2*k-2;j++)
            {
                printf("%d %d\n",i,j);
            }
        }
        for(int i=3;i<=k-1;i+=2)
        {
            printf("%d %d\n",i-1,i);
        }
        if(k>1)
        {
            for(int i=k-1;i<=2*k-2;i++)
            {
                printf("%d %d\n",2*k-1,i);
            }
        }
        for(int i=1;i<=k-1;i++)
        {
            for(int j=k;j<=2*k-2;j++)
            {
                printf("%d %d\n",i+2*k-1,j+2*k-1);
            }
        }
        for(int i=3;i<=k-1;i+=2)
        {
            printf("%d %d\n",i-1+2*k-1,i+2*k-1);
        }
        if(k>1)
        {
            for(int i=k-1;i<=2*k-2;i++)
            {
                printf("%d %d\n",2*k-1+2*k-1,i+2*k-1);
            }
        }
    }
    return 0;
}