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
        int n,ans;
        scanf("%d%d",&n,&ans);
        pair<int,int>a[110];
        rep(i,n)scanf("%d",&a[i].first);
        rep(i,n)scanf("%d",&a[i].second);
        sort(a+1,a+n+1);
        rep(i,n)if(ans>=a[i].first)ans+=a[i].second;else break;
        printf("%d\n",ans);
    }
    return 0;
}