#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int a[105];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    int l=0,r=n-1;
    while(a[l]<0)l++;
    while(a[r]>0)r--;
    if(r==n-1)
    {
        printf("1 %d\n",a[0]);
        printf("2 %d %d\n",a[1],a[2]);
        printf("%d",n-3);
        for(int i=3;i<n;i++)
            printf(" %d",a[i]);
        printf("\n");
    }
    else
    {
        if(l%2==0)l--;
        printf("%d",l);
        for(int i=0;i<l;i++)
            printf(" %d",a[i]);
        printf("\n");
        printf("%d",n-r-1);
        for(int i=r+1;i<n;i++)
            printf(" %d",a[i]);
        printf("\n");
        printf("%d",r-l+1);
        for(int i=l;i<=r;i++)
            printf(" %d",a[i]);
        printf("\n");
    }
    return 0;
}