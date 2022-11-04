#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[1005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int cnt=0;
    for(int i=2;i<=n;i++)
        cnt+=(__gcd(a[i],a[i-1])>1);
    printf("%d\n",cnt);
    printf("%d",a[1]);
    for(int i=2;i<=n;i++)
    {
        if(__gcd(a[i],a[i-1])>1)printf(" 1");
        printf(" %d",a[i]);
    }
    return 0;
}