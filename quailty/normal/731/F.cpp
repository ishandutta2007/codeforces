#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=200005;
int cnt[MAXN],sum[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        cnt[a]++;
    }
    for(int i=1;i<MAXN;i++)
        sum[i]=sum[i-1]+cnt[i];
    ll res=0;
    for(int i=1;i<MAXN;i++)
    {
        if(!cnt[i])continue;
        ll now=0;
        for(int j=i;j<MAXN;j+=i)
            now+=1LL*j*(sum[min(MAXN,j+i)-1]-sum[j-1]);
        res=max(res,now);
    }

    printf("%I64d\n",res);
    return 0;
}