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
        int n,a[55];scanf("%d",&n);
        int mn=(int)1e7;
        rep(i,n)scanf("%d",&a[i]),mn=min(mn,a[i]);
        int ans=0;
        rep(i,n)ans+=a[i]-mn;
        printf("%d\n",ans);
    }
    return 0;
}