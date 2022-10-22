#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=4e6+1e3+7;

int n,P,f[N],g[N];

signed main()
{
    // P=998244353;
    scanf("%lld%lld",&n,&P);
    // f[1]=1;
    // g[2]=2,g[3]=P-1;
    f[1]=1;g[2]=1;
    for(int i=2;i<=n;i++)
    {
        g[i]=(g[i]+g[i-1])%P;
        f[i]=(g[i]+(i-i/2))%P;
        for(int j=i*2;j<=n;j+=i)
        {
            int r=j+j/i;
            if(r<=j)
                continue;
            g[j]=(g[j]+f[i])%P;
            if(r<=n)
                g[r]=(g[r]-f[i]+P)%P;
        }
        g[i+1]=(g[i+1]+f[i])%P;
    }
    printf("%lld\n",f[n]);
}