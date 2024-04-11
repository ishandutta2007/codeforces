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
        int n,k,a[1010];scanf("%d%d",&n,&k);
        rep(i,n)scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        int ans=0;
        for(int i=2;i<=n;i++)ans+=(k-a[i])/a[1];
        printf("%d\n",ans);
    }
    return 0;
}