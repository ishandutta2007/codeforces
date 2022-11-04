#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int p[500005],tot;
int main()
{
    int m;
    scanf("%d",&m);
    int now=0;
    for(int i=1;i<=500000;i++)
    {
        int t=i;
        while(t%5==0)
        {
            t/=5;
            now++;
        }
        if(now==m)
        {
            p[tot++]=i;
        }
    }
    printf("%d\n",tot);
    for(int i=0;i<tot;i++)
        printf("%d ",p[i]);
    return 0;
}