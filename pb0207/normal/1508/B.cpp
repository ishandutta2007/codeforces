#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e5+1e3+7;

int n,k,T,f[N],ans[N];

int calc(int r,int l)
{
    if(l>r)
        return 0;
    if(l==r)
        return f[l];
    if(r>70)
        return 2e18;
    if(f[l]>1e18)
        return 2e18;
    return f[r+1]-f[l];//2^l+2^l+1+..+2^r=2^{r+1}-2^{l+1}
}

signed main()
{
    f[0]=f[1]=1;
    for(int i=2;i<=100000;i++)
        f[i]=f[i-1]*2,f[i]=f[i]>4e18?(int)4e18:f[i];
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld",&n,&k);
        if(k>f[n])
        {
            puts("-1");
            continue;
        }
        for(int i=1,j;i<=n;i=j+1)
        {
            int l=i-1,r=n;
            while(r-l>1)
            {
                int mid=(l+r)>>1;
                if(k<=calc(n-i,n-mid))
                    r=mid;
                else
                    l=mid;
            }
            k-=calc(n-i,n-r+1);
            for(j=r;j>=i;j--)
                ans[i+r-j]=j;
            j=r;
        }
        for(int i=1;i<=n;i++)
            printf("%lld%c",ans[i]," \n"[i==n]);
    }
}