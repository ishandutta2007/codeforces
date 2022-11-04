#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int a[MAXN],pre[MAXN],suf[MAXN];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    a[n+1]=m;
    for(int i=1;i<=n+1;i++)
        pre[i]=(a[i]-a[i-1])+(i>1 ? pre[i-2] : 0);
    for(int i=n;i>=0;i--)
        suf[i]=(a[i+1]-a[i])+suf[i+2];
    int res=suf[0];
    for(int i=0;i<=n+1;i++)
    {
        if(i<n+1 && a[i]<=a[i+1]-2)
        {
            int val;
            if(i&1)val=pre[i]+suf[i]-1;
            else val=(i>0 ? pre[i-1] : 0)+suf[i+1]+1;
            res=max(res,val);
        }
        if(i>0 && a[i]>=a[i-1]+2)
        {
            int val;
            if(i&1)val=pre[i]+suf[i]-1;
            else val=(i>0 ? pre[i-1] : 0)+suf[i+1]+1;
            res=max(res,val);
        }
    }
    printf("%d\n",res);
    return 0;
}