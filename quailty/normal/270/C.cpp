#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int n,k[100005],a[100005];
bool check(int p)
{
    for(int i=1;i<=n;i++)
    {
        if(2*(p-k[i])<max(1,(int)ceil(log(a[i])/log(2))))
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&k[i],&a[i]);
    }
    int l=0,r=1000000032;
    while(l<r)
    {
        int m=l+(r-l)/2;
        if(check(m))r=m;
        else l=m+1;
    }
    printf("%d\n",l);
    return 0;
}