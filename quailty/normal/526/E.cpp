#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int n;
ll a[2000005];
int d[1000005];
void solve(int q)
{
    int loc=0,mini=2000005,maxi=0,st;
    ll cur=0;
    for(int i=1;i<=n;i++)
    {
        cur-=a[i-1];
        while(loc<2*n-1)
        {
            if(cur+a[loc+1]>q)
            {
                break;
            }
            cur+=a[loc+1];
            loc++;
        }
        d[i]=loc;
        if(mini>=d[i]-i+1 && d[i]!=d[i-1])
        {
            mini=d[i]-i+1;
            st=i;
        }
        maxi=max(maxi,d[i]-i+1);
    }
    if(maxi>=n)printf("1\n");
    else
    {
        int ans=2000005;
        for(int i=st;i<=d[st];i++)
        {
            int cnt=0,sum=0,p=i;
            while(sum<n)
            {
                if(p>n)p-=n;
                cnt++;
                sum+=d[p]-p+1;
                p=d[p]+1;
            }
            ans=min(ans,cnt);
        }
        printf("%d\n",ans);
    }
}
int main()
{
    int q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=n+1;i<2*n;i++)
    {
        a[i]=a[i-n];
    }
    ll que;
    while(q--)
    {
        scanf("%lld",&que);
        solve(que);
    }
    return 0;
}