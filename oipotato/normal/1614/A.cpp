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
        int n,l,r,k,a[110];
        scanf("%d%d%d%d",&n,&l,&r,&k);
        rep(i,n)scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        int ans=0;
        rep(i,n)if(l<=a[i]&&a[i]<=r&&k>=a[i])k-=a[i],ans++;
        printf("%d\n",ans);
    }
    return 0;
}