#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100010
int n;
ll a[N],l[N],r[N],suml[N],sumr[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",a+i);
    }
    for(int i=1;i<=n;++i)
    {
        l[i]=max(a[i],l[i-1]+1);
        suml[i]=suml[i-1]+l[i]-a[i];
    }
    for(int i=n;i>=1;--i)
    {
        r[i]=max(a[i],r[i+1]+1);
        sumr[i]=sumr[i+1]+r[i]-a[i];
    }
    ll ans=1LL<<60;
    for(int i=1;i<=n;++i)
    {
        ans=min(ans,suml[i-1]+sumr[i+1]+max(max(l[i-1],r[i+1])+1,a[i])-a[i]);
    }
    cout<<ans<<endl;
}