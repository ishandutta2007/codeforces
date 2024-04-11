#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    k=min(k,n-k);
    long long res=1,now=1;
    for(int i=1,l=0,r=k;i<=n;i++)
    {
        now+=(l>0 && l<k)||(r>0 && r<k);
        l=(l+k)%n,r=(r+k)%n;
        printf("%lld ",res+=now);
    }
    return 0;
}