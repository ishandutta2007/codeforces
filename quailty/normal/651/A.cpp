#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a[2];
    for(int i=0;i<2;i++)
        scanf("%d",&a[i]);
    int res=0;
    while(a[0]>0 && a[1]>0 && a[0]+a[1]>2)
    {
        res++;
        if(a[0]<=a[1])a[0]+=1,a[1]-=2;
        else a[0]-=2,a[1]+=1;
    }
    printf("%d\n",res);
    return 0;
}