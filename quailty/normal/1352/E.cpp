#include<bits/stdc++.h>
using namespace std;
const int MAXN=8005;
int a[MAXN],cnt[MAXN];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            cnt[i]=0;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]),cnt[a[i]]++;
        for(int i=1;i<=n;i++)
            a[i]+=a[i-1];
        int res=0;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
            {
                int t=a[j]-a[i-1];
                if(t>=1 && t<=n)
                    res+=cnt[t],cnt[t]=0;
            }
        printf("%d\n",res);
    }
    return 0;
}