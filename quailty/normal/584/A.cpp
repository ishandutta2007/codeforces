#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,t;
    scanf("%d%d",&n,&t);
    if(t==10 && n==1)printf("%d\n",-1);
    else
    {
        if(t<10)
        {
            for(int i=1;i<=n;i++)
                printf("%d",t);
        }
        else
        {
            printf("%d",1);
            for(int i=2;i<=n;i++)
                printf("0");
        }
    }
    return 0;
}