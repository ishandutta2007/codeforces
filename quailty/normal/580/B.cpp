#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
pair<int,ll>a[100005];
int main()
{
    int n,d;
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;i++)
        scanf("%d%I64d",&a[i].first,&a[i].second);
    sort(a+1,a+n+1);
    int r=1;
    ll ans=0,now=0;
    for(int i=1;i<=n;i++)
    {
        while(r<=n && a[r].first<a[i].first+d)now+=a[r++].second;
        ans=max(ans,now);
        now-=a[i].second;
    }
    printf("%I64d\n",ans);
    return 0;
}