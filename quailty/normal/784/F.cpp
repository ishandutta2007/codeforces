#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<iostream>
#include<algorithm>
using namespace std;
int a[15];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    clock_t st=clock();
    while(1.0*(clock()-st)/CLOCKS_PER_SEC<1.5);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        printf("%d ",a[i]);
    return 0;
}