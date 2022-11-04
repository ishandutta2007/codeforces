#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=405;
ll C[MAXN],G[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%I64d",&C[i]);
    ll res=1LL<<60;
    for(int i=2;i<=n;i++)
    {
        ll t=C[i-1]-1;
        for(int j=1;j<=n;j++)
        {
            if(t>=C[j])
            {
                G[j]=t/C[j];
                t%=C[j];
            }
            else G[j]=0;
        }
        ll w=0,sum=0;
        for(int j=1;j<=n;j++)
        {
            sum+=G[j]+1;
            t=w+=(G[j]+1)*C[j];
            ll now=0;
            for(int k=1;k<=n;k++)
                if(t>=C[k])
                {
                    now+=t/C[k];
                    t%=C[k];
                }
            if(sum<now && res>w)res=w;
            sum--;
            w-=C[j];
        }
    }
    printf("%I64d",(res<(1LL<<60) ? res : -1));
    return 0;
}