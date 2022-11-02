#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int n,res=0;
        scanf("%d",&n);
        if(n%4%2==1)n-=9,res++;
        if(n%4==2)n-=6,res++;
        if(n<0)printf("-1\n");
        else printf("%d\n",n/4+res);
    }
    return 0;
}