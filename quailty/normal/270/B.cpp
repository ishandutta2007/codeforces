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
    {
        scanf("%d",&a[i]);
    }
    bool flag=0;
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]>a[i+1])
        {
            printf("%d\n",i);
            flag=1;
            break;
        }
    }
    if(!flag)printf("0\n");
    return 0;
}