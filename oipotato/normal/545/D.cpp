#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int n,a[100010];
int main()
{
    scanf("%d",&n);
    rep(i,n)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int now=0,ans=0;
    rep(i,n)
    if(now<=a[i])
    {
        ans++;
        now+=a[i];
        if(now>(int)1e9)break;
    }
    printf("%d\n",ans);
    return 0;
}