#include <bits/stdc++.h>
using namespace std;
const int MAXN=400005;
int a[MAXN],cnt[MAXN];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=2;i<=2*k;i++)
            cnt[i]=0;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n/2;i++)
        {
            int l=a[i],r=a[n+1-i];
            if(l>r)swap(l,r);
            cnt[2]+=2;
            cnt[1+l]+=-1;
            cnt[l+r]+=-1;
            cnt[l+r+1]+=1;
            cnt[r+k+1]+=1;
        }
        for(int i=3;i<=2*k;i++)
            cnt[i]+=cnt[i-1];
        int res=n;
        for(int i=2;i<=2*k;i++)
            res=min(res,cnt[i]);
        printf("%d\n",res);
    }
    return 0;
}