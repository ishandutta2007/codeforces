#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a[100005],f[100005],cnt[100005];
int main()
{
    ll n,k;
    scanf("%I64d%I64d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i]);
    }
    sort(a+1,a+n+1);
    int loc=0;
    f[++loc]=a[1];
    cnt[loc]++;
    for(int i=2;i<=n;i++)
    {
        if(a[i]==a[i-1])
        {
            cnt[loc]++;
        }
        else
        {
            f[++loc]=a[i];
            cnt[loc]++;
        }
    }
    ll suf=0;
    for(int i=1;i<=loc;i++)
    {
        suf+=cnt[i];
        if(n*suf>=k)
        {
            printf("%I64d ",f[i]);
            k-=n*(suf-cnt[i]);
            k=(k-1+cnt[i])/cnt[i];
            printf("%I64d",a[k]);
            break;
        }
    }
    return 0;
}