#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[100005];
int cnt[1000005];
int main()
{
    int n;
    scanf("%d",&n);
    int res=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        cnt[a[i]]++;
        res=max(res,cnt[a[i]]);
    }
    int l=1,r=n;
    while(l<r)
    {
        memset(cnt,0,sizeof(cnt));
        int m=(l+r)>>1;
        int tot=0;
        for(int i=1;i<=m;i++)
        {
            cnt[a[i]]++;
            tot=max(tot,cnt[a[i]]);
        }
        for(int i=m+1;i<=n;i++)
        {
            cnt[a[i]]++;
            cnt[a[i-m]]--;
            tot=max(tot,cnt[a[i]]);
        }
        if(tot>=res)r=m;
        else l=m+1;
    }
    memset(cnt,0,sizeof(cnt));
    int tot=0,loc;
    for(loc=1;loc<=l;loc++)
    {
        cnt[a[loc]]++;
        tot=max(tot,cnt[a[loc]]);
    }
    if(tot>=res)printf("%d %d\n",1,l);
    else
    {
        for(loc=l+1;loc<=n;loc++)
        {
            cnt[a[loc]]++;
            cnt[a[loc-l]]--;
            tot=max(tot,cnt[a[loc]]);
            if(tot>=res)
            {
                printf("%d %d\n",loc-l+1,loc);
                break;
            }
        }
    }
    return 0;
}