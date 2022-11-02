#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int a[200010];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n,k;scanf("%d%d",&n,&k);
        rep(i,n)scanf("%d",&a[i]),a[i]=(k-a[i]%k)%k;
        sort(a+1,a+n+1);
        LL ans=0;
        rep(i,n)
        if(a[i])
        {
            int j=i;
            for(;j<=n&&a[j]==a[i];j++);
            ans=max(ans,(LL)(j-i-1)*k+a[i]+1);
            i=j-1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}