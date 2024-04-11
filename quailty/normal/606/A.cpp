#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a[6];
    for(int i=0;i<6;i++)
        scanf("%d",&a[i]);
    int tot=0;
    for(int i=0;i<3;i++)
        tot+=max(0,(a[i]-a[i+3])/2);
    for(int i=0;i<3;i++)
        tot-=max(0,a[i+3]-a[i]);
    if(tot>=0)printf("Yes\n");
    else printf("No\n");
    return 0;
}