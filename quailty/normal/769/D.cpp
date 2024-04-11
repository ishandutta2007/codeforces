#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1<<14;
int cnt[MAXN];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        cnt[a]++;
    }
    ll res=0;
    if(k==0)for(int i=0;i<MAXN;i++)
        res+=1LL*cnt[i]*(cnt[i]-1);
    else for(int t=0;t<MAXN;t++)
        if(__builtin_popcount(t)==k)
            for(int i=0;i<MAXN;i++)
                res+=1LL*cnt[i]*cnt[i^t];
    return 0*printf("%lld\n",res/2);
}