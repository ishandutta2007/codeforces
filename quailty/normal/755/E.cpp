#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    if(n<=3 || k<=1 || k>3)return 0*printf("-1");
    if(k==2)
    {
        if(n==4)return 0*printf("-1");
        printf("%d\n",n-1);
        for(int i=1;i<=n-1;i++)
            printf("%d %d\n",i,i+1);
    }
    else
    {
        printf("%d\n",2*n-5);
        for(int i=1;i<=3;i++)
            printf("%d %d\n",i,i+1);
        for(int i=5;i<=n;i++)
        {
            printf("2 %d\n",i);
            printf("3 %d\n",i);
        }
    }
    return 0;
}