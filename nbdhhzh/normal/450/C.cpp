#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<utility>
using namespace std;
long long ans;
int main()
{
    long long n,m,k;
    scanf("%I64d%I64d%I64d",&n,&m,&k);
    if(k>=(n+m-1))
    {
        printf("-1\n");
        return 0;
    }
    if(k<n) ans=max(ans,n/(k+1)*m);
    else ans=max(ans,m/(k-n+2));
    if(k<m) ans=max(ans,m/(k+1)*n);
    else ans=max(ans,n/(k-m+2)); 
    printf("%I64d\n",ans);
    return 0;
}