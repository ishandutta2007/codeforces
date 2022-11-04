#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int a[2005];
ll cnt[5005],cnt2[10005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<i;j++)
            cnt[a[i]-a[j]]++;
    for(int i=1;i<=5000;i++)
        for(int j=1;j<=5000;j++)
            cnt2[i+j]+=cnt[i]*cnt[j];
    for(int i=1;i<=10000;i++)
        cnt2[i]+=cnt2[i-1];
    ll tot=0;
    for(int i=1;i<=5000;i++)
        tot+=cnt2[i-1]*cnt[i];
    ll now=n*(n-1)/2;
    printf("%.15f\n",(tot+0.0)/now/now/now);
    return 0;
}