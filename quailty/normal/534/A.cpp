#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    if(n<=2)
    {
        printf("1\n1\n");
    }
    else if(n==3)
    {
        printf("2\n1 3\n");
    }
    else if(n==4)
    {
        printf("4\n3 1 4 2\n");
    }
    else
    {
        printf("%d\n",n);
        int k=1;
        while(k<=n)
        {
            printf("%d ",k);
            k+=2;
        }
        k=2;
        while(k<=n)
        {
            printf("%d ",k);
            k+=2;
        }
    }
    return 0;
}