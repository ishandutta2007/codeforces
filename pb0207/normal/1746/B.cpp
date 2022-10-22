#include<bits/stdc++.h>
using namespace std;

int T;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        vector<int>a(n+1),s(n+1);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
            s[i]=s[i-1]+a[i];
        int ans=n;
        for(int i=0;i<=n;i++)
        {
            int p1=s[i];
            int s0=(n-i)-(s[n]-s[i]);
            ans=min(ans,max(p1,s0));
        }
        printf("%d\n",ans);
    }
}