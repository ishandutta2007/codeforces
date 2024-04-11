#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int a[400010],n,k;
bool check(int x)
{
    int now=0;
    for(int i=k-x+1;i<=k;i++)
    {
        if(now>=a[i])return 0;
        now+=n-a[i];
    }
    return 1;
}
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        scanf("%d%d",&n,&k);
        rep(i,k)scanf("%d",&a[i]);
        sort(a+1,a+k+1);
        int l=0,r=k+1;
        for(;l<r-1;)
        {
            int mid=(l+r)>>1;
            if(check(mid))l=mid;else r=mid;
        }
        printf("%d\n",l);
    }
    return 0;
}