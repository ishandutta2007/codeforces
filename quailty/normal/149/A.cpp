#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[12];
int main()
{
    int k;
    scanf("%d",&k);
    for(int i=0;i<12;i++)
        scanf("%d",&a[i]);
    sort(a,a+12,greater<int>());
    for(int i=0;i<12;i++)
    {
        if(k<=0)return 0*printf("%d",i);
        k-=a[i];
    }
    printf("%d",(k<=0 ? 12 : -1));
    return 0;
}