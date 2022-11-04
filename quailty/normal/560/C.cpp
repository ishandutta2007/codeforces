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
    for(int i=0;i<6;i++)scanf("%d",&a[i]);
    int tot=a[0]+a[1]+a[2];
    printf("%d\n",tot*tot-a[0]*a[0]-a[2]*a[2]-a[4]*a[4]);
    return 0;
}