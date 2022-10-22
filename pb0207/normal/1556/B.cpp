#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T,n,a[N],cnt[2];

vector<int>p[2];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        cnt[0]=cnt[1]=0;
        p[0].clear(),p[1].clear();
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]),cnt[a[i]&1]++,p[a[i]&1].push_back(i);
        if(n%2==0)
        {
            if(cnt[1]!=cnt[0])
                puts("-1");
            else
            {
                long long ans1=0,ans2=0;
                for(int i=0;i<n;i++)
                {
                    int x=i&1;
                    ans1+=abs(p[x][i/2]-i-1);
                    ans2+=abs(p[x^1][i/2]-i-1);
                }
                printf("%lld\n",min(ans1,ans2)/2);
            }
        }
        else
        {
            if(abs(cnt[1]-cnt[0])!=1)
                puts("-1");
            else
            {
                int mx=cnt[0]>cnt[1]?0:1;
                long long ans=0;
                for(int i=0;i<n;i++)
                    ans+=abs(p[mx][i/2]-i-1),mx^=1;
                printf("%lld\n",ans/2);
            }
        }
    }
}