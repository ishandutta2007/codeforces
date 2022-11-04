#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
long long a[15]={1};
void build()
{
    for(int i=1;i<=10;i++)
    {
        a[i]=a[i-1]*10;
    }
}
int main()
{
    build();
    int n;
    scanf("%d",&n);
    int loc=upper_bound(a,a+11,n)-a;
    long long ans=0;
    //printf("%d\n",loc);
    for(int i=1;i<=loc;i++)
    {
        //printf("%d\n",i);
        ans+=9*i*a[i-1];
    }
    ans+=loc*(n-a[loc]+1);
    printf("%I64d\n",ans);
    return 0;
}