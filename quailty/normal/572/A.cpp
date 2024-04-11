#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[100005],b[100005];
int main()
{
    int na,nb,k,m;
    scanf("%d%d%d%d",&na,&nb,&k,&m);
    for(int i=1;i<=na;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=nb;i++)
        scanf("%d",&b[i]);
    printf("%s\n",( a[k]<b[nb-m+1] ? "YES" : "NO"));
    return 0;
}