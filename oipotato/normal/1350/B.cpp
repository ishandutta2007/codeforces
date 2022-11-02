#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n,a[100010],f[100010];scanf("%d",&n);
        rep(i,n)scanf("%d",&a[i]);
        rep(i,n)f[i]=0;
        int ans=0;
        rep(i,n)
        {
            f[i]++;ans=max(ans,f[i]);
            for(int j=i;j<=n;j+=i)if(a[j]>a[i])f[j]=max(f[j],f[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}