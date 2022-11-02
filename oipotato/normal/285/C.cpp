#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int n,a[300010];
int main()
{
    scanf("%d",&n);rep(i,n)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    LL ans=0;
    rep(i,n)ans+=abs(a[i]-i);
    printf("%lld\n",ans);
    return 0;
}