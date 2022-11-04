#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[5005],h[10000005];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        h[a[i]]=1;
    }
    int q,x;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&x);
        int ans=25;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                if(x==j*a[i])
                {
                    ans=min(ans,j);
                    continue;
                }
                if(x<j*a[i])break;
                for(int jj=1;jj<=k-j;jj++)
                {
                    if((x-j*a[i])%jj==0 && (x-j*a[i])/jj<=10000000 && h[(x-j*a[i])/jj])
                        ans=min(ans,j+jj);
                }
            }
        }
        if(ans>k)printf("-1\n");
        else printf("%d\n",ans);
    }
    return 0;
}