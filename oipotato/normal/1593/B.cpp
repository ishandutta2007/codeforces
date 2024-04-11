#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int cal(int a[],int n,int x,int y)
{
    for(int i=n;i;i--)
    if(a[i]==y)
    {
        for(int j=i-1;j;j--)if(a[j]==x)return n-j-1;
        break;
    }
    return n+10;
}
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        LL n;scanf("%lld",&n);
        int a[20],cnt=0;
        for(;n;a[++cnt]=n%10,n/=10);
        reverse(a+1,a+cnt+1);
        int ans=cal(a,cnt,2,5);
        ans=min(ans,cal(a,cnt,5,0));
        ans=min(ans,cal(a,cnt,7,5));
        ans=min(ans,cal(a,cnt,0,0));
        printf("%d\n",ans);
    }
    return 0;
}