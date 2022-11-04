#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[100005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int now=1;
    for(int i=1;i<=n;i++)
        if(a[i]>=now)a[i]=now++;
    printf("%d\n",now);
    return 0;
}