#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200005;
ll d[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&d[i]);
    ll res=0,sum_l=0,sum_r=0;
    for(int l=1,r=n+1;l<r;l++)
    {
        sum_l+=d[l];
        while(l<r && sum_r<sum_l)
            sum_r+=d[--r];
        if(l<r && sum_l==sum_r)
            res=max(res,sum_l);
    }
    printf("%lld\n",res);
    return 0;
}